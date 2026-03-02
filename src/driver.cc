#include <iostream>

#include "client.hpp"
#include "project.hpp"

int main() {
  Client awesome_client("The Awesome Client");
  const Project kCoolProject(100, "Cool Project", 55);

  awesome_client += kCoolProject;

  return 0;
}
