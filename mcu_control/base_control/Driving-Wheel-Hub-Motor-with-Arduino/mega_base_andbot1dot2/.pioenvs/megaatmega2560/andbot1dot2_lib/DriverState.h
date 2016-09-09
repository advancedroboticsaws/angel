#ifndef _ROS_SERVICE_DriverState_h
#define _ROS_SERVICE_DriverState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace andbot1dot2
{

static const char DRIVERSTATE[] = "andbot1dot2/DriverState";

  class DriverStateRequest : public ros::Msg
  {
    public:
      bool driverstate;

    DriverStateRequest():
      driverstate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
        bool real;
        uint8_t base;
      } u_driverstate;
      u_driverstate.base = 0;
      u_driverstate.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driverstate = u_driverstate.real;
      offset += sizeof(this->driverstate);
     return offset;
    }

    const char * getType(){ return DRIVERSTATE; };
    const char * getMD5(){ return "8ae741de3d7c1161a9efa81aa2904249"; };

  };

  class DriverStateResponse : public ros::Msg
  {
    public:
      bool driverstate;

    DriverStateResponse():
      driverstate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
        bool real;
        uint8_t base;
      } u_driverstate;
      u_driverstate.base = 0;
      u_driverstate.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->driverstate = u_driverstate.real;
      offset += sizeof(this->driverstate);
     return offset;
    }

    const char * getType(){ return DRIVERSTATE; };
    const char * getMD5(){ return "8ae741de3d7c1161a9efa81aa2904249"; };

  };

  class DriverState {
    public:
    typedef DriverStateRequest Request;
    typedef DriverStateResponse Response;
  };

}
#endif
