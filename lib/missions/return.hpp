#ifndef RETURN_HPP
#define RETURN_HPP

#include "core/mission.hpp"

class Return : public Mission
{
public:
  std::string Run() override { return "Return"; };
};

#endif // RETURN_HPP
