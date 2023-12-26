#ifndef MOVE_H
#define MOVE_H

#include "core/mission.hpp"
#include "core/types.hpp"

#include <sstream>

class Move : public Mission
{
public:
  Move(double xGoal = 500, double yGoal = 500,
       MoveType moveType = MoveType::JUST_IN_POINT,
       MoveDepthType moveTypeDepth = MoveDepthType::CONST_DEPTH,
       double vicinity = 3)
      : mXgoal(xGoal), mYgoal(yGoal), mMoveType(moveType),
        mMoveTypeDepth(moveTypeDepth), mVicinity(vicinity){};

  std::string Run() override
  {
    std::stringstream res;
    res << "Move: " << mXgoal << " " << mYgoal << " " << mMoveType << " "
        << mMoveTypeDepth << " " << mVicinity;
    return res.str();
    // std::cout << res.str();
  };

private:
  const double mXgoal;
  const double mYgoal;
  const MoveType mMoveType;
  const MoveDepthType mMoveTypeDepth;
  const double mVicinity;
};

#endif // MOVE_H
