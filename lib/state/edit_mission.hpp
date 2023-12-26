#ifndef EDIT_MISSION_HPP
#define EDIT_MISSION_HPP

#include "core/context.hpp"
#include "utils/remove_missions.hpp"

StateType EditMission(Context &ctx)
{
    std::cout 
    << "--------------------------------------------\n"
    << "Which mission number do you want to edit?\n" 
    << "--------------------------------------------\n"
    << std::endl;
    int numberMissionForEdit = ReadNumber<int>();
    if (numberMissionForEdit == -2)
    {
        return StateType::EXIT;
    }
    if (numberMissionForEdit == -1 || numberMissionForEdit > ctx.missions.size() + 1) {
        std::cout << std::endl << "You have gone beyond the limits of an existing file" << std::endl;
    return StateType::MENU;    
    }
    RemoveMissions(ctx, numberMissionForEdit);
    std::cout 
    << "--------------------------------------------\n"
    << "Next, you will need to select the mission again and enter its parameters\n" 
    << "--------------------------------------------\n"
    << std::endl;
    ctx.insertID = numberMissionForEdit-1;
    return StateType::ADD_MISSIONS;
}

#endif // EDIT_MISSION_HPP