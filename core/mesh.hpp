#ifndef PLATON_MESH_HPP
#define PLATON_MESH_HPP

namespace platon
{
  class mesh
  {
  public:
    /**
     * Constructor
     */
    mesh();

    /**
     * Copy constructor
     */
    mesh(cont mesh&);

    /**
     * Destructor
     */
    ~mesh();

    /**
     * Add a new face
     */
    void add_face(const face&);

    /**
     * Remove a face
     */
    void remove_face(int face_id);


  private:
    std::vector<double> p;    
  };

}
#endif
