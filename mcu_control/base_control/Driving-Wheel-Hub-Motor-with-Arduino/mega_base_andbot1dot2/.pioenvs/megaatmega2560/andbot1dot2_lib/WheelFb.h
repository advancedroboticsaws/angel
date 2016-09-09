#ifndef _ROS_andbot1dot2_WheelFb_h
#define _ROS_andbot1dot2_WheelFb_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace andbot1dot2
{

  class WheelFb : public ros::Msg
  {
    public:
      float speed1;
      uint16_t current1;
      float speed2;
      uint16_t current2;

    WheelFb():
      speed1(0),
      current1(0),
      speed2(0),
      current2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_speed1;
      u_speed1.real = this->speed1;
      *(outbuffer + offset + 0) = (u_speed1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed1);
      *(outbuffer + offset + 0) = (this->current1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current1);
      union {
        float real;
        uint32_t base;
      } u_speed2;
      u_speed2.real = this->speed2;
      *(outbuffer + offset + 0) = (u_speed2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed2);
      *(outbuffer + offset + 0) = (this->current2 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current2 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_speed1;
      u_speed1.base = 0;
      u_speed1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed1 = u_speed1.real;
      offset += sizeof(this->speed1);
      this->current1 =  ((uint16_t) (*(inbuffer + offset)));
      this->current1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current1);
      union {
        float real;
        uint32_t base;
      } u_speed2;
      u_speed2.base = 0;
      u_speed2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed2 = u_speed2.real;
      offset += sizeof(this->speed2);
      this->current2 =  ((uint16_t) (*(inbuffer + offset)));
      this->current2 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current2);
     return offset;
    }

    const char * getType(){ return "andbot1dot2/WheelFb"; };
    const char * getMD5(){ return "cb918176b5631dae1371ac2bcdcb4261"; };

  };

}
#endif