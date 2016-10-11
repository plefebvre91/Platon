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
    mesh(const mesh&);

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
    
    /**
     * Get the face barycentre
     */
    const point& get_face_barycentre(int face_id) const;
    
  private:
    std::vector<int> p;    
  };

}
#endif
