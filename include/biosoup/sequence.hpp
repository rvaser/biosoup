// Copyright (c) 2020 Robert Vaser

#ifndef BIOSOUP_SEQUENCE_HPP_
#define BIOSOUP_SEQUENCE_HPP_

#include <algorithm>
#include <atomic>
#include <cstdint>
#include <string>

namespace biosoup {

struct Sequence {
 public:
  Sequence() = default;

  Sequence(const std::string& name, const std::string& data)
      : id(num_objects++), name(name), data(data) {}
  Sequence(const char* name, std::uint32_t name_length,
           const char* data, std::uint32_t data_length)
      : id(num_objects++), name(name, name_length), data(data, data_length) {}

  Sequence(const Sequence&) = default;
  Sequence& operator=(const Sequence&) = default;

  Sequence(Sequence&&) = default;
  Sequence& operator=(Sequence&&) = default;

  ~Sequence() = default;

  static std::atomic<std::uint64_t> num_objects;  // (optional) initialize to 0

  std::uint64_t id;
  std::string name;
  std::string data;
};

}  // namespace biosoup

#endif  // BIOSOUP_SEQUENCE_HPP_
