#ifndef DELETE_MISSIONS_HPP
#define DELETE_MISSIONS_HPP

#include "core/context.hpp"
#include "utils/remove_missions.hpp"

StateType DeleteMission(Context &ctx)
{
  std::cout 
    << "--------------------------------------------\n"
    << "Which mission number do you want to delete?\n" 
    << "--------------------------------------------\n"
    << std::endl;
  int numberMissionForDelete = ReadNumber<int>();
  if (numberMissionForDelete == -2)
  {
      return StateType::EXIT;
  }
  if (numberMissionForDelete == -1 || numberMissionForDelete > ctx.missions.size() + 1) {
        std::cout << std::endl << "You have gone beyond the limits of an existing file" << std::endl;
    return StateType::MENU;    
    }
  RemoveMissions(ctx, numberMissionForDelete);
  return StateType::SAVE_MISSION;
}

#endif // DELETE_MISSIONS_HPP
