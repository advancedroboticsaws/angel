#ifndef _ROS_jsk_footstep_msgs_FootstepArray_h
#define _ROS_jsk_footstep_msgs_FootstepArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_footstep_msgs/Footstep.h"

namespace jsk_footstep_msgs
{

  class FootstepArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t footsteps_length;
      jsk_footstep_msgs::Footstep st_footsteps;
      jsk_footstep_msgs::Footstep * footsteps;

    FootstepArray():
      header(),
      footsteps_length(0), footsteps(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = footsteps_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < footsteps_length; i++){
      offset += this->footsteps[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t footsteps_lengthT = *(inbuffer + offset++);
      if(footsteps_lengthT > footsteps_length)
        this->footsteps = (jsk_footstep_msgs::Footstep*)realloc(this->footsteps, footsteps_lengthT * sizeof(jsk_footstep_msgs::Footstep));
      offset += 3;
      footsteps_length = footsteps_lengthT;
      for( uint8_t i = 0; i < footsteps_length; i++){
      offset += this->st_footsteps.deserialize(inbuffer + offset);
        memcpy( &(this->footsteps[i]), &(this->st_footsteps), sizeof(jsk_footstep_msgs::Footstep));
      }
     return offset;
    }

    const char * getType(){ return "jsk_footstep_msgs/FootstepArray"; };
    const char * getMD5(){ return "0c6ec8f3a6945781372f53ae76659be3"; };

  };

}
#endif