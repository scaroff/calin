/*

   calin/util/file.hpp -- Stephen Fegan -- 2016-01-20

   File utility functions, e.g. test whether files exist, expand filenames etc

   Copyright 2016, Stephen Fegan <sfegan@llr.in2p3.fr>
   LLR, Ecole polytechnique, CNRS/IN2P3, Universite Paris-Saclay

   Based on original, copyright 2006, Stephen Fegan, see notice below

   This file is part of "calin"

   "calin" is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License version 2 or
   later, as published by the Free Software Foundation.

   "calin" is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

*/

/*! \file VSFileUtility.hpp

  Miscellaneous utility file functions

  \author     Stephen Fegan               \n
              UCLA                        \n
              sfegan@astro.ucla.edu       \n

  \version    1.0
  \date       11/11/2006
*/

#pragma once

#include <string>
#include <google/protobuf/message.h>

namespace calin { namespace util { namespace file {

//! Return true if filename exists on the filesystem
bool exists(const std::string& filename);

//! Return true if filename exists and corresponds to a regular file
bool is_file(const std::string& filename);
//! Return true if filename exists and corresponds to a directory
bool is_directory(const std::string& filename);

//! Return true if user has permission to read from filename
bool is_readable(const std::string& filename);
//! Return true if user has permission to write to filename
bool is_writable(const std::string& filename);

//! Return true if filename exists, is regular and writable or
// if file does not exist but its parent directory is writable
bool can_write_file(const std::string& filename);

//! Expand the leading tilde in the filename, replacing it with the home
// directory of the current or specified user
void expand_filename_in_place(std::string& filename);

inline std::string expand_filename(const std::string& filename)
{
  std::string filename_out(filename);
  expand_filename_in_place(filename_out);
  return filename_out;
}

//! Extract the longest positive number from the filename portion
// of a path/file specification. For example,
// "/veritas/data/V12345_v2.cvbf" would return 12345.
unsigned extract_number_from_filename(const std::string& filename);

//! Replace the first occurance of a question mark '?' with an
// unsigned integer. For example passing: filename="?.root" and n=12345
// would result in filename being returned as "12345.root"
void replace_question_with_number(std::string& filename, unsigned n);

void save_protobuf_to_json_file(const std::string& filename,
  const google::protobuf::Message* message);
inline void save_protobuf_to_json_file(const google::protobuf::Message* message,
    const std::string& filename) {
  save_protobuf_to_json_file(filename, message);
}

void load_protobuf_from_json_file(const std::string& filename,
  google::protobuf::Message* message);
inline void load_protobuf_from_json_file(google::protobuf::Message* message,
    const std::string& filename) {
  load_protobuf_from_json_file(filename, message);
}


} } } // namespace calin::util::file
