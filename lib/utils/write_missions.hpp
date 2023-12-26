#ifndef WRITE_MISSIONS_HPP
#define WRITE_MISSIONS_HPP

#include "core/context.hpp"

#include <fstream>
#include <list>
#include <string>

void WriteMissions(std::list<Mission *> missions, std::string const &fileName)
{
  std::ofstream file;
  file.open(fileName);
  for (auto mission : missions)
  {
    file << mission->Run() << std::endl;
  }
  file.close();
}

#endif // WRITE_MISSIONS_HPP
