// Copyright (c) 2020 Robert Vaser

#include "biosoup/nucleic_acid.hpp"

#include <iostream>

#include "gtest/gtest.h"

std::atomic<std::uint32_t> biosoup::NucleicAcid::num_objects{0};

namespace biosoup {
namespace test {

TEST(BiosoupNucleicAcidTest, NucleotideError) {
  try {
    NucleicAcid s{"test", "EFIJLOPQUXZ"};
  } catch (std::invalid_argument& exception) {
    EXPECT_STREQ(
        exception.what(),
        "[biosoup::NucleicAcid::NucleicAcid] error: not a nucleotide");
  }
}

TEST(BiosoupNucleicAcidTest, Inflate) {
  NucleicAcid s{"test", "ACGTRYKMSWBDHVN-nvhdbwsmkyrtgca"};
  EXPECT_EQ("ACGTATGCCACATGAAAGTACACCGTATGCA", s.Inflate());
  EXPECT_EQ("TGAAAGT", s.Inflate(12, 7));
  EXPECT_EQ("", s.Inflate(42, 42));
}

}  // namespace test
}  // namespace biosoup
