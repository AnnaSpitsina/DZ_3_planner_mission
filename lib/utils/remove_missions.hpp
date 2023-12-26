#ifndef REMOVE_MISSIONS_HPP
#define REMOVE_MISSIONS_HPP

#include "core/types.hpp"
#include "utils/read_console.hpp"
#include "core/context.hpp"

void RemoveMissions(Context &ctx, int numberMission)
{
    // Поиск элемента по индексу
    auto it = ctx.missions.begin();
    std::advance(it, numberMission- 1);

    if (it != ctx.missions.end()) {
        // Удаление объекта, на который указывает итератор
        delete *it;
        // Удаление элемента из списка
        ctx.missions.erase(it);
        
        std::cout << "Object at index " << numberMission << " delete successfully" << std::endl << std::endl;
    } else {
        std::cout << "Index of mission out of range" << std::endl << std::endl;
    }
}

#endif // REMOVE_MISSIONS_HPP