#ifndef _ROS_ml_classifiers_ClassDataPoint_h
#define _ROS_ml_classifiers_ClassDataPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ml_classifiers
{

  class ClassDataPoint : public ros::Msg
  {
    public:
      const char* target_class;
      uint8_t point_length;
      float st_point;
      float * point;

    ClassDataPoint():
      target_class(""),
      point_length(0), point(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_target_class = strlen(this->target_class);
      memcpy(outbuffer + offset, &length_target_class, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->target_class, length_target_class);
      offset += length_target_class;
      *(outbuffer + offset++) = point_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < point_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->point[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_target_class;
      memcpy(&length_target_class, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_target_class; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_target_class-1]=0;
      this->target_class = (char *)(inbuffer + offset-1);
      offset += length_target_class;
      uint8_t point_lengthT = *(inbuffer + offset++);
      if(point_lengthT > point_length)
        this->point = (float*)realloc(this->point, point_lengthT * sizeof(float));
      offset += 3;
      point_length = point_lengthT;
      for( uint8_t i = 0; i < point_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_point));
        memcpy( &(this->point[i]), &(this->st_point), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "ml_classifiers/ClassDataPoint"; };
    const char * getMD5(){ return "46bea2d2ef979a71ef0bfa470e5978ff"; };

  };

}
#endif