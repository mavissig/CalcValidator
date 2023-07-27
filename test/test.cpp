//
// Created by mavissig on 26.07.23.
//

#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "../controller/controller.h"

namespace sc_test {
TEST(pattern, TEST_1) {
  sc::calcController test;
  std::string str = "cos(sin(x+1.0523))";
  test.validation(str);
}
}

