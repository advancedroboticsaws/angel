#ifndef _ROS_fetch_driver_msgs_DisableChargingActionGoal_h
#define _ROS_fetch_driver_msgs_DisableChargingActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "fetch_driver_msgs/DisableChargingGoal.h"

namespace fetch_driver_msgs
{

  class DisableChargingActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      fetch_driver_msgs::DisableChargingGoal goal;

    DisableChargingActionGoal():
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

    const char * getType(){ return "fetch_driver_msgs/DisableChargingActionGoal"; };
    const char * getMD5(){ return "2cdef171810817cf95b4cd420433b17f"; };

  };

}
#endif