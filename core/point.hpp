#ifndef PLATON_POINT_HPP
#define PLATON_POINT_HPP

namespace platon
{
  class point
  {
  public:
    /**
     * Constructor
     */
    point();

    /**
     * Copy constructor
     */
    point(const point&);

    /**
     * Constructor overload
     */
    point(double x, double y);
    
    /**
     * Normalize
     */
    void normalize();
    
    /**
     * Destructor
     */
    ~point();

    
    
  private:
    double x;
    double y;
  };

}
#endif
