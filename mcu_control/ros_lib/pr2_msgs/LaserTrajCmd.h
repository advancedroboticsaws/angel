#ifndef _ROS_pr2_msgs_LaserTrajCmd_h
#define _ROS_pr2_msgs_LaserTrajCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ros/duration.h"

namespace pr2_msgs
{

  class LaserTrajCmd : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* profile;
      uint8_t position_length;
      float st_position;
      float * position;
      uint8_t time_from_start_length;
      ros::Duration st_time_from_start;
      ros::Duration * time_from_start;
      float max_velocity;
      float max_acceleration;

    LaserTrajCmd():
      header(),
      profile(""),
      position_length(0), position(NULL),
      time_from_start_length(0), time_from_start(NULL),
      max_velocity(0),
      max_acceleration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_profile = strlen(this->profile);
      memcpy(outbuffer + offset, &length_profile, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->profile, length_profile);
      offset += length_profile;
      *(outbuffer + offset++) = position_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < position_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->position[i]);
      }
      *(outbuffer + offset++) = time_from_start_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < time_from_start_length; i++){
      *(outbuffer + offset + 0) = (this->time_from_start[i].sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start[i].sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start[i].sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start[i].sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start[i].sec);
      *(outbuffer + offset + 0) = (this->time_from_start[i].nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start[i].nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start[i].nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start[i].nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start[i].nsec);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->max_velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_acceleration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_profile;
      memcpy(&length_profile, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_profile; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_profile-1]=0;
      this->profile = (char *)(inbuffer + offset-1);
      offset += length_profile;
      uint8_t position_lengthT = *(inbuffer + offset++);
      if(position_lengthT > position_length)
        this->position = (float*)realloc(this->position, position_lengthT * sizeof(float));
      offset += 3;
      position_length = position_lengthT;
      for( uint8_t i = 0; i < position_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_position));
        memcpy( &(this->position[i]), &(this->st_position), sizeof(float));
      }
      uint8_t time_from_start_lengthT = *(inbuffer + offset++);
      if(time_from_start_lengthT > time_from_start_length)
        this->time_from_start = (ros::Duration*)realloc(this->time_from_start, time_from_start_lengthT * sizeof(ros::Duration));
      offset += 3;
      time_from_start_length = time_from_start_lengthT;
      for( uint8_t i = 0; i < time_from_start_length; i++){
      this->st_time_from_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_time_from_start.sec);
      this->st_time_from_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_time_from_start.nsec);
        memcpy( &(this->time_from_start[i]), &(this->st_time_from_start), sizeof(ros::Duration));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_acceleration));
     return offset;
    }

    const char * getType(){ return "pr2_msgs/LaserTrajCmd"; };
    const char * getMD5(){ return "68a1665e9079049dce55a0384cb2e9b5"; };

  };

}
#endif