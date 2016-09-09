#ifndef _ROS_jsk_recognition_msgs_WeightedPoseArray_h
#define _ROS_jsk_recognition_msgs_WeightedPoseArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseArray.h"

namespace jsk_recognition_msgs
{

  class WeightedPoseArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t weights_length;
      float st_weights;
      float * weights;
      geometry_msgs::PoseArray poses;

    WeightedPoseArray():
      header(),
      weights_length(0), weights(NULL),
      poses()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = weights_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < weights_length; i++){
      union {
        float real;
        uint32_t base;
      } u_weightsi;
      u_weightsi.real = this->weights[i];
      *(outbuffer + offset + 0) = (u_weightsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_weightsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_weightsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_weightsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->weights[i]);
      }
      offset += this->poses.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t weights_lengthT = *(inbuffer + offset++);
      if(weights_lengthT > weights_length)
        this->weights = (float*)realloc(this->weights, weights_lengthT * sizeof(float));
      offset += 3;
      weights_length = weights_lengthT;
      for( uint8_t i = 0; i < weights_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_weights;
      u_st_weights.base = 0;
      u_st_weights.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_weights.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_weights.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_weights.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_weights = u_st_weights.real;
      offset += sizeof(this->st_weights);
        memcpy( &(this->weights[i]), &(this->st_weights), sizeof(float));
      }
      offset += this->poses.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/WeightedPoseArray"; };
    const char * getMD5(){ return "40f180494a75a8797b1c2ba81b2cb4c0"; };

  };

}
#endif