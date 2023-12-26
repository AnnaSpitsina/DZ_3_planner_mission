#ifndef SWAP_MISSION_HPP
#define SWAP_MISSION_HPP

#include "core/context.hpp"
#include "core/types.hpp"
#include "utils/read_console.hpp"

StateType SwapMission(Context &ctx)
{
  std::cout 
    << "--------------------------------------------\n"
    << "Which two missions do you want to swap?\n" 
    << "--------------------------------------------\n"
    << std::endl;
    int indexForSwap1 = ReadNumber<int>();
    int indexForSwap2 = ReadNumber<int>();

    if (indexForSwap1 == -2 || indexForSwap2 == -2)
    {
      return StateType::EXIT;
    }
    
    if (indexForSwap1 == -1 || indexForSwap1 > ctx.missions.size() || indexForSwap2 == -1 || indexForSwap2 > ctx.missions.size()) {
        std::cout << "Error, you have gone beyond the limits of an existing file" << std::endl << std::endl;
        return StateType::MENU;
    }
    //ctx.insertID = indexForInsert - 1;

    auto iter1 = ctx.missions.begin();
    std::advance(iter1, indexForSwap1 - 1);
    auto iter2 = ctx.missions.begin();
    std::advance(iter2, indexForSwap2 - 1);
    std::swap(*iter1, *iter2);
    std::cout  << "The exchange was completed successfully" << std::endl << std::endl;

    return StateType::SAVE_MISSION;
}

#endif // SWAP_MISSION_HPP