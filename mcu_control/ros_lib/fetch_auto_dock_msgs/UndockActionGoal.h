#ifndef _ROS_fetch_auto_dock_msgs_UndockActionGoal_h
#define _ROS_fetch_auto_dock_msgs_UndockActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "fetch_auto_dock_msgs/UndockGoal.h"

namespace fetch_auto_dock_msgs
{

  class UndockActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      fetch_auto_dock_msgs::UndockGoal goal;

    UndockActionGoal():
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

    const char * getType(){ return "fetch_auto_dock_msgs/UndockActionGoal"; };
    const char * getMD5(){ return "83d89c5d575f723697d44b3ce0db1099"; };

  };

}
#endif