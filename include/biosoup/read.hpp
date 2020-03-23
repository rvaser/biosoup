// Copyright (c) 2020 Robert Vaser

#ifndef BIOSOUP_READ_HPP_
#define BIOSOUP_READ_HPP_

#include <string>

#include "biosoup/sequence.hpp"

namespace biosoup {

struct Read : public Sequence {
 public:
  Read() = default;

  Read(const std::string& name, const std::string& data,
       const std::string& quality)
      : Sequence(name, data), quality(quality) {}
  Read(const char* name, std::uint32_t name_length,
       const char* data, std::uint32_t data_length,
       const char* quality, std::uint32_t quality_length)
      : Sequence(name, name_length, data, data_length),
        quality(quality, quality_length) {}

  Read(const Read&) = default;
  Read& operator=(const Read&) = default;

  Read(Read&&) = default;
  Read& operator=(Read&&) = default;

  ~Read() = default;

  void ReverseAndComplement(void) {
    for (auto& it : data) {
      switch (it) {
        case 'A': case 'a': it = 'T'; break;
        case 'C': case 'c': it = 'G'; break;
        case 'G': case 'g': it = 'C'; break;
        case 'T': case 't': case 'U': it = 'A'; break;
        case 'R': it = 'Y'; break;  // A || G
        case 'Y': it = 'R'; break;  // C || T (U)
        case 'K': it = 'M'; break;  // G || T (U)
        case 'M': it = 'K'; break;  // A || C
        case 'S': break;  // C || G
        case 'W': break;  // A || T (U)
        case 'B': it = 'V'; break;  // !A
        case 'D': it = 'H'; break;  // !C
        case 'H': it = 'D'; break;  // !G
        case 'V': it = 'B'; break;  // !T (!U)
        default: break;  // N
      }
    }
    std::reverse(data.begin(), data.end());
    std::reverse(quality.begin(), quality.end());
  }

  std::string quality;
};

}  // namespace biosoup

#endif  // BIOSOUP_READ_HPP_
