#ifndef HELPER_HPP
#define HELPER_HPP

#include <set>
#include <vector>

template <typename T>
std::vector<T> SetToVector(const std::set<T>& input) {
  return std::vector<T>(input.begin(), input.end());
}

#endif