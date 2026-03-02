#include "client.hpp"

#include <vector>

#include "helper.hpp"

Client& Client::operator+=(const Project& rhs) {
  (void)rhs;
  return *this;
}

Client& Client::operator-=(const Project& rhs) {
  (void)rhs;
  return *this;
}

bool Client::operator<(const Client& rhs) const {
  (void)rhs;
  return false;
}