//
// Created by mavissig on 27.07.23.
//

#ifndef CALCVALIDATOR_MODEL_VALIDATOR_H_
#define CALCVALIDATOR_MODEL_VALIDATOR_H_

#include <string>
#include <regex>

#include "signals.h"

namespace sc {
class validator {
 public:
  status_e validate(std::string &str);
  status_e parser(std::string &str);
 private:
  int date_;
};

sc::status_e sc::validator::validate(std::string &str) {
  status_e current_status = status_e::OK;
  current_status = parser(str);
  return current_status;
}

sc::status_e sc::validator::parser(std::string &str) {
  std::regex regexPattern(R"(^(\s*((cos\()|(sin\()|x|\d+\.\d+|\d+|\\|\^|[\+\-()])\s*)+$)");
  if (std::regex_match(str, regexPattern)) {
    std::cout << "All required characters are present in the string." << std::endl;
    std::cout << "[current string]: " << str << std::endl;
    std::cout << "src size= " << str.size() << std::endl;
    return status_e::OK;
  } else {
    std::cout << "Not all required characters are present in the string." << std::endl;
    std::cout << "[current string]: " << str << std::endl;
    std::cout << "src size= " << str.size() << std::endl;
    return status_e::ERROR;
  }
}
}
#endif //CALCVALIDATOR_MODEL_VALIDATOR_H_
