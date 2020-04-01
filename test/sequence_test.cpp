// Copyright (c) 2020 Robert Vaser

#include "biosoup/sequence.hpp"

#include "gtest/gtest.h"

std::atomic<std::uint64_t> biosoup::Sequence::num_objects{0};

namespace biosoup {
namespace test {

TEST(BiosoupSequenceTest, ReverseAndComplement) {
  Sequence s{"Test", "ACGTURYKMSWBDHVN", "0123456789:;<=>?"};
  s.ReverseAndComplement();
  EXPECT_EQ(s.id, 0);
  EXPECT_EQ(s.data, "NBDHVWSKMRYAACGT");
  EXPECT_EQ(s.quality, "?>=<;:9876543210");
}

}  // namespace test
}  // namespace biosoup
