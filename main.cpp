#include "lib/missions.hpp"
#include "lib/states.hpp"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#define FILE_SAVE "planner_file.txt"

int main()
{
  Context ctx;
  ctx.saveFileName = FILE_SAVE;
  StateType state = StateType::MENU;
  bool isStateMachineWorked = true;

  std::cout << "Start!" << std::endl;
  while (isStateMachineWorked)
  {
    switch (state)
    {
    case StateType::MENU:
      state = Menu(ctx);
      break;
    case StateType::ADD_MISSIONS:
      state = AddMissions(ctx);
      break;
    case StateType::ADD_DIVE:
      state = AddDive(ctx);
      break;
    case StateType::ADD_LIFT:
      state = AddLift(ctx);
      break;
    case StateType::ADD_MOVE:
      state = AddMove(ctx);
      break;
    case StateType::ADD_RETURN:
      state = AddReturn(ctx);
      break;
    case StateType::DELETE_MISSIONS:  
      state = DeleteMission(ctx);
      break;
    case StateType::INSERT_MISSION:  
      state = InsertMission(ctx);
      break;
    case StateType::SWAP_MISSION:  
      state = SwapMission(ctx);
      break;
    case StateType::SAVE_MISSION:  
      state = SaveMission(ctx);
      break;
    case StateType::EDIT_MISSION:  
      state = EditMission(ctx);
      break;
    case StateType::EXIT:
      Exit(ctx);
      isStateMachineWorked = false;
      break;
    default:
      break;
    }
  }
  std::cout << "Exit!" << std::endl;
  return 0;
}
