//
// Created by mavissig on 27.07.23.
//

#ifndef CALCVALIDATOR_MODEL_VALIDATOR_H_
#define CALCVALIDATOR_MODEL_VALIDATOR_H_

#include <regex>
#include <string>

#include "signals.h"

namespace sc {
class validator {
 public:
  status_e validate(std::string &str);

 private:
  status_e parser(std::string &str);
  status_e check_bracket(std::string &str);
  status_e status_;
};

sc::status_e sc::validator::validate(std::string &str) {
  status_ = check_bracket(str);
  if (status_ == status_e::OK) status_ = parser(str);
  return status_;
}

sc::status_e sc::validator::check_bracket(std::string &str) {
  int condition = 0;
  for (auto i = str.begin(); i != str.end(); i++) {
    if (*i == '(') {
      condition++;
    }
    if (*i == ')') {
      condition--;
      if (0 > condition) {
        return status_e::ERROR;
      }
    }
  }
  return (0 != condition) ? status_e::ERROR : status_e::OK;
}

sc::status_e sc::validator::parser(std::string &str) {
  std::regex regexPattern(
      R"(^(\s*((cos\()|(sin\()|x|(\d+\.\d+(?!\d))|\d+|\\|\^|(\+\+(?!\+))|(\+(?!\+))|[\-()])\s*)+$)");
  if (std::regex_match(str, regexPattern)) {
    return status_e::OK;
  } else {
    return status_e::ERROR;
  }
}
}  // namespace sc
#endif  // CALCVALIDATOR_MODEL_VALIDATOR_H_
