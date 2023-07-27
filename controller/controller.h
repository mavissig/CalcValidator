//
// Created by mavissig on 26.07.23.
//
#ifndef CALCVALIDATOR_CONTROLLER_CALCCONTROLLER_H_
#define CALCVALIDATOR_CONTROLLER_CALCCONTROLLER_H_

#include <iostream>
#include <string>

#include "../model/signals.h"
#include "../model/validator.h"

namespace sc {
class calcController {
 public:
  status_e validation(std::string &str);

 private:
  status_e status_;
};

sc::status_e sc::calcController::validation(std::string &str) {
  validator V;
  return V.validate(str);
}
}  // namespace sc

#endif  // CALCVALIDATOR_CONTROLLER_CALCCONTROLLER_H_
