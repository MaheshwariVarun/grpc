/*
 *
 * Copyright 2014, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef NET_GRPC_COMPILER_RUBY_GENERATOR_HELPERS_INL_H_
#define NET_GRPC_COMPILER_RUBY_GENERATOR_HELPERS_INL_H_

#include <string>

#include <google/protobuf/descriptor.h>
#include "src/compiler/ruby_generator_string-inl.h"

namespace grpc_ruby_generator {

inline bool ServicesFilename(const google::protobuf::FileDescriptor* file,
                             std::string* file_name_or_error) {
  // Get output file name.
  static const unsigned proto_suffix_length = 6;  // length of ".proto"
  if (file->name().size() > proto_suffix_length &&
      file->name().find_last_of(".proto") == file->name().size() - 1) {
    *file_name_or_error =
        file->name().substr(0, file->name().size() - proto_suffix_length) +
        "_services.rb";
    return true;
  } else {
    *file_name_or_error = "Invalid proto file name:  must end with .proto";
    return false;
  }
}

inline std::string MessagesRequireName(
    const google::protobuf::FileDescriptor* file) {
  return Replace(file->name(), ".proto", "");
}

}  // namespace grpc_ruby_generator

#endif  // NET_GRPC_COMPILER_RUBY_GENERATOR_HELPERS_INL_H_
