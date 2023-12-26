#ifndef EXIT_HPP
#define EXIT_HPP

#include "core/context.hpp"
#include "missions/return.hpp"
#include "utils/write_missions.hpp"

#include <iostream>

void Exit(Context &ctx)
{

  if (!ctx.missions.empty() &&
      dynamic_cast<Return *>(ctx.missions.back()) == nullptr)
  {
    ctx.missions.push_back(new Return());
  }

  std::cout << "Saving ... ";
  WriteMissions(ctx.missions, ctx.saveFileName);
  std::cout << "Finish" << std::endl;
}

#endif // EXIT_HPP
