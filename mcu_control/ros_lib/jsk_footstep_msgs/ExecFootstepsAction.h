#ifndef _ROS_jsk_footstep_msgs_ExecFootstepsAction_h
#define _ROS_jsk_footstep_msgs_ExecFootstepsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_footstep_msgs/ExecFootstepsActionGoal.h"
#include "jsk_footstep_msgs/ExecFootstepsActionResult.h"
#include "jsk_footstep_msgs/ExecFootstepsActionFeedback.h"

namespace jsk_footstep_msgs
{

  class ExecFootstepsAction : public ros::Msg
  {
    public:
      jsk_footstep_msgs::ExecFootstepsActionGoal action_goal;
      jsk_footstep_msgs::ExecFootstepsActionResult action_result;
      jsk_footstep_msgs::ExecFootstepsActionFeedback action_feedback;

    ExecFootstepsAction():
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

    const char * getType(){ return "jsk_footstep_msgs/ExecFootstepsAction"; };
    const char * getMD5(){ return "3e35eb18eb23fb65da3bd1f390fc30ae"; };

  };

}
#endif