#ifndef SAVE_MISSIONS_HPP
#define SAVE_MISSIONS_HPP

#include "core/context.hpp"
#include "core/types.hpp"

#include <fstream>
#include <list>
#include <string>

StateType SaveMission(Context &ctx)
{
  std::ofstream file;
  file.open(ctx.saveFileName);
  for (auto mission : ctx.missions)
  {
    file << mission->Run() << std::endl;
  }
  file.close();
  return StateType::MENU;
}

#endif // SAVE_MISSIONS_HPP