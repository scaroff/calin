/*

   calin/iact_data/event_dispatcher.hpp -- Stephen Fegan -- 2016-01-30

   A dispatcher of run and event data

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

#include <string>
#include <vector>

#include <calin_global_definitions.hpp>
#include <calin_global_config.hpp>
#include <iact_data/telescope_data_source.hpp>
#include <iact_data/event_visitor.hpp>
#include <iact_data/nectarcam_data_source.hpp>

namespace calin { namespace iact_data { namespace event_dispatcher {

enum VisitorExecutionMode {
  EXECUTE_PARALLEL_IF_POSSIBLE,
  EXECUTE_SEQUENTIAL,
  EXECUTE_SEQUENTIAL_AND_PARALLEL,
  EXECUTE_SEQUENTIAL_AND_PARALLEL_IF_POSSIBLE,
  EXECUTE_PARALLEL
};

class TelescopeEventDispatcher
{
public:
  TelescopeEventDispatcher();
  ~TelescopeEventDispatcher();

  void add_visitor(
    calin::iact_data::event_visitor::TelescopeEventVisitor* visitor,
    VisitorExecutionMode execution_mode = EXECUTE_PARALLEL_IF_POSSIBLE,
    bool adopt_visitor = false);

  void process_run(calin::iact_data::telescope_data_source::
    TelescopeRandomAccessDataSourceWithRunConfig* src,
    unsigned log_frequency = 0, int nthread = 0);

  void process_run(calin::io::data_source::DataSource<
      calin::ix::iact_data::telescope_event::TelescopeEvent>* src,
    calin::ix::iact_data::
      telescope_run_configuration::TelescopeRunConfiguration* run_config,
    unsigned log_frequency = 0, int nthread = 0,
    bool use_buffered_reader = true);

#ifdef CALIN_HAVE_CTA_CAMERASTOACTL
  void process_nectarcam_zfits_run(const std::string& filename,
    unsigned log_frequency = 0, int nthread = 0,
    const calin::ix::iact_data::nectarcam_data_source::NectarCamCameraEventDecoderConfig& decoder_config =
      calin::iact_data::nectarcam_data_source::NectarCamZFITSDataSource::default_decoder_config(),
    const calin::ix::iact_data::zfits_data_source::ZFITSDataSourceConfig& zfits_config =
      calin::iact_data::nectarcam_data_source::NectarCamZFITSDataSource::default_config());

  void process_nectarcam_zfits_run(const std::string& filename,
    unsigned log_frequency, int nthread,
    const calin::ix::iact_data::zfits_data_source::ZFITSDataSourceConfig& zfits_config,
    const calin::ix::iact_data::nectarcam_data_source::NectarCamCameraEventDecoderConfig& decoder_config =
      calin::iact_data::nectarcam_data_source::NectarCamZFITSDataSource::default_decoder_config()) {
    return process_nectarcam_zfits_run(filename, log_frequency, nthread,
      decoder_config, zfits_config);
  }

  void process_nectarcam_zfits_run(const std::string& filename,
    const calin::ix::iact_data::nectarcam_data_source::NectarCamCameraEventDecoderConfig& decoder_config,
    unsigned log_frequency = 0, int nthread = 0,
    const calin::ix::iact_data::zfits_data_source::ZFITSDataSourceConfig& zfits_config =
      calin::iact_data::nectarcam_data_source::NectarCamZFITSDataSource::default_config()) {
    return process_nectarcam_zfits_run(filename, log_frequency, nthread,
      decoder_config, zfits_config);
  }
#endif

  // These functions allow events to be passed on to the visitors - they
  // are not meant to be called directly as the visiors expect them to be
  // called in a specific order. They are liable to be made private.
  void accept_run_configuration(calin::ix::iact_data::
    telescope_run_configuration::TelescopeRunConfiguration* run_config);
  void accept_event(uint64_t seq_index,
    calin::ix::iact_data::telescope_event::TelescopeEvent* event);
  void accept_all_from_src(
    calin::io::data_source::DataSource<
      calin::ix::iact_data::telescope_event::TelescopeEvent>* src,
    unsigned log_frequency = 0, bool use_buffered_reader = true,
    calin::io::data_source::DataSink<
      calin::ix::iact_data::telescope_event::TelescopeEvent>* sink = nullptr);
  void leave_run();
  void merge_results();

private:
  void do_accept_from_src(
    calin::io::data_source::DataSource<
      calin::ix::iact_data::telescope_event::TelescopeEvent>* src,
    unsigned log_frequency,
    calin::io::data_source::DataSink<
      calin::ix::iact_data::telescope_event::TelescopeEvent>* sink);

  std::vector<calin::iact_data::event_visitor::TelescopeEventVisitor*>
    adopted_visitors_;
  std::vector<std::pair<VisitorExecutionMode,
    calin::iact_data::event_visitor::TelescopeEventVisitor*>> visitors_;
  std::vector<calin::iact_data::event_visitor::TelescopeEventVisitor*>
    wf_visitors_;
};

} } } // namespace calin::iact_data::event_dispatcher
