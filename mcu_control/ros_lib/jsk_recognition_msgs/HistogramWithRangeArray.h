#ifndef _ROS_jsk_recognition_msgs_HistogramWithRangeArray_h
#define _ROS_jsk_recognition_msgs_HistogramWithRangeArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/HistogramWithRange.h"

namespace jsk_recognition_msgs
{

  class HistogramWithRangeArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t histograms_length;
      jsk_recognition_msgs::HistogramWithRange st_histograms;
      jsk_recognition_msgs::HistogramWithRange * histograms;

    HistogramWithRangeArray():
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
        this->histograms = (jsk_recognition_msgs::HistogramWithRange*)realloc(this->histograms, histograms_lengthT * sizeof(jsk_recognition_msgs::HistogramWithRange));
      offset += 3;
      histograms_length = histograms_lengthT;
      for( uint8_t i = 0; i < histograms_length; i++){
      offset += this->st_histograms.deserialize(inbuffer + offset);
        memcpy( &(this->histograms[i]), &(this->st_histograms), sizeof(jsk_recognition_msgs::HistogramWithRange));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/HistogramWithRangeArray"; };
    const char * getMD5(){ return "2622b1b7ae84f154677cf4c0d3a398c7"; };

  };

}
#endif