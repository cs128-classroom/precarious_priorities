#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <string>

class Project {
public:
  Project(unsigned int num_users,
          const std::string& project_name,
          unsigned int contract_value):
      project_name_(project_name),
      num_users_(num_users),
      contract_value_(contract_value) {};

  std::string GetProjectName() const { return project_name_; }
  unsigned int GetNumUsers() const { return num_users_; }
  unsigned int GetContractValue() const { return contract_value_; }

  bool operator<(const Project& rhs) const;

private:
  std::string project_name_;
  unsigned int num_users_;
  unsigned int contract_value_;
};

#endif