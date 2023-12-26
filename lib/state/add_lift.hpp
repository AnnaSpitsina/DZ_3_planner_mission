#ifndef ADD_LIFT_HPP
#define ADD_LIFT_HPP

#include "core/context.hpp"
#include "core/types.hpp"
#include "missions/lift.hpp"
#include "utils/read_console.hpp"

StateType AddLift(Context &ctx)
{
  std::cout 
    << "--------------------------------------------\n"
    << "Adding Lift mission, example 1 25.4 2:\n"
    << "Depth sensor: 0 - depth sensor, 1 - echo sensor\n"
    << "Depth: float number\n"
    << "Dive Type: 0 - spiral, 1 - vertical\n"
    << "--------------------------------------------\n" 
    << std::endl;
  int depthSensorCMD = ReadNumber<int>();
  double depth = ReadNumber<double>();
  int diveCMD = ReadNumber<int>();
  if (depthSensorCMD == -2 || depth == -2 || diveCMD == -2)
  {
    return StateType::EXIT;
  }
  if (depthSensorCMD == -1 || depth == -1 || diveCMD == -1 ||
      depthSensorCMD > 1 || diveCMD > 1)
  {
    std::cout << "!!! Input error, try again !!!" << std::endl << std::endl;;
    return StateType::ADD_MISSIONS;
  }

  if (depth > Z_POLIGONS) {
      std::cout << "!!! Input error, you went beyond the poligon !!!" << std::endl << std::endl;
      return StateType::ADD_MISSIONS;  
    }
  // if ((depthSensorCMD == 0) && (ctx.current_z < depth) || (depthSensorCMD == 1) && (ctx.current_z < Z_POLIGONS - depth)) {
  //   std::cout << "!!! You are higher than the point you want to lift to, you in " << ctx.current_z << " meters depth, try again !!!" << std::endl << std::endl;
  //   return StateType::ADD_MISSIONS;  
  // }
  
  if (depthSensorCMD == 0) {
    ctx.current_z = depth;
  }
  if (depthSensorCMD == 1) {
    ctx.current_z = Z_POLIGONS - depth;
  }

  ctx.missions.insert(std::next(ctx.missions.begin(), ctx.insertID), new Lift((DepthType)depthSensorCMD, depth, (DiveType)diveCMD));
  ctx.insertID = ctx.missions.size();
  std::cout << "Mission succesfully added!" << std::endl << std::endl;
  //std::cout << " ctx.current_x " << ctx.current_x << " ctx.current_x " << ctx.current_y << " ctx.current_z " << ctx.current_z  << std::endl;
  
  return StateType::SAVE_MISSION;
}

#endif // ADD_LIFT_HPP
