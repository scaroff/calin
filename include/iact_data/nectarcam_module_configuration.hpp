/*

   calin/iact_data/nectarcam_module_configuration.hpp -- Stephen Fegan -- 2017-12-13

   NectarCAM specific configuration

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

#include <iact_data/nectarcam_module_configuration.pb.h>

namespace calin { namespace iact_data { namespace nectarcam_module_configuration {

#ifndef SWIG

calin::ix::iact_data::nectarcam_module_configuration::NectarCamCameraConfiguration*
decode_nmc_xml_file(const std::string& filename,
  calin::ix::iact_data::nectarcam_module_configuration::NectarCamCameraConfiguration* nccc = nullptr);

#else

calin::ix::iact_data::nectarcam_module_configuration::NectarCamCameraConfiguration*
decode_nmc_xml_file(const std::string& filename);
void decode_nmc_xml_file(const std::string& filename,
  calin::ix::iact_data::nectarcam_module_configuration::NectarCamCameraConfiguration* nccc);

#endif

} } } // namespace calin::iact_data::nectarcam_module_configuration
