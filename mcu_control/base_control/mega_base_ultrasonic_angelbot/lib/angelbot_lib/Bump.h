#ifndef _ROS_angelbot_Bump_h
#define _ROS_angelbot_Bump_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace angelbot
{

  class Bump : public ros::Msg
  {
    public:
      bool bump1;
      bool bump2;
      bool bump3;
      bool bump4;
      bool cliff1;
      bool cliff2;
      bool cliff3;
      bool cliff4;

    Bump():
      bump1(0),
      bump2(0),
      bump3(0),
      bump4(0),
      cliff1(0),
      cliff2(0),
      cliff3(0),
      cliff4(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_bump1;
      u_bump1.real = this->bump1;
      *(outbuffer + offset + 0) = (u_bump1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bump1);
      union {
        bool real;
        uint8_t base;
      } u_bump2;
      u_bump2.real = this->bump2;
      *(outbuffer + offset + 0) = (u_bump2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bump2);
      union {
        bool real;
        uint8_t base;
      } u_bump3;
      u_bump3.real = this->bump3;
      *(outbuffer + offset + 0) = (u_bump3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bump3);
      union {
        bool real;
        uint8_t base;
      } u_bump4;
      u_bump4.real = this->bump4;
      *(outbuffer + offset + 0) = (u_bump4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bump4);
      union {
        bool real;
        uint8_t base;
      } u_cliff1;
      u_cliff1.real = this->cliff1;
      *(outbuffer + offset + 0) = (u_cliff1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cliff1);
      union {
        bool real;
        uint8_t base;
      } u_cliff2;
      u_cliff2.real = this->cliff2;
      *(outbuffer + offset + 0) = (u_cliff2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cliff2);
      union {
        bool real;
        uint8_t base;
      } u_cliff3;
      u_cliff3.real = this->cliff3;
      *(outbuffer + offset + 0) = (u_cliff3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cliff3);
      union {
        bool real;
        uint8_t base;
      } u_cliff4;
      u_cliff4.real = this->cliff4;
      *(outbuffer + offset + 0) = (u_cliff4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cliff4);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_bump1;
      u_bump1.base = 0;
      u_bump1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->bump1 = u_bump1.real;
      offset += sizeof(this->bump1);
      union {
        bool real;
        uint8_t base;
      } u_bump2;
      u_bump2.base = 0;
      u_bump2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->bump2 = u_bump2.real;
      offset += sizeof(this->bump2);
      union {
        bool real;
        uint8_t base;
      } u_bump3;
      u_bump3.base = 0;
      u_bump3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->bump3 = u_bump3.real;
      offset += sizeof(this->bump3);
      union {
        bool real;
        uint8_t base;
      } u_bump4;
      u_bump4.base = 0;
      u_bump4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->bump4 = u_bump4.real;
      offset += sizeof(this->bump4);
      union {
        bool real;
        uint8_t base;
      } u_cliff1;
      u_cliff1.base = 0;
      u_cliff1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cliff1 = u_cliff1.real;
      offset += sizeof(this->cliff1);
      union {
        bool real;
        uint8_t base;
      } u_cliff2;
      u_cliff2.base = 0;
      u_cliff2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cliff2 = u_cliff2.real;
      offset += sizeof(this->cliff2);
      union {
        bool real;
        uint8_t base;
      } u_cliff3;
      u_cliff3.base = 0;
      u_cliff3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cliff3 = u_cliff3.real;
      offset += sizeof(this->cliff3);
      union {
        bool real;
        uint8_t base;
      } u_cliff4;
      u_cliff4.base = 0;
      u_cliff4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->cliff4 = u_cliff4.real;
      offset += sizeof(this->cliff4);
     return offset;
    }

    const char * getType(){ return "angelbot/Bump"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
