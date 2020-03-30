// Copyright (c) 2020 Robert Vaser

#include "biosoup/progress_bar.hpp"

#include <iostream>

#include "gtest/gtest.h"

namespace {

TEST(BiosoupProgressBarTest, Operator) {
  biosoup::ProgressBar b{8, 8};
  EXPECT_EQ(b(), "#.......");
  EXPECT_EQ(b(), "##......");
  EXPECT_EQ(b(), "###.....");
  EXPECT_EQ(b(), "####....");
  EXPECT_EQ(b(), "#####...");
  EXPECT_EQ(b(), "######..");
  EXPECT_EQ(b(), "#######.");
  EXPECT_EQ(b(), "########");
  b = {8, 9};
  EXPECT_EQ(b(), "#.......");
  b = {8, 7};
  EXPECT_EQ(b(), ".......");
  EXPECT_EQ(b(), "#......");
  EXPECT_EQ(b(), "##.....");
  EXPECT_EQ(b(), "###....");
  EXPECT_EQ(b(), "####...");
  EXPECT_EQ(b(), "#####..");
  EXPECT_EQ(b(), "######.");
  EXPECT_EQ(b(), "#######");
  b = {8, 4};
  EXPECT_EQ(b(), "....");
  EXPECT_EQ(b(), "#...");
  EXPECT_EQ(b(), "#...");
  EXPECT_EQ(b(), "##..");
  EXPECT_EQ(b(), "##..");
  EXPECT_EQ(b(), "###.");
  EXPECT_EQ(b(), "###.");
  EXPECT_EQ(b(), "####");
  b = {8, 2};
  EXPECT_EQ(b(), "..");
  EXPECT_EQ(b(), "..");
  EXPECT_EQ(b(), "..");
  EXPECT_EQ(b(), "#.");
  EXPECT_EQ(b(), "#.");
  EXPECT_EQ(b(), "#.");
  EXPECT_EQ(b(), "#.");
  EXPECT_EQ(b(), "##");
  b = {8, 1};
  EXPECT_EQ(b(), ".");
  EXPECT_EQ(b(), ".");
  EXPECT_EQ(b(), ".");
  EXPECT_EQ(b(), ".");
  EXPECT_EQ(b(), ".");
  EXPECT_EQ(b(), ".");
  EXPECT_EQ(b(), ".");
  EXPECT_EQ(b(), "#");
  b = {8, 0};
  EXPECT_EQ(b(), ".");
}

}  // namespace