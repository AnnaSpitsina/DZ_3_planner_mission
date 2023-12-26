#ifndef DRIVE_HPP
#define DRIVE_HPP

#include "core/mission.hpp"
#include "core/types.hpp"

#include <sstream>

class Dive : public Mission
{
public:
  Dive(DepthType depthType = DepthType::DEPTH_SENSOR, double depth = 0,
       DiveType diveType = DiveType::VERTICAL)
      : mDepthType(depthType), mDepth(depth), mDiveType(diveType){};

  std::string Run() override
  {
    std::stringstream res;
    res << "Dive: " << mDepthType << " " << mDepth << " " << mDiveType;
    return res.str();
    // std::cout << res.str();
  };

private:
  const DepthType mDepthType;
  const double mDepth;
  const DiveType mDiveType;
};

#endif // DRIVE_HPP
