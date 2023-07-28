//
// Created by mavissig on 26.07.23.
//
#ifndef CALCVALIDATOR_CONTROLLER_CALCCONTROLLER_H_
#define CALCVALIDATOR_CONTROLLER_CALCCONTROLLER_H_

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../model/signals.h"
#include "../model/validator.h"

namespace sc {
class calcController {
 public:
  status_e validation(std::string &str);
  std::string connect(std::string &str);
  std::multimap<double, std::pair<double, double>> connect(std::string &str,
                                                           double xVal,
                                                           double minVal,
                                                           double maxVal);

 private:
  status_e status_;
};

sc::status_e sc::calcController::validation(std::string &str) {
  validator V;
  return V.validate(str);
}
}  // namespace sc

#endif  // CALCVALIDATOR_CONTROLLER_CALCCONTROLLER_H_
