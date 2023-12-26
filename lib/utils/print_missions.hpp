#ifndef PRINT_MISSIONS_HPP
#define PRINT_MISSIONS_HPP

#include "core/mission.hpp"

#include <iostream>
#include <list>

void PrintMissions(std::list<Mission *> missions)
{
  for (auto m : missions)
  {
    std::cout << m->Run() << std::endl;
  }
    std::cout << std::endl
    << "Please, choose a mission: 1 - dive, 2 - lift, 3 - move, 4 - return\n"
    << "For view selected missions: 5\n"
    << "For end or delete or insert or swap missions: 0" << std::endl << std::endl;
}

#endif // PRINT_MISSIONS_HPP
