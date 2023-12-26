#ifndef ADD_MISSIONS_HPP
#define ADD_MISSIONS_HPP

#include "core/context.hpp"
#include "core/types.hpp"
#include "utils/print_missions.hpp"
#include "utils/read_console.hpp"

#include <iostream>

StateType AddMissions(Context &ctx)
{
  std::cout
    << std::endl
    << "Please, choose a mission: 1 - dive, 2 - lift, 3 - move, 4 - return\n"
    << "For view selected missions: 5\n"
    << "For end or delete or insert or swap missions: 0" << std::endl << std::endl;
  int mission_choose = 0;

  while ((mission_choose = ReadNumber<int>()) != 0)
  {
    switch (mission_choose)
    {
    case 1:
      return StateType::ADD_DIVE;
    case 2:
      return StateType::ADD_LIFT;
    case 3:
      return StateType::ADD_MOVE;
    case 4:
      return StateType::ADD_RETURN;
    case 5:
      PrintMissions(ctx.missions);
      break;
    case -2:
      return StateType::EXIT;
    default:
      std::cout << "Input must be 1 | 2 | 3 | 4 | 5 | 0" << std::endl;
      break;
    }
  }

  std::cout << "End missions adding" << std::endl;
  return StateType::SAVE_MISSION;
}

#endif // ADD_MISSIONS_HPP
