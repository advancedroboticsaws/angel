#ifndef _ROS_SERVICE_DeviceCheck_h
#define _ROS_SERVICE_DeviceCheck_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace angelbot
{

static const char DEVICECHECK[] = "angelbot/DeviceCheck";

  class DeviceCheckRequest : public ros::Msg
  {
    public:

    DeviceCheckRequest()
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

    const char * getType(){ return DEVICECHECK; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DeviceCheckResponse : public ros::Msg
  {
    public:
      bool id1;
      bool id2;
      bool id3;
      bool id4;
      bool id5;
      bool id6;
      bool id7;
      bool id8;
      bool id9;
      bool id10;

    DeviceCheckResponse():
      id1(0),
      id2(0),
      id3(0),
      id4(0),
      id5(0),
      id6(0),
      id7(0),
      id8(0),
      id9(0),
      id10(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_id1;
      u_id1.real = this->id1;
      *(outbuffer + offset + 0) = (u_id1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id1);
      union {
        bool real;
        uint8_t base;
      } u_id2;
      u_id2.real = this->id2;
      *(outbuffer + offset + 0) = (u_id2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id2);
      union {
        bool real;
        uint8_t base;
      } u_id3;
      u_id3.real = this->id3;
      *(outbuffer + offset + 0) = (u_id3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id3);
      union {
        bool real;
        uint8_t base;
      } u_id4;
      u_id4.real = this->id4;
      *(outbuffer + offset + 0) = (u_id4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id4);
      union {
        bool real;
        uint8_t base;
      } u_id5;
      u_id5.real = this->id5;
      *(outbuffer + offset + 0) = (u_id5.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id5);
      union {
        bool real;
        uint8_t base;
      } u_id6;
      u_id6.real = this->id6;
      *(outbuffer + offset + 0) = (u_id6.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id6);
      union {
        bool real;
        uint8_t base;
      } u_id7;
      u_id7.real = this->id7;
      *(outbuffer + offset + 0) = (u_id7.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id7);
      union {
        bool real;
        uint8_t base;
      } u_id8;
      u_id8.real = this->id8;
      *(outbuffer + offset + 0) = (u_id8.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id8);
      union {
        bool real;
        uint8_t base;
      } u_id9;
      u_id9.real = this->id9;
      *(outbuffer + offset + 0) = (u_id9.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id9);
      union {
        bool real;
        uint8_t base;
      } u_id10;
      u_id10.real = this->id10;
      *(outbuffer + offset + 0) = (u_id10.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id10);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_id1;
      u_id1.base = 0;
      u_id1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id1 = u_id1.real;
      offset += sizeof(this->id1);
      union {
        bool real;
        uint8_t base;
      } u_id2;
      u_id2.base = 0;
      u_id2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id2 = u_id2.real;
      offset += sizeof(this->id2);
      union {
        bool real;
        uint8_t base;
      } u_id3;
      u_id3.base = 0;
      u_id3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id3 = u_id3.real;
      offset += sizeof(this->id3);
      union {
        bool real;
        uint8_t base;
      } u_id4;
      u_id4.base = 0;
      u_id4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id4 = u_id4.real;
      offset += sizeof(this->id4);
      union {
        bool real;
        uint8_t base;
      } u_id5;
      u_id5.base = 0;
      u_id5.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id5 = u_id5.real;
      offset += sizeof(this->id5);
      union {
        bool real;
        uint8_t base;
      } u_id6;
      u_id6.base = 0;
      u_id6.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id6 = u_id6.real;
      offset += sizeof(this->id6);
      union {
        bool real;
        uint8_t base;
      } u_id7;
      u_id7.base = 0;
      u_id7.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id7 = u_id7.real;
      offset += sizeof(this->id7);
      union {
        bool real;
        uint8_t base;
      } u_id8;
      u_id8.base = 0;
      u_id8.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id8 = u_id8.real;
      offset += sizeof(this->id8);
      union {
        bool real;
        uint8_t base;
      } u_id9;
      u_id9.base = 0;
      u_id9.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id9 = u_id9.real;
      offset += sizeof(this->id9);
      union {
        bool real;
        uint8_t base;
      } u_id10;
      u_id10.base = 0;
      u_id10.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id10 = u_id10.real;
      offset += sizeof(this->id10);
     return offset;
    }

    const char * getType(){ return DEVICECHECK; };
    const char * getMD5(){ return "5275e5b287ae93006574ee9220d40c7e"; };

  };

  class DeviceCheck {
    public:
    typedef DeviceCheckRequest Request;
    typedef DeviceCheckResponse Response;
  };

}
#endif
