#ifndef __ROSBAXTER_H__
#define __ROSBAXTER_H__

#include <string>
#include <map>

//forward declarations
namespace ros {
  class NodeHandle;
};

class CurrentPose;

//TODO: consider making this a singleton
class RosBaxter
{
public:
  typedef std::map<std::string, double> Pose;

  explicit RosBaxter(std::string const &nodename);
  virtual ~RosBaxter();

  bool ok();
  bool update();
  bool subToPose();
  const Pose &getPose();

private:

  ros::NodeHandle *_pnh;
  CurrentPose *_pcurrentpose;
};

#endif // __ROSBAXTER_H__

