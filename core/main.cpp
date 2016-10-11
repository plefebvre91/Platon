#include "server_ws.hpp"

using namespace std;

typedef SimpleWeb::SocketServer<SimpleWeb::WS> WsServer;

int main() {
  //WebSocket (WS)-server at port 1234 using 4 threads
  WsServer server(1234, 4);
    
  //Example 1: echo WebSocket endpoint
  //  Added debug messages for example use of the callbacks
  //  Test with the following JavaScript:
  //    var ws=new WebSocket("ws://localhost:8080/echo");
  //    ws.onmessage=function(evt){console.log(evt.data);};
  //    ws.send("test");
  auto& echo=server.endpoint["^/echo/?$"];
  
  echo.onmessage=[&server](shared_ptr<WsServer::Connection> connection, shared_ptr<WsServer::Message> message) {
    //WsServer::Message::string() is a convenience function for:
    //stringstream data_ss;
    //data_ss << message->rdbuf();
    //auto message_str = data_ss.str();
    auto message_str=message->string();
    
    cout << "Server: Message received: \"" << message_str << "\" from " << (size_t)connection.get() << endl;
    
    cout << "Server: Sending message \"" << message_str <<  "\" to " << (size_t)connection.get() << endl;
        
    auto send_stream=make_shared<WsServer::SendStream>();
    *send_stream << message_str;
    //server.send is an asynchronous function
    server.send(connection, send_stream, [](const boost::system::error_code& ec){
	if(ec) {
	  cout << "Server: Error sending message. " <<
	    //See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
	    "Error: " << ec << ", error message: " << ec.message() << endl;
	}
      });
  };
    
  echo.onopen=[](shared_ptr<WsServer::Connection> connection) {
    cout << "Server: Opened connection " << (size_t)connection.get() << endl;
  };
    
  //See RFC 6455 7.4.1. for status codes
  echo.onclose=[](shared_ptr<WsServer::Connection> connection, int status, const string& reason) {
    cout << "Server: Closed connection " << (size_t)connection.get() << " with status code " << status << endl;
  };
    
  //See http://www.boost.org/doc/libs/1_55_0/doc/html/boost_asio/reference.html, Error Codes for error code meanings
  echo.onerror=[](shared_ptr<WsServer::Connection> connection, const boost::system::error_code& ec) {
    cout << "Server: Error in connection " << (size_t)connection.get() << ". " << 
    "Error: " << ec << ", error message: " << ec.message() << endl;
  };
    
  thread server_thread([&server](){
      //Start WS-server
      server.start();
    });
    
  //Wait for server to start so that the client can connect
  this_thread::sleep_for(chrono::seconds(4));
    
  server_thread.join();
    
  return 0;
}
