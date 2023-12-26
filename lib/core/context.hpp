#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "mission.hpp"

#include <list>
#include <string>

double X_POLIGONS = 10000;
double Y_POLIGONS = 10000;
double Z_POLIGONS = 100;

struct Context
{
  ~Context()
  {
    for (auto m : missions)
    {
      delete m;
    }
  }

  std::string saveFileName = "save.txt";
  std::list<Mission *> missions;
  int insertID;
  double current_x = 0;
  double current_y = 0;
  double current_z = 0;

};

#endif // CONTEXT_HPP
