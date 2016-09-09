#ifndef _ROS_fetch_driver_msgs_DisableChargingActionResult_h
#define _ROS_fetch_driver_msgs_DisableChargingActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "fetch_driver_msgs/DisableChargingResult.h"

namespace fetch_driver_msgs
{

  class DisableChargingActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      fetch_driver_msgs::DisableChargingResult result;

    DisableChargingActionResult():
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

    const char * getType(){ return "fetch_driver_msgs/DisableChargingActionResult"; };
    const char * getMD5(){ return "303f1e5dc2c6adb3e46cf4339a1cdb1d"; };

  };

}
#endif