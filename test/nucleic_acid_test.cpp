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
  NucleicAcid s{"test", "AaAaCcCcGgGgTtTt------ACGTRYKMSWBDHVN-nvhdbwsmkyrtgca------tTtTgGgGcCcCaAaA"};  // NOLINT
  EXPECT_EQ("AAAACCCCGGGGTTTTAAAAAAACGTATGCCACATGAAAGTACACCGTATGCAAAAAAATTTTGGGGCCCCAAAA", s.Inflate());  // NOLINT
  EXPECT_EQ("TATGCCACATGAAAGTACACCGTAT", s.Inflate(25, 25));
  EXPECT_EQ("TGAAAGT", s.Inflate(34, 7));
  EXPECT_EQ("", s.Inflate(75, 42));
  EXPECT_EQ("C", s.Inflate(29, 1));
  EXPECT_EQ("G", s.Inflate(64, 1));
  EXPECT_EQ("CCAAAA", s.Inflate(69));
}

TEST(BiosoupNucleicAcidTest, ReverseAndComplement) {
  NucleicAcid s{"test", "ACGTACTGAGCTAGTCATCGATGCCAGTCATGCGATCGTACTAGCTGAGACTGATCGCATGCTAGTACGTCA"};  // NOLINT
  NucleicAcid c{s};
  c.ReverseAndComplement();
  EXPECT_EQ("TGACGTACTAGCATGCGATCAGTCTCAGCTAGTACGATCGCATGACTGGCATCGATGACTAGCTCAGTACGT", c.Inflate());  // NOLINT
  c.ReverseAndComplement();
  EXPECT_EQ(c.deflated_data, s.deflated_data);
}

}  // namespace test
}  // namespace biosoup
