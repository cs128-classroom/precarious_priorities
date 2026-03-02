#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <set>
#include <stdexcept>
#include <string>

#include "project.hpp"

class Client {
public:
  Client(const std::string& client_name):
      Client(std::set<Project>(), client_name, std::set<Project>()){};

  Client(const std::set<Project>& current_projects,
         const std::string& client_name,
         const std::set<Project>& completed_projects):
      client_name_(client_name),
      current_projects_(current_projects),
      completed_projects_(completed_projects){};

  const std::set<Project>& GetCurrentProjects() { return current_projects_; }
  const std::set<Project>& GetCompletedProjects() {
    return completed_projects_;
  }

  Client& operator+=(const Project& rhs);

  Client& operator-=(const Project& rhs);

  bool operator<(const Client& rhs) const;

private:
  std::string client_name_;
  std::set<Project> current_projects_;
  std::set<Project> completed_projects_;
};

#endif