#ifndef _ROS_jsk_recognition_msgs_ColorHistogramArray_h
#define _ROS_jsk_recognition_msgs_ColorHistogramArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/ColorHistogram.h"

namespace jsk_recognition_msgs
{

  class ColorHistogramArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t histograms_length;
      jsk_recognition_msgs::ColorHistogram st_histograms;
      jsk_recognition_msgs::ColorHistogram * histograms;

    ColorHistogramArray():
      header(),
      histograms_length(0), histograms(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = histograms_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < histograms_length; i++){
      offset += this->histograms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t histograms_lengthT = *(inbuffer + offset++);
      if(histograms_lengthT > histograms_length)
        this->histograms = (jsk_recognition_msgs::ColorHistogram*)realloc(this->histograms, histograms_lengthT * sizeof(jsk_recognition_msgs::ColorHistogram));
      offset += 3;
      histograms_length = histograms_lengthT;
      for( uint8_t i = 0; i < histograms_length; i++){
      offset += this->st_histograms.deserialize(inbuffer + offset);
        memcpy( &(this->histograms[i]), &(this->st_histograms), sizeof(jsk_recognition_msgs::ColorHistogram));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ColorHistogramArray"; };
    const char * getMD5(){ return "3bcc7f05c5520f311047096d5530e715"; };

  };

}
#endif