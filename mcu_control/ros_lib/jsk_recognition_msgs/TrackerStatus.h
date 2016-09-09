#ifndef _ROS_jsk_recognition_msgs_TrackerStatus_h
#define _ROS_jsk_recognition_msgs_TrackerStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class TrackerStatus : public ros::Msg
  {
    public:
      std_msgs::Header header;
      bool is_tracking;

    TrackerStatus():
      header(),
      is_tracking(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_tracking;
      u_is_tracking.real = this->is_tracking;
      *(outbuffer + offset + 0) = (u_is_tracking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_tracking);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_tracking;
      u_is_tracking.base = 0;
      u_is_tracking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_tracking = u_is_tracking.real;
      offset += sizeof(this->is_tracking);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/TrackerStatus"; };
    const char * getMD5(){ return "78e8f06a6b728df052dd181bfcf6c26e"; };

  };

}
#endif