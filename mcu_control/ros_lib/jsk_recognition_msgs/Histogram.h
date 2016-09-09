#ifndef _ROS_jsk_recognition_msgs_Histogram_h
#define _ROS_jsk_recognition_msgs_Histogram_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class Histogram : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t histogram_length;
      float st_histogram;
      float * histogram;

    Histogram():
      header(),
      histogram_length(0), histogram(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = histogram_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < histogram_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->histogram[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t histogram_lengthT = *(inbuffer + offset++);
      if(histogram_lengthT > histogram_length)
        this->histogram = (float*)realloc(this->histogram, histogram_lengthT * sizeof(float));
      offset += 3;
      histogram_length = histogram_lengthT;
      for( uint8_t i = 0; i < histogram_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_histogram));
        memcpy( &(this->histogram[i]), &(this->st_histogram), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/Histogram"; };
    const char * getMD5(){ return "376372f016c22c39ab7ee6b6bdd0f10a"; };

  };

}
#endif