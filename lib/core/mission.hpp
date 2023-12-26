#ifndef MISSION_HPP
#define MISSION_HPP

#include <string>

class Mission
{
public:
  virtual ~Mission() = default;
  virtual std::string Run() = 0;
};

#endif // MISSION_HPP
