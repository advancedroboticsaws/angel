#ifndef _ROS_jsk_recognition_msgs_ColorHistogram_h
#define _ROS_jsk_recognition_msgs_ColorHistogram_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class ColorHistogram : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t histogram_length;
      float st_histogram;
      float * histogram;

    ColorHistogram():
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
      union {
        float real;
        uint32_t base;
      } u_histogrami;
      u_histogrami.real = this->histogram[i];
      *(outbuffer + offset + 0) = (u_histogrami.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_histogrami.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_histogrami.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_histogrami.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->histogram[i]);
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
      union {
        float real;
        uint32_t base;
      } u_st_histogram;
      u_st_histogram.base = 0;
      u_st_histogram.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_histogram.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_histogram.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_histogram.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_histogram = u_st_histogram.real;
      offset += sizeof(this->st_histogram);
        memcpy( &(this->histogram[i]), &(this->st_histogram), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ColorHistogram"; };
    const char * getMD5(){ return "5b08641478fdecd8720ba08b36fce2aa"; };

  };

}
#endif