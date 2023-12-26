#ifndef INSERT_MISSION_HPP
#define INSERT_MISSION_HPP

#include "core/context.hpp"
#include "core/types.hpp"
#include "utils/read_console.hpp"

StateType InsertMission(Context &ctx)
{
  std::cout 
    << "--------------------------------------------\n"
    << "Where should the mission be inserted in the account?\n" 
    << "--------------------------------------------\n"
    << std::endl;
    int indexForInsert = ReadNumber<int>();
    if (indexForInsert == -2)
  {
    return StateType::EXIT;
  }
    if (indexForInsert == -1 || indexForInsert > ctx.missions.size() + 1) {
        std::cout << std::endl << "You have gone beyond the limits of an existing file" << std::endl;
    return StateType::MENU;    
    }
    ctx.insertID = indexForInsert - 1;
  return StateType::ADD_MISSIONS;
}

#endif // INSERT_MISSION_HPP