#include "client.hpp"

#include <vector>

#include "helper.hpp"

Client& Client::operator+=(const Project& rhs) {
  (void)rhs;  // remove me
  return *this;
}

Client& Client::operator-=(const Project& rhs) {
  (void)rhs;  // remove me
  return *this;
}

bool Client::operator<(const Client& rhs) const {
  (void)rhs;  // remove me
  return false;
}