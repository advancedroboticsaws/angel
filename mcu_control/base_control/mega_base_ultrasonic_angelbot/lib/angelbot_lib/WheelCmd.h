#ifndef _ROS_angelbot_WheelCmd_h
#define _ROS_angelbot_WheelCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace angelbot
{

  class WheelCmd : public ros::Msg
  {
    public:
      float speed1;
      float speed2;
      bool driverstate;

    WheelCmd():
      speed1(0),
      speed2(0),
      driverstate(0)
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
      union {
        bool real;
        uint8_t base;
      } u_driverstate;
      u_driverstate.real = this->driverstate;
      *(outbuffer + offset + 0) = (u_driverstate.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driverstate);
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
      union {
        bool real;
        uint8_t base;
      } u_driverstate;
      u_driverstate.base = 0;
      u_driverstate.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driverstate = u_driverstate.real;
      offset += sizeof(this->driverstate);
     return offset;
    }

    const char * getType(){ return "angelbot/WheelCmd"; };
    const char * getMD5(){ return "173609e82190eaee99c6e251573e54e9"; };

  };

}
#endif
