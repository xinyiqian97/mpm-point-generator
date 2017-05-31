#ifndef MPM_POINT_GEN_GMSH_H_
#define MPM_POINT_GEN_GMSH_H_

#include <array>
#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "mesh.h"
#include "point.h"

//! \brief Generate Material Points from GMSH file
class GMSH : public Mesh {

 public:
  //! Read vertices in GMSH
  void read_vertices(const std::string& filename);

  //! Read elements in GMSH
  void read_elements(const std::string& filename);

  //! Compute stresses
  void compute_stresses();

  //! call total number of vertices generated
  unsigned nvertices() const { return nvertices_; }

  //! Return a vector of vertices
  std::vector<std::shared_ptr<Point<3>>> vertices() const { return vertices_; }

  //! Return a vector of elements
  std::vector<std::shared_ptr<Point<3>>> elements() const { return elements_; }

  //! Return a vector of stresses
  std::vector<std::array<double, 6>> stress() const { return stress_; }

 private:
  //! Number of vertices
  unsigned nvertices_;

  //! Vector of vertices 
  std::vector<std::shared_ptr<Point<3>>> vertices_;

  //! Vector of elements
  std::vector<std::shared_ptr<Point<3>>> elements_;

  //! Stress vector in Voigt Notation
  //! $\sigma_{xx}$ $\sigma_{yy}$ $\sigma_{zz}$ $\tau_{yz}$ $\tau_{zx}$ $\tau_{xy}$
  std::vector<std::array<double, 6>> stress_;
};

#include "gmsh.tcc"

#endif  // MPM_POINT_GEN_GMSH_H_
