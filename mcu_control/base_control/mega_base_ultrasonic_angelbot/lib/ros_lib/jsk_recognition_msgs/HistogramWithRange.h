#ifndef _ROS_jsk_recognition_msgs_HistogramWithRange_h
#define _ROS_jsk_recognition_msgs_HistogramWithRange_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/HistogramWithRangeBin.h"

namespace jsk_recognition_msgs
{

  class HistogramWithRange : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t bins_length;
      jsk_recognition_msgs::HistogramWithRangeBin st_bins;
      jsk_recognition_msgs::HistogramWithRangeBin * bins;

    HistogramWithRange():
      header(),
      bins_length(0), bins(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = bins_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < bins_length; i++){
      offset += this->bins[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t bins_lengthT = *(inbuffer + offset++);
      if(bins_lengthT > bins_length)
        this->bins = (jsk_recognition_msgs::HistogramWithRangeBin*)realloc(this->bins, bins_lengthT * sizeof(jsk_recognition_msgs::HistogramWithRangeBin));
      offset += 3;
      bins_length = bins_lengthT;
      for( uint8_t i = 0; i < bins_length; i++){
      offset += this->st_bins.deserialize(inbuffer + offset);
        memcpy( &(this->bins[i]), &(this->st_bins), sizeof(jsk_recognition_msgs::HistogramWithRangeBin));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/HistogramWithRange"; };
    const char * getMD5(){ return "aa922a22cbdcbdcc1146f30df5b605b8"; };

  };

}
#endif