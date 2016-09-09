#ifndef _ROS_fetch_auto_dock_msgs_DockAction_h
#define _ROS_fetch_auto_dock_msgs_DockAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fetch_auto_dock_msgs/DockActionGoal.h"
#include "fetch_auto_dock_msgs/DockActionResult.h"
#include "fetch_auto_dock_msgs/DockActionFeedback.h"

namespace fetch_auto_dock_msgs
{

  class DockAction : public ros::Msg
  {
    public:
      fetch_auto_dock_msgs::DockActionGoal action_goal;
      fetch_auto_dock_msgs::DockActionResult action_result;
      fetch_auto_dock_msgs::DockActionFeedback action_feedback;

    DockAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "fetch_auto_dock_msgs/DockAction"; };
    const char * getMD5(){ return "cce26d4fecf14ada90d5d392d0b75e38"; };

  };

}
#endif