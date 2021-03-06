/*

   calin/iact_data/zfits_data_source.hpp -- Stephen Fegan -- 2016-01-21

   A supplier of single telescope data from CTA ACTL ZFits data files

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

#include <calin_global_definitions.hpp>
#include <calin_global_config.hpp>
#include <io/chained_data_source.hpp>
#include <iact_data/zfits_actl_data_source.hpp>
#include <iact_data/zfits_data_source.pb.h>
#include <iact_data/telescope_data_source.hpp>

#ifdef CALIN_HAVE_CTA_CAMERASTOACTL
#include <CoreMessages.pb.h>
#endif

namespace calin { namespace iact_data { namespace zfits_data_source {

#ifdef CALIN_HAVE_CTA_CAMERASTOACTL

class CTACameraEventDecoder
{
public:
  virtual ~CTACameraEventDecoder();
  virtual bool decode(
    calin::ix::iact_data::telescope_event::TelescopeEvent* event,
    const DataModel::CameraEvent* cta_event) = 0;
  virtual bool decode_run_config(
    calin::ix::iact_data::telescope_run_configuration::
      TelescopeRunConfiguration* run_config,
    const DataModel::CameraRunHeader* cta_run_header,
    const DataModel::CameraEvent* cta_event) = 0;
};

class DecodedACTLDataSource:
  public calin::iact_data::telescope_data_source::TelescopeDataSource
{
public:
  DecodedACTLDataSource(
    calin::iact_data::zfits_actl_data_source::ACTLDataSource* actl_src,
    CTACameraEventDecoder* decoder,
    bool adopt_actl_src = false, bool adopt_decoder = false);

  virtual ~DecodedACTLDataSource();

  calin::ix::iact_data::telescope_event::TelescopeEvent* get_next(
    uint64_t& seq_index_out, google::protobuf::Arena** arena = nullptr) override;

private:
  CTACameraEventDecoder* decoder_;
  bool adopt_decoder_ = false;
  calin::iact_data::zfits_actl_data_source::ACTLDataSource* actl_src_ = nullptr;
  bool adopt_actl_src_ = false;
};

class DecodedConstACTLDataSource:
  public calin::iact_data::telescope_data_source::TelescopeDataSource
{
public:
  DecodedConstACTLDataSource(
    calin::iact_data::zfits_actl_data_source::ConstACTLDataSource* actl_src,
    calin::iact_data::zfits_actl_data_source::ConstACTLDataSink* actl_sink,
    CTACameraEventDecoder* decoder,
    bool adopt_actl_src = false, bool adopt_actl_sink = false, bool adopt_decoder = false);

  DecodedConstACTLDataSource(
    calin::iact_data::zfits_actl_data_source::ConstACTLDataSource* actl_src,
    CTACameraEventDecoder* decoder,
    bool adopt_actl_src = false, bool adopt_decoder = false);

  virtual ~DecodedConstACTLDataSource();

  calin::ix::iact_data::telescope_event::TelescopeEvent* get_next(
    uint64_t& seq_index_out, google::protobuf::Arena** arena = nullptr) override;

private:
  CTACameraEventDecoder* decoder_;
  bool adopt_decoder_ = false;
  calin::iact_data::zfits_actl_data_source::ConstACTLDataSource* actl_src_ = nullptr;
  bool adopt_actl_src_ = false;
  calin::iact_data::zfits_actl_data_source::ConstACTLDataSink* actl_sink_ = nullptr;
  bool adopt_actl_sink_ = false;
};

class DecodedConstACTLDataSourceFactory:
  public calin::iact_data::telescope_data_source::TelescopeDataSourceFactory
{
public:
  DecodedConstACTLDataSourceFactory(
    calin::io::data_source::BidirectionalBufferedDataSourcePump<
      const DataModel::CameraEvent>* pump, CTACameraEventDecoder* decoder,
    bool adopt_pump = false, bool adopt_decoder = false);
  virtual ~DecodedConstACTLDataSourceFactory();
  DecodedConstACTLDataSource* new_data_source() override;

private:
  CTACameraEventDecoder* decoder_;
  bool adopt_decoder_ = false;
  calin::io::data_source::BidirectionalBufferedDataSourcePump<
    const DataModel::CameraEvent>* pump_ = nullptr;
  bool adopt_pump_ = false;
};

class ZFITSSingleFileDataSource:
  public calin::iact_data::telescope_data_source::
    TelescopeRandomAccessDataSourceWithRunConfig
{
public:
  CALIN_TYPEALIAS(config_type,
    calin::ix::iact_data::zfits_data_source::ZFITSDataSourceConfig);

  ZFITSSingleFileDataSource(calin::iact_data::zfits_actl_data_source::
      ZFITSSingleFileACTLDataSource* actl_zfits,
    bool dont_decode_run_configuration,
    CTACameraEventDecoder* decoder, bool adopt_decoder = false,
    bool adopt_actl_zfits = false);

  ZFITSSingleFileDataSource(const std::string& filename,
    CTACameraEventDecoder* decoder, bool adopt_decoder = false,
    const config_type& config = default_config());
  virtual ~ZFITSSingleFileDataSource();

  calin::ix::iact_data::telescope_event::TelescopeEvent* get_next(
    uint64_t& seq_index_out, google::protobuf::Arena** arena = nullptr) override;
  uint64_t size() override;
  void set_next_index(uint64_t next_index) override;

  calin::ix::iact_data::telescope_run_configuration::
    TelescopeRunConfiguration* get_run_configuration() override;

  static config_type default_config() {
    return zfits_actl_data_source::ZFITSSingleFileACTLDataSource::default_config(); }

private:
  CTACameraEventDecoder* decoder_;
  bool adopt_decoder_ = false;
  calin::iact_data::zfits_actl_data_source::
    ZFITSSingleFileACTLDataSource* actl_zfits_ = nullptr;
  bool adopt_actl_zfits_ = false;
  calin::ix::iact_data::telescope_run_configuration::
    TelescopeRunConfiguration* run_config_ = nullptr;
};

class ZFITSDataSource:
  public calin::io::data_source::BasicChainedRandomAccessDataSource<
    calin::iact_data::telescope_data_source::
      TelescopeRandomAccessDataSourceWithRunConfig>
{
public:
  CALIN_TYPEALIAS(config_type,
    calin::ix::iact_data::zfits_data_source::ZFITSDataSourceConfig);

  ZFITSDataSource(const std::string& filename,
    CTACameraEventDecoder* decoder, bool adopt_decoder = false,
    const config_type& config = default_config());
  virtual ~ZFITSDataSource();

  calin::ix::iact_data::telescope_run_configuration::
    TelescopeRunConfiguration* get_run_configuration() override;

  static config_type default_config() {
    return zfits_actl_data_source::ZFITSACTLDataSource::default_config(); }

private:
  CTACameraEventDecoder* decoder_;
  bool adopt_decoder_ = false;
  calin::ix::iact_data::telescope_run_configuration::
    TelescopeRunConfiguration* run_config_ = nullptr;
};

class ZFITSDataSourceOpener:
  public calin::io::data_source::DataSourceOpener<
    calin::iact_data::telescope_data_source::
      TelescopeRandomAccessDataSourceWithRunConfig>
{
public:
  CALIN_TYPEALIAS(data_source_type, calin::iact_data::telescope_data_source::
    TelescopeRandomAccessDataSourceWithRunConfig);
  ZFITSDataSourceOpener(std::string filename, CTACameraEventDecoder* decoder,
    const ZFITSDataSource::config_type& config =
      ZFITSDataSource::default_config());
  virtual ~ZFITSDataSourceOpener();
  unsigned num_sources() override;
  ZFITSSingleFileDataSource* open(unsigned isource) override;
private:
  calin::iact_data::zfits_actl_data_source::
    ZFITSACTLDataSourceOpener* zfits_actl_opener_ = nullptr;
  CTACameraEventDecoder* decoder_ = nullptr;
  ZFITSDataSource::config_type config_;
};

void decode_cdts_data(calin::ix::iact_data::telescope_event::CDTSData* calin_cdts_data,
  const DataModel::AnyArray& cta_array);

void decode_tib_data(calin::ix::iact_data::telescope_event::TIBData* calin_tib_data,
  const DataModel::AnyArray& cta_array);

#endif
} } } // namespace calin::iact_data::zfits_data_source
