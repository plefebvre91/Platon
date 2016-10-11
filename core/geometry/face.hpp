#ifndef PLATON_FACE_HPP
#define PLATON_FACE_HPP

namespace platon
{
  class face
  {
  public:
    /**
     * Constructor
     */
    face();

    /**
     * Copy constructor
     */
    face(cont face&);

    /**
     * Destructor
     */
    ~face();

    /**
     * Compute the barycentre
     */
    void barycentre() const;

  private:
    std::vector<double> p;    
    point barycentre;
  };

}
#endif
