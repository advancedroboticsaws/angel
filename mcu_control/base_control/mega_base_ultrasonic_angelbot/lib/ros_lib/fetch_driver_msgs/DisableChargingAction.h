#ifndef _ROS_fetch_driver_msgs_DisableChargingAction_h
#define _ROS_fetch_driver_msgs_DisableChargingAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fetch_driver_msgs/DisableChargingActionGoal.h"
#include "fetch_driver_msgs/DisableChargingActionResult.h"
#include "fetch_driver_msgs/DisableChargingActionFeedback.h"

namespace fetch_driver_msgs
{

  class DisableChargingAction : public ros::Msg
  {
    public:
      fetch_driver_msgs::DisableChargingActionGoal action_goal;
      fetch_driver_msgs::DisableChargingActionResult action_result;
      fetch_driver_msgs::DisableChargingActionFeedback action_feedback;

    DisableChargingAction():
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

    const char * getType(){ return "fetch_driver_msgs/DisableChargingAction"; };
    const char * getMD5(){ return "779104bea58517403422a5cae55a1bb1"; };

  };

}
#endif