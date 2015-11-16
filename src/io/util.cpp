/* 

   calin/io/until.cpp -- Stephen Fegan -- 2015-11-13

   Various IO related utility functions

   Copyright 2015, Stephen Fegan <sfegan@llr.in2p3.fr>
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

#include <sstream>

#include <io/util.hpp>

// Copyright 2008 Evan Teran and others under the CC license
// From: http://stackoverflow.com/questions/236129/split-a-string-in-c

std::vector<std::string>& calin::io::util::
split(const std::string &s, char delim, std::vector<std::string> &elems)
{
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) { elems.push_back(item); }
  return elems;
}

std::vector<std::string> calin::io::util::
split(const std::string &s, char delim)
{
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
}