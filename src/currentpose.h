#ifndef __CURRENTPOSE_H__
#define __CURRENTPOSE_H__

#include "sensor_msgs/JointState.h"
#include "rosbaxter.h"
#include "ros/ros.h"

class CurrentPose
{
public:
  CurrentPose();
  virtual ~CurrentPose();

  void subscribe(ros::NodeHandle *pnh);
  const RosBaxter::Pose &get() { return _pose; }

private:
  void callback(const sensor_msgs::JointState::ConstPtr &msg);

  RosBaxter::Pose _pose;
  ros::Subscriber _sub;
};

#endif //__CURRENTPOSE_H__
