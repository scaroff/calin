/*

   calin/math/vector3d_util.cpp -- Stephen Fegan -- 2016-10-23

   Utility functions for Eigen::Vector3d

   Copyright 2016, Stephen Fegan <sfegan@llr.in2p3.fr>
   LLR, Ecole polytechnique, CNRS/IN2P3, Universite Paris-Saclay

   This file is part of "calin"

   "calin" is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License version 2 or
   later, as published by the Free Software Foundation.

   "calin" is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

*/

#include <math/vector3d_util.hpp>

calin::ix::common_types::Vector3D* calin::math::vector3d_util::
dump_as_proto(const Eigen::Vector3d& v, calin::ix::common_types::Vector3D* d)
{
  if(d == nullptr)d = new calin::ix::common_types::Vector3D;
  d->set_x(v.x());
  d->set_y(v.y());
  d->set_z(v.z());
  return d;
}

void calin::math::vector3d_util::
set_from_proto(Eigen::Vector3d& v, const calin::ix::common_types::Vector3D& d)
{
  v.x() = d.x();
  v.y() = d.y();
  v.z() = d.z();
}

calin::ix::common_types::Vector3D* calin::math::vector3d_util::
dump_scaled_as_proto(const Eigen::Vector3d& v,
  double scale, calin::ix::common_types::Vector3D* d)
{
  if(d == nullptr)d = new calin::ix::common_types::Vector3D;
  d->set_x(v.x()*scale);
  d->set_y(v.y()*scale);
  d->set_z(v.z()*scale);
  return d;
}

void calin::math::vector3d_util::set_from_scaled_proto(Eigen::Vector3d& v,
  const calin::ix::common_types::Vector3D& d, double scale)
{
  v.x() = d.x()*scale;
  v.y() = d.y()*scale;
  v.z() = d.z()*scale;
}
