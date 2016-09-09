#ifndef _ROS_fetch_auto_dock_msgs_DockActionGoal_h
#define _ROS_fetch_auto_dock_msgs_DockActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "fetch_auto_dock_msgs/DockGoal.h"

namespace fetch_auto_dock_msgs
{

  class DockActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      fetch_auto_dock_msgs::DockGoal goal;

    DockActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "fetch_auto_dock_msgs/DockActionGoal"; };
    const char * getMD5(){ return "69333baaf59d995d4a69e40ea04b8312"; };

  };

}
#endif