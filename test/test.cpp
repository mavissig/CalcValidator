//
// Created by mavissig on 26.07.23.
//

#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "../controller/controller.h"
#include "../model/signals.h"

namespace sc_test {
TEST(pattern, TEST_1) {
  sc::calcController test;
  std::string str = "cos(sin(x+1.0523))";
sc::status_e check = test.validation(str);
EXPECT_EQ(check, sc::status_e::OK);
}
TEST(pattern, TEST_2) {
sc::calcController test;
std::string str = "cos(sin(x+1.0523)";
sc::status_e check = test.validation(str);
EXPECT_EQ(check, sc::status_e::ERROR);
}

TEST(pattern, TEST_3) {
sc::calcController test;
std::string str = "cossin(sin(x+1.0523))";
sc::status_e check = test.validation(str);
EXPECT_EQ(check, sc::status_e::ERROR);
}

TEST(pattern, TEST_4) {
sc::calcController test;
std::string str = "cos(sin(x+1.05552.25523))";
sc::status_e check = test.validation(str);
EXPECT_EQ(check, sc::status_e::ERROR);
}

TEST(pattern, TEST_5) {
sc::calcController test;
std::string str = "cos(sin(1))";
sc::status_e check = test.validation(str);
EXPECT_EQ(check, sc::status_e::OK);
}

TEST(pattern, TEST_6) {
sc::calcController test;
std::string str = "1";
sc::status_e check = test.validation(str);
EXPECT_EQ(check, sc::status_e::OK);
}

TEST(pattern, TEST_7) {
sc::calcController test;
std::string str = "1+(7+3)";
sc::status_e check = test.validation(str);
EXPECT_EQ(check, sc::status_e::OK);
}

TEST(pattern, TEST_8) {
sc::calcController test;
std::string str = "1+(7++3)";
sc::status_e check = test.validation(str);
EXPECT_EQ(check, sc::status_e::OK);
}

TEST(pattern, TEST_9) {
sc::calcController test;
std::string str = "1+(7+++3)";
sc::status_e check = test.validation(str);
EXPECT_EQ(check, sc::status_e::ERROR);
}
TEST(pattern, TEST_10) {
sc::calcController test;
std::string str = "cos)1";
sc::status_e check = test.validation(str);
EXPECT_EQ(check, sc::status_e::ERROR);
}
}

