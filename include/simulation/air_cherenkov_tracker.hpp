/*

   calin/simulation/air_cherenkov_tracker.hpp -- Stephen Fegan -- 2016-07-24

   Air shower track visitor to calcilate Cherenkov cone parameters

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

// Units:
// Time, t:      ns
// Height, z:    cm
// Energy, e:    MeV

#include"Eigen/Core"

#include"simulation/atmosphere.hpp"
#include"simulation/tracker.hpp"
#include"simulation/tracker.pb.h"
#include"math/rng.hpp"

namespace calin { namespace simulation { namespace air_cherenkov_tracker {

using calin::simulation::tracker::Event;

// Cherenkov yield in photons per track length per unit bandwidth [eV^-1 cm^-1]
// alpha^2 / r_e / m_e / c^2 -- see PDG 2014, eqn. 32.45
constexpr double YIELD_CONST = 369.81020849958;

struct AirCherenkovTrack
{
  double sin2_thetac;       // Sine^2 of emission angle          [1]
  double sin_thetac;        // Sine of emssion angle             [1]
  double cos_thetac;        // Cosine of emission angle          [1]
  double yield_density;     // Cherenkov photon density          [ph/eV]
  double n;                 // Refracive index                   [1]
  double propagation_delay; // Vertical propagation delay in ct  [cm]
  double gamma_sq;          // Particle gamma squared            [1]

  Eigen::Vector3d x0;       // Position of start of track        [cm]
  double e0;                // Total energy at start of trk      [MeV]
  double t0;                // Time at start of track            [ns]

  Eigen::Vector3d x_mid;    // Position of "middle" of track     [cm]
  double e_mid;             // Total energy at "middle" of trk   [MeV]
  double t_mid;             // Time at "middle" of track         [ns]

  Eigen::Vector3d dx_hat;   // Unit vector from x0 to x1         [1]
  double dx;                // Step length                       [cm]
  double de;                // Change in energy                  [MeV]
  double dt;                // Time step                         [ns]

  // Track from underlying simulator - this could be split by AirCherenkov
  // code if it is too long, i.e. if theta_c changes significantly along
  // the track
  const calin::simulation::tracker::Track* particle_track;
};

class AirCherenkovTrackVisitor
{
public:
  virtual ~AirCherenkovTrackVisitor();
  virtual void visit_event(const Event& event, bool& kill_event);
  virtual void visit_cherenkov_track(const AirCherenkovTrack& cherenkov_track,
    bool& kill_track);
  virtual void leave_event();
};

class AirCherenkovParameterCalculatorTrackVisitor:
  public calin::simulation::tracker::TrackVisitor
{
public:
  AirCherenkovParameterCalculatorTrackVisitor(AirCherenkovTrackVisitor* visitor,
      calin::simulation::atmosphere::Atmosphere* atm,
      const calin::ix::simulation::tracker::AirCherenkovParameterCalculatorTrackVisitorConfig& cfg = default_config(),
      bool adopt_visitor = false, bool adopt_atm = false):
    calin::simulation::tracker::TrackVisitor(),
    visitor_(visitor), adopt_visitor_(adopt_visitor),
    atm_(atm), adopt_atm_(adopt_atm) { if(cfg.enable_forced_cherenkov_angle_mode()) {
      enable_forced_cherenkov_angle_mode_ = true;
      set_forced_cherenkov_angle(cfg.forced_cherenkov_angle()); } }
  virtual ~AirCherenkovParameterCalculatorTrackVisitor();
  void visit_event(const Event& event, bool& kill_event) override;
  void visit_track(const calin::simulation::tracker::Track& track,
    bool& kill_track) override;
  void leave_event() override;
  static calin::ix::simulation::tracker::AirCherenkovParameterCalculatorTrackVisitorConfig default_config();
  void set_forced_cherenkov_angle(double theta_c_deg);
  bool is_forced_cherenkov_angle_mode_enabled() { return enable_forced_cherenkov_angle_mode_; }
private:
  bool enable_forced_cherenkov_angle_mode_ = false;
  double forced_sin2_thetac_ = -1.0;
  AirCherenkovTrackVisitor* visitor_ = nullptr;
  bool adopt_visitor_ = false;
  calin::simulation::atmosphere::Atmosphere* atm_ = nullptr;
  bool adopt_atm_ = false;
};

struct CherenkovPhoton
{
  Eigen::Vector3d x0;       // Position of photon emission              [cm]
  Eigen::Vector3d u0;       // Direction of photon at emission          [cm]
  double t0;                // Time at emission                         [ns]
  double epsilon;           // Photon energy, 0 if none, or -1 for PE   [eV]

  // Air Cherenkov track from underlying simulator
  const AirCherenkovTrack* air_cherenkov_track;
};

class CherenkovPhotonVisitor
{
public:
  virtual ~CherenkovPhotonVisitor();
  virtual void visit_event(const Event& event, bool& kill_event);
  virtual void visit_cherenkov_photon(const CherenkovPhoton& cherenkov_photon);
  virtual void leave_event();
};

class MCCherenkovPhotonGenerator: public AirCherenkovTrackVisitor
{
public:
  MCCherenkovPhotonGenerator(CherenkovPhotonVisitor* visitor,
    double epsilon0 = 1.5, double bandwidth = 3.0, bool do_color_photons = false,
    calin::math::rng::RNG* rng = nullptr,
    bool adopt_visitor = false, bool adopt_rng = false);
  virtual ~MCCherenkovPhotonGenerator();
  virtual void visit_event(const Event& event, bool& kill_event);
  virtual void visit_cherenkov_track(const AirCherenkovTrack& cherenkov_track,
    bool& kill_track);
  virtual void leave_event();
private:
  CherenkovPhotonVisitor* visitor_ = nullptr;
  bool adopt_visitor_ = false;
  double epsilon0_ = 1.5;
  double bandwidth_ = 3.0;
  bool do_color_photons_ = false;
  calin::math::rng::RNG* rng_ = nullptr;
  bool adopt_rng_ = false;
  double dX_emission_ = -1;
};

} } } // namespace calin::simulation::air_cherenkov_tracker
