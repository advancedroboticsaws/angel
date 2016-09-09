#ifndef _ROS_robot_calibration_msgs_GripperLedCommandActionGoal_h
#define _ROS_robot_calibration_msgs_GripperLedCommandActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "robot_calibration_msgs/GripperLedCommandGoal.h"

namespace robot_calibration_msgs
{

  class GripperLedCommandActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      robot_calibration_msgs::GripperLedCommandGoal goal;

    GripperLedCommandActionGoal():
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

    const char * getType(){ return "robot_calibration_msgs/GripperLedCommandActionGoal"; };
    const char * getMD5(){ return "a6f43a5345c808a3839fc4ee405e8697"; };

  };

}
#endif