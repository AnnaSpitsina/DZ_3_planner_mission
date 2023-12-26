#ifndef LIFT_H
#define LIFT_H

#include "core/mission.hpp"
#include "core/types.hpp"

#include <sstream>

class Lift : public Mission
{
public:
  Lift(DepthType depthType = DepthType::DEPTH_SENSOR, double depth = 0,
       DiveType diveType = DiveType::VERTICAL)
      : mDepthType(depthType), mDepth(depth), mDiveType(diveType){};

  std::string Run() override
  {
    std::stringstream res;
    res << "Lift: " << mDepthType << " " << mDepth << " " << mDiveType;
    return res.str();
    // std::cout << res.str();
  };

private:
  const DepthType mDepthType;
  const double mDepth;
  const DiveType mDiveType;
};

#endif // LIFT_H
