#ifndef _ROS_jsk_footstep_msgs_PlanFootstepsAction_h
#define _ROS_jsk_footstep_msgs_PlanFootstepsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_footstep_msgs/PlanFootstepsActionGoal.h"
#include "jsk_footstep_msgs/PlanFootstepsActionResult.h"
#include "jsk_footstep_msgs/PlanFootstepsActionFeedback.h"

namespace jsk_footstep_msgs
{

  class PlanFootstepsAction : public ros::Msg
  {
    public:
      jsk_footstep_msgs::PlanFootstepsActionGoal action_goal;
      jsk_footstep_msgs::PlanFootstepsActionResult action_result;
      jsk_footstep_msgs::PlanFootstepsActionFeedback action_feedback;

    PlanFootstepsAction():
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

    const char * getType(){ return "jsk_footstep_msgs/PlanFootstepsAction"; };
    const char * getMD5(){ return "7353a3590ff62d4eb101134b949f1ea7"; };

  };

}
#endif