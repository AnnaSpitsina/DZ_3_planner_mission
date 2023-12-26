#ifndef TYPES_HPP
#define TYPES_HPP

#include <iostream>

enum class StateType
{
  MENU,
  ADD_MISSIONS,
  ADD_DIVE,
  ADD_LIFT,
  ADD_MOVE,
  ADD_RETURN,
  DELETE_MISSIONS,
  INSERT_MISSION,
  SWAP_MISSION,
  SAVE_MISSION,
  EDIT_MISSION,
  EXIT
};

enum class DepthType
{
  DEPTH_SENSOR,
  ECHO_SENSOR
};

enum class DiveType
{
  SPIRAL,
  VERTICAL
};

enum class MoveType
{
  JUST_IN_POINT,
  ALONG_STRAIGHT,
};

enum class MoveDepthType
{
  CONST_DEPTH,
  CONST_REPENTANCE,
};

std::ostream &operator<<(std::ostream &os, DepthType depth)
{
  switch (depth)
  {
  case DepthType::DEPTH_SENSOR:
    os << "depth_sensor";
    break;
  case DepthType::ECHO_SENSOR:
    os << "echo_sensor";
    break;
  default:
    os.setstate(std::ios_base::failbit);
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, DiveType dive)
{
  switch (dive)
  {
  case DiveType::SPIRAL:
    os << "spiral_dive";
    break;
  case DiveType::VERTICAL:
    os << "vertical_sensor";
    break;
  default:
    os.setstate(std::ios_base::failbit);
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, MoveType move_type)
{
  switch (move_type)
  {
  case MoveType::JUST_IN_POINT:
    os << "just_in_point";
    break;
  case MoveType::ALONG_STRAIGHT:
    os << "along_straight";
    break;
  default:
    os.setstate(std::ios_base::failbit);
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, MoveDepthType move_type_depth)
{
  switch (move_type_depth)
  {
  case MoveDepthType::CONST_DEPTH:
    os << "const_depth";
    break;
  case MoveDepthType::CONST_REPENTANCE:
    os << "const_repentance";
    break;
  default:
    os.setstate(std::ios_base::failbit);
  }
  return os;
}

#endif // TYPES_HPP
