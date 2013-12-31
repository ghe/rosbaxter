#include "rosbaxter.h"
#include "ros/ros.h"
#include <stdio.h>
#include "currentpose.h"

RosBaxter::RosBaxter(std::string const &nodename) :
_pcurrentpose(new CurrentPose)
{
  std::map<std::string, std::string> remapping;
  ros::init(remapping, nodename.c_str());
  _pnh = new ros::NodeHandle();
}

RosBaxter::~RosBaxter()
{
  delete _pnh;
  delete _pcurrentpose;
}

bool RosBaxter::ok()
{
  ros::ok();
}

bool RosBaxter::update()
{
  if (ok())
  {
    ros::spinOnce();
    return true;
  }
  return false;
}

bool RosBaxter::subToPose()
{
  if (ok())
  {
    _pcurrentpose->subscribe(_pnh);
  }
}

const RosBaxter::Pose &RosBaxter::getPose()
{
  return _pcurrentpose->get();
}

