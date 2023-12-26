#ifndef READ_CONSOLE_HPP
#define READ_CONSOLE_HPP

#include "iostream"

template <typename T> T ReadNumber()
{
  T input = 0;
  std::cin >> input;
  if (std::cin.good())
  {
    return input >= 0 ? input : -1;
  }
  std::cin.clear();
  std::cin.ignore(1, '\n');
  if (std::cin.eof())
  {
    return -2;
  }
  return -1;
}

#endif // READ_CONSOLE_HPP
