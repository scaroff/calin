/*

   calin/util/timestamp.hpp -- Stephen Fegan -- 2017-10-29

   Simple (non-precision) timestamp class

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

#include <sys/time.h>
#include <time.h>

#include <util/timestamp.hpp>

using namespace calin::util::timestamp;

std::string Timestamp::as_string() const
{
  time_t ts = time_t(sec());
  struct tm the_tm;
  localtime_r(&ts, &the_tm);
  char buffer[] = "1999-12-31T23:59:59";
  strftime(buffer, sizeof(buffer)-1, "%Y-%m-%dT%H:%M:%S", &the_tm);
  std::string str(buffer);
  uint32_t ms = nsec()/1000000;
  if(ms<10) { str += ".00"; }
  else if(ms<100) { str += ".0"; }
  else { str += "."; }
  str += std::to_string(ms);
  return str;
}

calin::ix::util::timestamp::Timestamp*
Timestamp::as_proto(calin::ix::util::timestamp::Timestamp* x) const
{
  if(x == nullptr)x = new calin::ix::util::timestamp::Timestamp;
  x->set_unix_sec(sec());
  x->set_unix_nsec(nsec());
  x->set_printable(as_string());
  return x;
}

Timestamp Timestamp::now()
{
  struct timespec tp;
  clock_gettime(CLOCK_REALTIME, &tp);
  return { uint64_t(tp.tv_sec), uint32_t(tp.tv_nsec) };
}

double Timestamp::seconds_since(const Timestamp& then) const
{
  double dt { sec()>=then.sec()?double(sec()-then.sec()):-double(then.sec()-sec()) };
  dt += (nsec()>=then.nsec()?double(nsec()-then.nsec()):-double(then.nsec()-nsec()))*1e-9;
  return dt;
}
