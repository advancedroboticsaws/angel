#ifndef _ROS_fetch_driver_msgs_JointState_h
#define _ROS_fetch_driver_msgs_JointState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fetch_driver_msgs
{

  class JointState : public ros::Msg
  {
    public:
      const char* name;
      uint8_t control_mode;
      float desired_position;
      float desired_velocity;
      float desired_effort;
      float position;
      float velocity;
      float effort;

    JointState():
      name(""),
      control_mode(0),
      desired_position(0),
      desired_velocity(0),
      desired_effort(0),
      position(0),
      velocity(0),
      effort(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->control_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_mode);
      union {
        float real;
        uint32_t base;
      } u_desired_position;
      u_desired_position.real = this->desired_position;
      *(outbuffer + offset + 0) = (u_desired_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_desired_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_desired_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_desired_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->desired_position);
      union {
        float real;
        uint32_t base;
      } u_desired_velocity;
      u_desired_velocity.real = this->desired_velocity;
      *(outbuffer + offset + 0) = (u_desired_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_desired_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_desired_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_desired_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->desired_velocity);
      union {
        float real;
        uint32_t base;
      } u_desired_effort;
      u_desired_effort.real = this->desired_effort;
      *(outbuffer + offset + 0) = (u_desired_effort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_desired_effort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_desired_effort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_desired_effort.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->desired_effort);
      union {
        float real;
        uint32_t base;
      } u_position;
      u_position.real = this->position;
      *(outbuffer + offset + 0) = (u_position.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_position.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_position.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_position.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.real = this->velocity;
      *(outbuffer + offset + 0) = (u_velocity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_effort;
      u_effort.real = this->effort;
      *(outbuffer + offset + 0) = (u_effort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_effort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_effort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_effort.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      this->control_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control_mode);
      union {
        float real;
        uint32_t base;
      } u_desired_position;
      u_desired_position.base = 0;
      u_desired_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_desired_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_desired_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_desired_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->desired_position = u_desired_position.real;
      offset += sizeof(this->desired_position);
      union {
        float real;
        uint32_t base;
      } u_desired_velocity;
      u_desired_velocity.base = 0;
      u_desired_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_desired_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_desired_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_desired_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->desired_velocity = u_desired_velocity.real;
      offset += sizeof(this->desired_velocity);
      union {
        float real;
        uint32_t base;
      } u_desired_effort;
      u_desired_effort.base = 0;
      u_desired_effort.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_desired_effort.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_desired_effort.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_desired_effort.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->desired_effort = u_desired_effort.real;
      offset += sizeof(this->desired_effort);
      union {
        float real;
        uint32_t base;
      } u_position;
      u_position.base = 0;
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->position = u_position.real;
      offset += sizeof(this->position);
      union {
        float real;
        uint32_t base;
      } u_velocity;
      u_velocity.base = 0;
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity = u_velocity.real;
      offset += sizeof(this->velocity);
      union {
        float real;
        uint32_t base;
      } u_effort;
      u_effort.base = 0;
      u_effort.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_effort.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_effort.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_effort.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->effort = u_effort.real;
      offset += sizeof(this->effort);
     return offset;
    }

    const char * getType(){ return "fetch_driver_msgs/JointState"; };
    const char * getMD5(){ return "20cf035aa8e1812b6fd2af53c6aa178a"; };

  };

}
#endif