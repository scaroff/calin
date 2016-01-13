/*

   calin/io/nectarcam_data_source.hpp -- Stephen Fegan -- 2016-01-11

   A supplier of single telescope data from NectarCam DAQ data files

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

#pragma once

#include <string>

#include <calin_global_definitions.hpp>
#include <calin_global_config.hpp>
#include <io/telescope_data_source.hpp>
#include <io/nectarcam_data_source.pb.h>

// Forward declaration of ACTL::IO::ProtobufIFits
#ifdef CALIN_HAVE_CTA_CAMERASTOACTL
namespace ACTL { namespace IO {
  class ProtobufIFits;
} } // namespace ACTL::IO
#endif // #ifdef CALIN_HAVE_CTA_CAMERASTOACTL

namespace calin { namespace io { namespace nectarcam_data_source {

#ifdef CALIN_HAVE_CTA_CAMERASTOACTL

class NectarCamZFITSDataSource:
  public calin::io::telescope_data_source::TelescopeDataSource
{
public:
  CALIN_TYPEALIAS(config_type, calin::ix::io::nectarcam_data_source::NectarCamZFITSDataSourceConfig);

  NectarCamZFITSDataSource(const std::string& filename);
  virtual ~NectarCamZFITSDataSource();
  void set_config(const config_type& config) { config_.CopyFrom(config); }
  const config_type& config() const { return config_; }
  config_type* config() { return &config_; }

  calin::ix::iact::telescope_event::TelescopeEvent* getNextEvent() override;
private:
  std::string filename_;
  ACTL::IO::ProtobufIFits* zfits_ = nullptr;
  config_type config_;
  unsigned next_event_index_ = 0;
};

#endif // #ifdef CALIN_HAVE_CTA_CAMERASTOACTL

} } } // namespace calin::io::nectarcam_data_source
