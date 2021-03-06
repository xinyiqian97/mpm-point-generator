#ifndef MPM_POINT_GEN_GMSH_H_
#define MPM_POINT_GEN_GMSH_H_

#include <cmath>

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <utility>
#include <vector>

#include <eigen3/Eigen/Dense>

#include "element.h"
#include "material_points.h"
#include "mesh.h"

//! \brief Generate Material Points from GMSH file
template <unsigned Tdim, unsigned Tvertices>
class GMSH : public Mesh<Tdim, Tvertices> {

 public:
  //! Read GMSH file
  void read_mesh(const std::string& filename);

  //! Read keyword in GMSH
  void read_keyword(std::ifstream& file, const std::string& keyword);

  //! Read vertices in GMSH
  void read_vertices(std::ifstream& file);

  //! Read elements in GMSH
  void read_elements(std::ifstream& file);

  //! Store element id and vertices coordinates as map
  void store_element_vertices();

  //! Compute material points from element coordinate map
  void generate_material_points(unsigned ngauss_points);

 private:
  //! Total number of vertices
  using Mesh<Tdim, Tvertices>::nvertices_;

  //! Total number of material points generated
  using Mesh<Tdim, Tvertices>::npoints_;

  //! Map to store id and vertices coordinates
  using Mesh<Tdim, Tvertices>::vertices_;

  //! Map to store element id and vertices id
  using Mesh<Tdim, Tvertices>::elements_;

  //! Vector of material points
  using Mesh<Tdim, Tvertices>::materialpoints_;
};

#include "gmsh.tcc"

#endif  // MPM_POINT_GEN_GMSH_H_
