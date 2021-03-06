//-*-mode:swig;-*-

/*

   calin/simulation/ray_processor.i -- Stephen Fegan -- 2017-01-19

   SWIG interface file for calin.simulation.ray_processor

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

%module (package="calin.simulation") ray_processor

%{
#include "simulation/pe_processor.hpp"
#include "simulation/ray_processor.hpp"
#include "simulation/vso_ray_processor.hpp"
#define SWIG_FILE_WITH_INIT
  %}

%init %{
  import_array();
%}

%include "calin_typemaps.i"
%import "calin_global_definitions.i"

%import "math/ray.i"
%import "math/ray_generator.i"
%import "math/moments_calc.i"

%include "simulation/pe_processor.hpp"
%newobject *::add_processor_and_pe_visitor;
%include "simulation/ray_processor.hpp"
%include "simulation/vso_ray_processor.hpp"
