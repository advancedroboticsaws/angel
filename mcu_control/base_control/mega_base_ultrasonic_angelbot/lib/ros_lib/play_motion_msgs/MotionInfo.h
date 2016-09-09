#ifndef _ROS_play_motion_msgs_MotionInfo_h
#define _ROS_play_motion_msgs_MotionInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace play_motion_msgs
{

  class MotionInfo : public ros::Msg
  {
    public:
      const char* name;
      uint8_t joints_length;
      char* st_joints;
      char* * joints;
      ros::Duration duration;

    MotionInfo():
      name(""),
      joints_length(0), joints(NULL),
      duration()
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
      *(outbuffer + offset++) = joints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joints_length; i++){
      uint32_t length_jointsi = strlen(this->joints[i]);
      memcpy(outbuffer + offset, &length_jointsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joints[i], length_jointsi);
      offset += length_jointsi;
      }
      *(outbuffer + offset + 0) = (this->duration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.sec);
      *(outbuffer + offset + 0) = (this->duration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->duration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->duration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->duration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duration.nsec);
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
      uint8_t joints_lengthT = *(inbuffer + offset++);
      if(joints_lengthT > joints_length)
        this->joints = (char**)realloc(this->joints, joints_lengthT * sizeof(char*));
      offset += 3;
      joints_length = joints_lengthT;
      for( uint8_t i = 0; i < joints_length; i++){
      uint32_t length_st_joints;
      memcpy(&length_st_joints, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joints; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joints-1]=0;
      this->st_joints = (char *)(inbuffer + offset-1);
      offset += length_st_joints;
        memcpy( &(this->joints[i]), &(this->st_joints), sizeof(char*));
      }
      this->duration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.sec);
      this->duration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->duration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->duration.nsec);
     return offset;
    }

    const char * getType(){ return "play_motion_msgs/MotionInfo"; };
    const char * getMD5(){ return "12fa5a438744c4ad98a7da64c759d1bd"; };

  };

}
#endif