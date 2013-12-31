#include "currentpose.h"

CurrentPose::CurrentPose()
{
}

CurrentPose::~CurrentPose()
{
}

void CurrentPose::subscribe(ros::NodeHandle *pnh)
{
  std::string topic("/robot/joint_states");
  _sub = pnh->subscribe<sensor_msgs::JointState>(topic, 1, &CurrentPose::callback, this);
  ROS_INFO("subscribed to %s", topic.c_str());
}

void CurrentPose::callback(const sensor_msgs::JointState::ConstPtr &msg)
{
  ROS_INFO("Joint State received!");
  for (size_t i=0; i < msg->name.size(); i++)
  {
    _pose[msg->name[i]] = msg->position[i];
     ROS_INFO("%s = %f", msg->name[i].c_str(), msg->position[i]);
  }
}

