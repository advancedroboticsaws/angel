#ifndef _ROS_robot_calibration_msgs_GripperLedCommandAction_h
#define _ROS_robot_calibration_msgs_GripperLedCommandAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robot_calibration_msgs/GripperLedCommandActionGoal.h"
#include "robot_calibration_msgs/GripperLedCommandActionResult.h"
#include "robot_calibration_msgs/GripperLedCommandActionFeedback.h"

namespace robot_calibration_msgs
{

  class GripperLedCommandAction : public ros::Msg
  {
    public:
      robot_calibration_msgs::GripperLedCommandActionGoal action_goal;
      robot_calibration_msgs::GripperLedCommandActionResult action_result;
      robot_calibration_msgs::GripperLedCommandActionFeedback action_feedback;

    GripperLedCommandAction():
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

    const char * getType(){ return "robot_calibration_msgs/GripperLedCommandAction"; };
    const char * getMD5(){ return "48f166d6c125d28b70639966a1197497"; };

  };

}
#endif