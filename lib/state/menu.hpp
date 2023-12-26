#ifndef MENU_HPP
#define MENU_HPP

#include "core/types.hpp"
#include "utils/read_console.hpp"
#include "core/context.hpp"

#include "iostream"

StateType Menu(Context &ctx)
{
  std::cout << "0 - exit, 1 - add missions, 2 - delete mission, 3 - insert mission in list, 4 - swap two missions, 5 - edit mission" << std::endl << std::endl;
  int cmd = 0;
  while (1)
  {
    cmd = ReadNumber<int>();
    switch (cmd)
    {
    case 5:
      return StateType::EDIT_MISSION;
      break;
    case 4:
      return StateType::SWAP_MISSION;
      break;
    case 3:
      return StateType::INSERT_MISSION;
      break;
    case 2:
      return StateType::DELETE_MISSIONS;
      break;
    case 1:
      ctx.insertID = ctx.missions.size();
      return StateType::ADD_MISSIONS;
      break;
    case -2:
    case 0:
      return StateType::EXIT;
      break;
    default:
      std::cout << "!!! Input must be 5 | 4 | 3 | 2 | 1 | 0 !!!" << std::endl;
      break;
    }
  }
}

#endif // MENU_HPP
