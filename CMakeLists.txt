cmake_minimum_required(VERSION 3.5)

project(DZ_3_planner_mission)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_executable(DZ_3_planner_mission main.cpp lib/dive.hpp lib/return.hpp lib/lift.hpp lib/move.hpp lib/core/entity.hpp lib/core/mission.hpp )

# install(TARGETS DZ_3_planner_mission
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/lib)

