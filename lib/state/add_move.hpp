#ifndef ADD_MOVE_HPP
#define ADD_MOVE_HPP

#include "core/context.hpp"
#include "core/types.hpp"
#include "missions/move.hpp"
#include "utils/read_console.hpp"

double current_x_check = 0;
double current_y_check = 0;

StateType AddMove(Context &ctx)
{
  std::cout 
    << "--------------------------------------------\n"
    << "Adding Move mission, example 1 23 0 50 0:\n"
    << "X goal: float number\n"
    << "Y goal: float number\n"
    << "Move type: 0 - just in point, 1 - along straight\n"
    << "Move depth Type: 0 - depth, 1 - repentance\n"
    << "--------------------------------------------\n"
    << std::endl;
  double xGoal = ReadNumber<double>();
  double yGoal = ReadNumber<double>();
  int moveCMD = ReadNumber<int>();
  int moveDepthCMD = ReadNumber<int>();
  //double vicinity = ReadNumber<double>();
  if (xGoal == -2 || yGoal == -2 || moveCMD == -2 || moveDepthCMD == -2)
  {
    return StateType::EXIT;
  }
  if (xGoal == -1 || yGoal == -1 || moveCMD == -1 || moveDepthCMD == -1 || moveCMD > 1 || moveDepthCMD > 1)
  {
    std::cout << "!!! Input error, try again !!!" << std::endl << std::endl;
    return StateType::ADD_MISSIONS;
  }
 
  if ( (xGoal > X_POLIGONS) || (yGoal > Y_POLIGONS)) {
    std::cout << "!!! Input error, you went beyond the poligon !!!" << std::endl << std::endl;
    return StateType::ADD_MISSIONS;  
  }
  ctx.current_x = xGoal;
  ctx.current_y = yGoal;
 
  ctx.missions.insert(std::next(ctx.missions.begin(), ctx.insertID), new Move(xGoal, yGoal, (MoveType)moveCMD, (MoveDepthType)moveDepthCMD));
  ctx.insertID = ctx.missions.size();
  std::cout << "Mission succesfully added!" << std::endl << std::endl;
  //std::cout << " ctx.current_x " << ctx.current_x << " ctx.current_x " << ctx.current_y << " ctx.current_z " << ctx.current_z  << std::endl;
  
  return StateType::SAVE_MISSION;
}

#endif // ADD_MOVE_HPP
