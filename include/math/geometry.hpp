/*

   calin/math/geometry.hpp -- Stephen Fegan -- 2016-11-12

   Misc geometrical functions :
   - Box intersections
   - Rotation matrix for angles

   Copyright 2016, Stephen Fegan <sfegan@llr.in2p3.fr>
   LLR, Ecole Polytechnique, CNRS/IN2P3

   This file is part of "calin"

   "calin" is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License version 2 or
   later, as published by the Free Software Foundation.

   "calin" is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

*/

#pragma once

#include <algorithm>
#include <Eigen/Dense>

namespace calin { namespace math { namespace geometry {

inline bool box_has_future_intersection(double& tmin, double& tmax,
  const Eigen::Vector3d& min_corner, const Eigen::Vector3d& max_corner,
  const Eigen::Vector3d& pos, const Eigen::Vector3d& dir)
{
  // See: https://tavianator.com/fast-branchless-raybounding-box-intersections/
  // and: https://tavianator.com/fast-branchless-raybounding-box-intersections-part-2-nans/

  // Normalized direction vector
  const double vx = 1.0 / dir.x();
  const double vy = 1.0 / dir.y();
  const double vz = 1.0 / dir.z();

  Eigen::Vector3d min_rel = min_corner - pos;
  Eigen::Vector3d max_rel = max_corner - pos;

  const double tx1 = min_rel.x() * vx;
  const double tx2 = max_rel.x() * vx;
  tmin = std::min(tx1, tx2);
  tmax = std::max(tx1, tx2);

  const double ty1 = min_rel.y() * vy;
  const double ty2 = max_rel.y() * vy;
  tmin = std::max(tmin, std::min(std::min(ty1, ty2), tmax));
  tmax = std::min(tmax, std::max(std::max(ty1, ty2), tmin));

  const double tz1 = min_rel.z() * vz;
  const double tz2 = max_rel.z() * vz;
  tmin = std::max(tmin, std::min(std::min(tz1, tz2), tmax));
  tmax = std::min(tmax, std::max(std::max(tz1, tz2), tmin));

  return tmax > std::max(tmin, 0.0);
}

inline bool box_has_future_intersection(
  const Eigen::Vector3d& min_corner, const Eigen::Vector3d& max_corner,
  const Eigen::Vector3d& pos, const Eigen::Vector3d& dir)
{
  double tmin;
  double tmax;
  return box_has_future_intersection(tmin,tmax,min_corner,max_corner,pos,dir);
}

inline void rotation_theta_phi(Eigen::Matrix3d& m,
  const double ct, const double st, const double cp, const double sp)
{
  m << ct*cp, -sp, st*cp,
       ct*sp,  cp, st*sp,
         -sp,   0,    ct;
}

inline void rotation_theta_phi(Eigen::Matrix3d& m, double theta, double phi)
{
  const double ct = std::cos(theta);
  const double st = std::sin(theta);
  const double cp = std::cos(phi);
  const double sp = std::sin(phi);
  return rotation_theta_phi(m, ct, st, cp, sp);
}

inline void rotation_z_to_xyz(Eigen::Matrix3d& m,
  const double x, const double y, const double z)
{
  double st = std::sqrt(x*x+y*y);
  if(st == 0.0) {
    if(z>=0) {
      m.setIdentity();
    } else {
      m << -1,  0,  0,
            0,  1,  0,
            0,  0, -1;
    }
  } else {
    double sp = y/st;
    double cp = x/st;
    m << z*cp, -sp, x,
         z*sp,  cp, y,
          -st,   0, z;
  }
}

inline void rotation_z_to_vec(Eigen::Matrix3d& m, const Eigen::Vector3d& v)
{
  return rotation_z_to_xyz(m, v.x(), v.y(), v.z());
}

#ifndef SWIG

// -----------------------------------------------------------------------------
// Skip in SWIG as templates map above functions in equivalents of these
// -----------------------------------------------------------------------------

inline Eigen::Matrix3d rotation_theta_phi(
  const double ct, const double st, const double cp, const double sp)
{
  Eigen::Matrix3d m;
  rotation_theta_phi(m, ct, st, cp, sp);
  return m;
}

inline Eigen::Matrix3d rotation_theta_phi(double theta, double phi)
{
  Eigen::Matrix3d m;
  rotation_theta_phi(m, theta, phi);
  return m;
}

inline Eigen::Matrix3d rotation_z_to_xyz(
  const double x, const double y, const double z)
{
  Eigen::Matrix3d m;
  rotation_z_to_xyz(m, x, y, z);
  return m;
}

inline Eigen::Matrix3d rotation_z_to_vec(const Eigen::Vector3d v)
{
  Eigen::Matrix3d m;
  rotation_z_to_vec(m, v);
  return m;
}
#endif

} } } // namespace calin::math::geometry
