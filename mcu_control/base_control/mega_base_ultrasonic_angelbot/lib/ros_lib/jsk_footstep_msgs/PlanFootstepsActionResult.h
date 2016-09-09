#ifndef _ROS_jsk_footstep_msgs_PlanFootstepsActionResult_h
#define _ROS_jsk_footstep_msgs_PlanFootstepsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "jsk_footstep_msgs/PlanFootstepsResult.h"

namespace jsk_footstep_msgs
{

  class PlanFootstepsActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      jsk_footstep_msgs::PlanFootstepsResult result;

    PlanFootstepsActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_footstep_msgs/PlanFootstepsActionResult"; };
    const char * getMD5(){ return "4c67fe7e3bfd56f2cae1d481636e8720"; };

  };

}
#endif