#ifndef _ROS_jsk_recognition_msgs_VectorArray_h
#define _ROS_jsk_recognition_msgs_VectorArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class VectorArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      int32_t vector_dim;
      uint8_t data_length;
      float st_data;
      float * data;

    VectorArray():
      header(),
      vector_dim(0),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_vector_dim;
      u_vector_dim.real = this->vector_dim;
      *(outbuffer + offset + 0) = (u_vector_dim.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vector_dim.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vector_dim.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vector_dim.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vector_dim);
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_vector_dim;
      u_vector_dim.base = 0;
      u_vector_dim.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vector_dim.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vector_dim.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vector_dim.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vector_dim = u_vector_dim.real;
      offset += sizeof(this->vector_dim);
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (float*)realloc(this->data, data_lengthT * sizeof(float));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_data));
        memcpy( &(this->data[i]), &(this->st_data), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/VectorArray"; };
    const char * getMD5(){ return "5755776409eb8318e94c95cd52de2b69"; };

  };

}
#endif