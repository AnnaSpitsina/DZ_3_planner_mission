#ifndef ADD_DIVE_HPP
#define ADD_DIVE_HPP

#include "core/context.hpp"
#include "core/types.hpp"
#include "missions/dive.hpp"
#include "utils/read_console.hpp"

StateType AddDive(Context &ctx)
{
  std::cout 
    << "--------------------------------------------\n"
    << "Adding Dive mission, example 1 25.4 0:\n"
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
    std::cout << "!!! Input error, try again !!!" << std::endl << std::endl;
    return StateType::ADD_MISSIONS;
  }

  if (depth > Z_POLIGONS) {
      std::cout << "!!! Input error, you went beyond the poligon !!!" << std::endl << std::endl;
      return StateType::ADD_MISSIONS;  
    }
  // if ((depthSensorCMD == 0) && (ctx.current_z > depth) || (depthSensorCMD == 1) && (ctx.current_z > Z_POLIGONS - depth)) {
  //   std::cout << "!!! You are lower than the point you want to dive to, you in " << ctx.current_z << " meters depth, try again !!!" << std::endl << std::endl;
  //   return StateType::ADD_MISSIONS;  
  // }
  
  if (depthSensorCMD == 0) {
    ctx.current_z = depth;
    }
  if (depthSensorCMD == 1) {
    ctx.current_z = Z_POLIGONS - depth;
    }
  
  ctx.missions.insert(std::next(ctx.missions.begin(), ctx.insertID), new Dive((DepthType)depthSensorCMD, depth, (DiveType)diveCMD));
  ctx.insertID = ctx.missions.size();
  std::cout << "Mission succesfully added!" << std::endl << std::endl;
  //std::cout << " ctx.current_x " << ctx.current_x << " ctx.current_x " << ctx.current_y << " ctx.current_z " << ctx.current_z  << std::endl;
  
  return StateType::SAVE_MISSION;
}

#endif // ADD_DIVE_HPP
