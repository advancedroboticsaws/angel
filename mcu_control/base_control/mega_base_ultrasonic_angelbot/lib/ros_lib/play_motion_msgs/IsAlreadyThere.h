#ifndef _ROS_SERVICE_IsAlreadyThere_h
#define _ROS_SERVICE_IsAlreadyThere_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace play_motion_msgs
{

static const char ISALREADYTHERE[] = "play_motion_msgs/IsAlreadyThere";

  class IsAlreadyThereRequest : public ros::Msg
  {
    public:
      const char* motion_name;
      float tolerance;

    IsAlreadyThereRequest():
      motion_name(""),
      tolerance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_motion_name = strlen(this->motion_name);
      memcpy(outbuffer + offset, &length_motion_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->motion_name, length_motion_name);
      offset += length_motion_name;
      union {
        float real;
        uint32_t base;
      } u_tolerance;
      u_tolerance.real = this->tolerance;
      *(outbuffer + offset + 0) = (u_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tolerance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tolerance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_motion_name;
      memcpy(&length_motion_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_motion_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_motion_name-1]=0;
      this->motion_name = (char *)(inbuffer + offset-1);
      offset += length_motion_name;
      union {
        float real;
        uint32_t base;
      } u_tolerance;
      u_tolerance.base = 0;
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tolerance = u_tolerance.real;
      offset += sizeof(this->tolerance);
     return offset;
    }

    const char * getType(){ return ISALREADYTHERE; };
    const char * getMD5(){ return "99caf0c415b632c6336d7371da3ff931"; };

  };

  class IsAlreadyThereResponse : public ros::Msg
  {
    public:
      bool already_there;

    IsAlreadyThereResponse():
      already_there(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_already_there;
      u_already_there.real = this->already_there;
      *(outbuffer + offset + 0) = (u_already_there.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->already_there);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_already_there;
      u_already_there.base = 0;
      u_already_there.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->already_there = u_already_there.real;
      offset += sizeof(this->already_there);
     return offset;
    }

    const char * getType(){ return ISALREADYTHERE; };
    const char * getMD5(){ return "ab529bf62f4cfd6bb0a78ed51c04fcba"; };

  };

  class IsAlreadyThere {
    public:
    typedef IsAlreadyThereRequest Request;
    typedef IsAlreadyThereResponse Response;
  };

}
#endif
