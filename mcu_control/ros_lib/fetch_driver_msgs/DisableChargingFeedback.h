#ifndef _ROS_fetch_driver_msgs_DisableChargingFeedback_h
#define _ROS_fetch_driver_msgs_DisableChargingFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fetch_driver_msgs
{

  class DisableChargingFeedback : public ros::Msg
  {
    public:

    DisableChargingFeedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "fetch_driver_msgs/DisableChargingFeedback"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif