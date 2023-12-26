#ifndef ADD_RETURN_HPP
#define ADD_RETURN_HPP

#include "core/context.hpp"
#include "core/types.hpp"
#include "missions/return.hpp"

StateType AddReturn(Context &ctx)
{
  ctx.missions.insert(std::next(ctx.missions.begin(), ctx.insertID), new Return());
  ctx.insertID = ctx.missions.size();
  ctx.current_x = ctx.current_y = ctx.current_z = 0;
  //std::cout << " ctx.current_x " << ctx.current_x << " ctx.current_x " << ctx.current_y << " ctx.current_z " << ctx.current_z  << std::endl;
  std::cout << "Mission succesfully added!" << std::endl << std::endl;

  return StateType::SAVE_MISSION;
}

#endif // ADD_RETURN_HPP
