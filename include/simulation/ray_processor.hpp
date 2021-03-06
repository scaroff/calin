/*

   calin/simulation/ray_processor.hpp -- Stephen Fegan -- 2017-01-16

   Multi-purpose ray processor.

   Copyright 2017, Stephen Fegan <sfegan@llr.in2p3.fr>
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

#include <vector>
#include <math/ray.hpp>
#include <math/ray_generator.hpp>
#include <simulation/pe_processor.hpp>

namespace calin { namespace simulation { namespace ray_processor {

struct RayProcessorDetectorSphere
{
  RayProcessorDetectorSphere(const Eigen::Vector3d& r0_, double radius_sq_):
      r0(r0_), radius_sq(radius_sq_) { /* nothing to see here */ }
  Eigen::Vector3d r0;                        // Center of detector sphere [cm]
  double radius_sq;                          // Squared radius of sphere  [cm^2]
};

class RayProcessor
{
public:
  virtual ~RayProcessor();
  virtual std::vector<RayProcessorDetectorSphere> detector_spheres();
  virtual void start_processing();
  virtual void process_ray(unsigned scope_id, const calin::math::ray::Ray& ray,
    double pe_weight);
  virtual void finish_processing();
  unsigned process_all_from_ray_generator(
    calin::math::ray_generator::RayGenerator* gen, unsigned scope_id = 0);
};

class FederatedPEProcessor: public calin::simulation::pe_processor::PEProcessor
{
public:
  FederatedPEProcessor(calin::simulation::pe_processor::PEProcessor* pe_processor,
    unsigned scope_id_base);
  virtual ~FederatedPEProcessor();
  void start_processing() override;
  void process_pe(unsigned scope_id, int pixel_id,
    double x, double y, double t0, double pe_weight) override;
  void finish_processing() override;
protected:
  unsigned scope_id_base_ = 0;
  calin::simulation::pe_processor::PEProcessor* pe_processor_ = nullptr;
};

class FederatedRayProcessor: public RayProcessor
{
public:
  FederatedRayProcessor();
  virtual ~FederatedRayProcessor();
  std::vector<RayProcessorDetectorSphere> detector_spheres() override;
  void start_processing() override;
  void process_ray(unsigned scope_id, const calin::math::ray::Ray& ray,
    double pe_weight) override;
  void finish_processing() override;
  void add_processor(RayProcessor* processor, bool adopt_processor);
  FederatedPEProcessor* add_processor_and_pe_visitor(
    RayProcessor* ray_processor,
    calin::simulation::pe_processor::PEProcessor* pe_processor,
    bool adopt_ray_processor);
protected:
  std::vector<RayProcessor*> processors_;
  std::vector<unsigned> nsphere_;
  std::vector<RayProcessor*> adopted_processors_;
};

} } } // namespace calin::simulation::ray_processor
