#ifndef _ROS_jsk_recognition_msgs_Circle2D_h
#define _ROS_jsk_recognition_msgs_Circle2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class Circle2D : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float radius;
      float x;
      float y;

    Circle2D():
      header(),
      radius(0),
      x(0),
      y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->radius);
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->radius));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/Circle2D"; };
    const char * getMD5(){ return "2337fe90a715387bfdc3cf4b7fa2391e"; };

  };

}
#endif