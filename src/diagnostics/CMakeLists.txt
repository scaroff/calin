# calin/src/io/CMakeLists.txt -- Stephen Fegan
#
# Copyright 2015, Stephen Fegan <sfegan@llr.in2p3.fr>
# LLR, Ecole Polytechnique, CNRS/IN2P3
#
# This file is part of "calin"
#
# "calin" is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License version 2 or later, as published by
# the Free Software Foundation.
#
# "calin" is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --save-temps")

set(CALIN_TARGET_LIBRARY calin_diagnostics)
set(CALIN_SOURCES counter.cpp module.cpp event_number.cpp waveform.cpp
waveform_avx2.cpp waveform_psd.cpp functional.cpp value_capture.cpp delta_t.cpp)

add_library(${CALIN_TARGET_LIBRARY} SHARED ${CALIN_SOURCES})
target_link_libraries(${CALIN_TARGET_LIBRARY} calin_proto_diagnostics
  calin_iact_data calin_math calin_util ${FFTW_LIBRARIES})

install(TARGETS ${CALIN_TARGET_LIBRARY} DESTINATION ${CALIN_LIB_INSTALL_DIR})
