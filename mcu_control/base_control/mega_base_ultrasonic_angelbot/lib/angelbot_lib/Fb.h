#ifndef _ROS_angelbot_Fb_h
#define _ROS_angelbot_Fb_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace angelbot
{

  class Fb : public ros::Msg
  {
    public:
      float angle;
      uint16_t current;
      bool hall1;
      bool hall2;

    Fb():
      angle(0),
      current(0),
      hall1(0),
      hall2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      *(outbuffer + offset + 0) = (this->current >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current);
      union {
        bool real;
        uint8_t base;
      } u_hall1;
      u_hall1.real = this->hall1;
      *(outbuffer + offset + 0) = (u_hall1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hall1);
      union {
        bool real;
        uint8_t base;
      } u_hall2;
      u_hall2.real = this->hall2;
      *(outbuffer + offset + 0) = (u_hall2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hall2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      this->current =  ((uint16_t) (*(inbuffer + offset)));
      this->current |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current);
      union {
        bool real;
        uint8_t base;
      } u_hall1;
      u_hall1.base = 0;
      u_hall1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hall1 = u_hall1.real;
      offset += sizeof(this->hall1);
      union {
        bool real;
        uint8_t base;
      } u_hall2;
      u_hall2.base = 0;
      u_hall2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hall2 = u_hall2.real;
      offset += sizeof(this->hall2);
     return offset;
    }

    const char * getType(){ return "angelbot/Fb"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
