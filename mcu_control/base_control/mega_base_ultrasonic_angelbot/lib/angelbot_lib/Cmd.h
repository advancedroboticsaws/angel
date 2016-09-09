#ifndef _ROS_angelbot_Cmd_h
#define _ROS_angelbot_Cmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace angelbot
{

  class Cmd : public ros::Msg
  {
    public:
      float angle;
      float duration;
      bool driverstate;

    Cmd():
      angle(0),
      duration(0),
      driverstate(0)
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
      union {
        float real;
        uint32_t base;
      } u_duration;
      u_duration.real = this->duration;
      *(outbuffer + offset + 0) = (u_duration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_duration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_duration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_duration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration);
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
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      union {
        float real;
        uint32_t base;
      } u_duration;
      u_duration.base = 0;
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_duration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->duration = u_duration.real;
      offset += sizeof(this->duration);
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

    const char * getType(){ return "angelbot/Cmd"; };
    const char * getMD5(){ return "1fc188ab0affdb24340dfd740cc8ab00"; };

  };

}
#endif
