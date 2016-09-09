#ifndef _ROS_grasping_msgs_GraspPlanningAction_h
#define _ROS_grasping_msgs_GraspPlanningAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "grasping_msgs/GraspPlanningActionGoal.h"
#include "grasping_msgs/GraspPlanningActionResult.h"
#include "grasping_msgs/GraspPlanningActionFeedback.h"

namespace grasping_msgs
{

  class GraspPlanningAction : public ros::Msg
  {
    public:
      grasping_msgs::GraspPlanningActionGoal action_goal;
      grasping_msgs::GraspPlanningActionResult action_result;
      grasping_msgs::GraspPlanningActionFeedback action_feedback;

    GraspPlanningAction():
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

    const char * getType(){ return "grasping_msgs/GraspPlanningAction"; };
    const char * getMD5(){ return "7133eaf5c7bbf3f1f2b109ce543a58b0"; };

  };

}
#endif