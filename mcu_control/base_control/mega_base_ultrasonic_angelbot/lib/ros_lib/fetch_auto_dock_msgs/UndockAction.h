#ifndef _ROS_fetch_auto_dock_msgs_UndockAction_h
#define _ROS_fetch_auto_dock_msgs_UndockAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fetch_auto_dock_msgs/UndockActionGoal.h"
#include "fetch_auto_dock_msgs/UndockActionResult.h"
#include "fetch_auto_dock_msgs/UndockActionFeedback.h"

namespace fetch_auto_dock_msgs
{

  class UndockAction : public ros::Msg
  {
    public:
      fetch_auto_dock_msgs::UndockActionGoal action_goal;
      fetch_auto_dock_msgs::UndockActionResult action_result;
      fetch_auto_dock_msgs::UndockActionFeedback action_feedback;

    UndockAction():
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

    const char * getType(){ return "fetch_auto_dock_msgs/UndockAction"; };
    const char * getMD5(){ return "67f75452c196985277234c9f084093d5"; };

  };

}
#endif