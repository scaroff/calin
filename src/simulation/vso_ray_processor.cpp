/*

   calin/simulation/vso_ray_processor.cpp -- Stephen Fegan -- 2017-01-16

   VSO ray (weight, scope, ray) processor.

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

#include <math/special.hpp>
#include <simulation/vso_ray_processor.hpp>

using namespace calin::simulation::vso_ray_processor;
using calin::math::special::SQR;

#include <util/log.hpp>
using namespace calin::util::log;

VSOTracedRayVisitor::~VSOTracedRayVisitor()
{
  // nothing to see here
}

void VSOTracedRayVisitor::start_processing()
{
  // nothing to see here
}

void VSOTracedRayVisitor::process_traced_ray(unsigned scope_id,
  const calin::simulation::vs_optics::VSOTraceInfo& trace, double pe_weight)
{
  // nothing to see here
}

void VSOTracedRayVisitor::finish_processing()
{
  // nothing to see here
}

VSOTracedRayVisitor2PEProcessorAdapter::
VSOTracedRayVisitor2PEProcessorAdapter(
    calin::simulation::pe_processor::PEProcessor* visitor, bool adopt_visitor):
  VSOTracedRayVisitor(),
  visitor_(visitor), adopt_visitor_(adopt_visitor)
{
  // nothing to see here
}

VSOTracedRayVisitor2PEProcessorAdapter::
~VSOTracedRayVisitor2PEProcessorAdapter()
{
  if(adopt_visitor_)delete visitor_;
}

void VSOTracedRayVisitor2PEProcessorAdapter::start_processing()
{
  visitor_->start_processing();
}

void VSOTracedRayVisitor2PEProcessorAdapter::
process_traced_ray(unsigned scope_id,
  const calin::simulation::vs_optics::VSOTraceInfo& trace, double pe_weight)
{
  if(not trace.rayHitFocalPlane())return;
  if(trace.pixel != nullptr) {
    visitor_->process_pe(scope_id, trace.pixel->id(),
      trace.fplane_x, trace.fplane_z, trace.fplane_t, pe_weight);
  } else {
    visitor_->process_pe(scope_id, -1,
      trace.fplane_x, trace.fplane_z, trace.fplane_t, pe_weight);
  }
}

void VSOTracedRayVisitor2PEProcessorAdapter::finish_processing()
{
  visitor_->finish_processing();
}

VSOMultiTracedRayVisitor::VSOMultiTracedRayVisitor():
  VSOTracedRayVisitor(), visitors_()
{
  // nothing to see here
}

VSOMultiTracedRayVisitor::~VSOMultiTracedRayVisitor()
{
  for(auto* ivisitor : adopted_visitors_)delete ivisitor;
}

void VSOMultiTracedRayVisitor::start_processing()
{
  for(auto* ivisitor : visitors_)ivisitor->start_processing();
}

void VSOMultiTracedRayVisitor::process_traced_ray(unsigned scope_id,
  const calin::simulation::vs_optics::VSOTraceInfo& trace, double pe_weight)
{
  for(auto* ivisitor : visitors_)
    ivisitor->process_traced_ray(scope_id, trace, pe_weight);
}

void VSOMultiTracedRayVisitor::finish_processing()
{
  for(auto* ivisitor : visitors_)ivisitor->finish_processing();
}

void VSOMultiTracedRayVisitor::add_visitor(VSOTracedRayVisitor* visitor,
  bool adopt_visitor)
{
  visitors_.push_back(visitor);
  if(adopt_visitor)adopted_visitors_.push_back(visitor);
}

VSORayProcessor::VSORayProcessor(calin::simulation::vs_optics::VSOArray* array,
    VSOTracedRayVisitor* visitor, calin::math::rng::RNG* rng,
    bool adopt_array, bool adopt_visitor, bool adopt_rng):
  calin::simulation::ray_processor::RayProcessor(),
  array_(array), adopt_array_(adopt_array),
  visitor_(visitor), adopt_visitor_(adopt_visitor),
  rng_(rng ? rng : new calin::math::rng::RNG(__PRETTY_FUNCTION__)),
  adopt_rng_(rng ? adopt_rng : true),
  ray_tracer_(new calin::simulation::vs_optics::VSORayTracer(array_, rng_)),
  scope_response_(array->numTelescopes())
{
  // nothing to see hee
}

VSORayProcessor::VSORayProcessor(calin::simulation::vs_optics::VSOArray* array,
    calin::simulation::pe_processor::PEProcessor* visitor,
    calin::math::rng::RNG* rng,
    bool adopt_array, bool adopt_visitor, bool adopt_rng):
  calin::simulation::ray_processor::RayProcessor(),
  array_(array), adopt_array_(adopt_array),
  visitor_(new VSOTracedRayVisitor2PEProcessorAdapter(visitor, adopt_visitor)),
  adopt_visitor_(true),
  rng_(rng ? rng : new calin::math::rng::RNG(__PRETTY_FUNCTION__)),
  adopt_rng_(rng ? adopt_rng : true),
  ray_tracer_(new calin::simulation::vs_optics::VSORayTracer(array_, rng_)),
  scope_response_(array->numTelescopes())
{
  // nothing to see here
}

VSORayProcessor::~VSORayProcessor()
{
  if(adopt_array_)delete array_;
  if(adopt_visitor_)delete visitor_;
  if(adopt_rng_)delete rng_;
}

std::vector<calin::simulation::ray_processor::RayProcessorDetectorSphere>
VSORayProcessor::detector_spheres()
{
  std::vector<calin::simulation::ray_processor::RayProcessorDetectorSphere> s;
  for(unsigned iscope=0; iscope<array_->numTelescopes(); iscope++)
  {
    auto* scope = array_->telescope(iscope);
    Eigen::Vector3d sphere_center = scope->reflectorIPCenter();
    scope->reflectorToGlobal_pos(sphere_center);
    s.emplace_back(sphere_center, SQR(0.5*scope->reflectorIP()));
  }
  return s;
}

void VSORayProcessor::start_processing()
{
  visitor_->start_processing();
}

void VSORayProcessor::process_ray(unsigned scope_id,
  const calin::math::ray::Ray& ray, double pe_weight)
{
  double z0 = ray.position().z();
  double w = ray.direction().z();
  auto* scope = array_->telescope(scope_id);

  calin::math::ray::Ray ray_copy(ray);
  vs_optics::VSOTraceInfo trace_info;
  ray_tracer_->trace(ray_copy, trace_info, scope);

  const ScopeResponse& scope_response { scope_response_[scope_id] };
  if(scope_response.has_effective_bandwidth)
    pe_weight *= scope_response.effective_bandwidth.bandwidth(z0, std::fabs(w));
  else
    pe_weight *= scope_response.detector_bandwidth;

  if(trace_info.rayHitFocalPlane())
    pe_weight *= scope_response.cone_efficiency.y(trace_info.fplane_uy);

#if 0
  static unsigned counter = 0;
  if(counter++<10) {
    LOG(INFO) << trace_info.status << ' ' << trace_info.mirror_hexid << ' '
      << trace_info.reflec_x << ' ' << trace_info.reflec_z << ' '
      << trace_info.reflec_dx << ' ' << trace_info.reflec_dz;
  }
#endif

  visitor_->process_traced_ray(scope_id, trace_info, pe_weight);
}

void VSORayProcessor::finish_processing()
{
  visitor_->finish_processing();
}

void VSORayProcessor::add_fp_hit_trace_visitor(VSOTracedRayVisitor* visitor,
  bool adopt_visitor)
{
  if(multi_visitor_ == nullptr) {
    multi_visitor_ = new VSOMultiTracedRayVisitor;
    multi_visitor_->add_visitor(visitor_, adopt_visitor_);
    visitor_ = multi_visitor_;
    adopt_visitor_ = true;
  }
  multi_visitor_->add_visitor(visitor, adopt_visitor);
}

void VSORayProcessor::add_pe_visitor(
  calin::simulation::pe_processor::PEProcessor* visitor, bool adopt_visitor)
{
  add_fp_hit_trace_visitor(new VSOTracedRayVisitor2PEProcessorAdapter(visitor,
    adopt_visitor), true);
}

void VSORayProcessor::set_all_detection_efficiencies(
  const calin::simulation::detector_efficiency::DetectionEfficiency& detector_efficiency,
  const calin::simulation::detector_efficiency::AtmosphericAbsorption& atmospheric_absorption,
  double w0,
  const calin::simulation::detector_efficiency::AngularEfficiency& cone_efficiency)
{
  for(unsigned iscope=0; iscope<scope_response_.size(); iscope++)
    set_scope_detection_efficiencies(iscope, detector_efficiency,
      atmospheric_absorption, w0, cone_efficiency);
}

void VSORayProcessor::set_all_detector_response_without_atmospheric_absorption(
  const calin::simulation::detector_efficiency::DetectionEfficiency& detector_efficiency)
{
  for(unsigned iscope=0; iscope<scope_response_.size(); iscope++)
    set_scope_detector_response_without_atmospheric_absorption(iscope, detector_efficiency);
}

void VSORayProcessor::set_all_detector_and_atmosphere_response(
  const calin::simulation::detector_efficiency::DetectionEfficiency& detector_efficiency,
  const calin::simulation::detector_efficiency::AtmosphericAbsorption& atmospheric_absorption,
  double w0)
{
  for(unsigned iscope=0; iscope<scope_response_.size(); iscope++)
    set_scope_detector_and_atmosphere_response(iscope, detector_efficiency,
      atmospheric_absorption, w0);
}

void VSORayProcessor::set_all_cone_angular_response(
  const calin::simulation::detector_efficiency::AngularEfficiency& cone_efficiency)
{
  for(unsigned iscope=0; iscope<scope_response_.size(); iscope++)
    set_scope_cone_angular_response(iscope, cone_efficiency);
}

void VSORayProcessor::set_scope_detection_efficiencies(unsigned iscope,
  const calin::simulation::detector_efficiency::DetectionEfficiency& detector_efficiency,
  const calin::simulation::detector_efficiency::AtmosphericAbsorption& atmospheric_absorption,
  double w0,
  const calin::simulation::detector_efficiency::AngularEfficiency& cone_efficiency)
{
  if(iscope >= scope_response_.size())
    throw std::out_of_range("Scope not defined: " + std::to_string(iscope));

  auto* scope = array_->telescope(iscope);
  scope_response_[iscope].has_effective_bandwidth = true;
  scope_response_[iscope].effective_bandwidth =
    atmospheric_absorption.integrateBandwidth(
      scope->position().z(), std::fabs(w0), detector_efficiency);
  scope_response_[iscope].detector_bandwidth = detector_efficiency.integrate();
  scope_response_[iscope].cone_efficiency = cone_efficiency;
}

void VSORayProcessor::
set_scope_detector_response_without_atmospheric_absorption(unsigned iscope,
  const calin::simulation::detector_efficiency::DetectionEfficiency& detector_efficiency)
{
  if(iscope >= scope_response_.size())
    throw std::out_of_range("Scope not defined: " + std::to_string(iscope));

  scope_response_[iscope].has_effective_bandwidth = false;
  scope_response_[iscope].effective_bandwidth =
    calin::simulation::detector_efficiency::ACTEffectiveBandwidth(1.0);
  scope_response_[iscope].detector_bandwidth = detector_efficiency.integrate();
}

void VSORayProcessor::
set_scope_detector_and_atmosphere_response(unsigned iscope,
  const calin::simulation::detector_efficiency::DetectionEfficiency& detector_efficiency,
  const calin::simulation::detector_efficiency::AtmosphericAbsorption& atmospheric_absorption,
  double w0)
{
  if(iscope >= scope_response_.size())
    throw std::out_of_range("Scope not defined: " + std::to_string(iscope));

  auto* scope = array_->telescope(iscope);
  scope_response_[iscope].has_effective_bandwidth = true;
  scope_response_[iscope].effective_bandwidth =
    atmospheric_absorption.integrateBandwidth(
      scope->position().z(), std::fabs(w0), detector_efficiency);
  scope_response_[iscope].detector_bandwidth = detector_efficiency.integrate();
}

void VSORayProcessor::set_scope_cone_angular_response(unsigned iscope,
  const calin::simulation::detector_efficiency::AngularEfficiency& cone_efficiency)
{
  if(iscope >= scope_response_.size())
    throw std::out_of_range("Scope not defined: " + std::to_string(iscope));

  scope_response_[iscope].cone_efficiency = cone_efficiency;
}
