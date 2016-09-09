#ifndef _ROS_jsk_recognition_msgs_LineArray_h
#define _ROS_jsk_recognition_msgs_LineArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/Line.h"

namespace jsk_recognition_msgs
{

  class LineArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t lines_length;
      jsk_recognition_msgs::Line st_lines;
      jsk_recognition_msgs::Line * lines;

    LineArray():
      header(),
      lines_length(0), lines(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = lines_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < lines_length; i++){
      offset += this->lines[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t lines_lengthT = *(inbuffer + offset++);
      if(lines_lengthT > lines_length)
        this->lines = (jsk_recognition_msgs::Line*)realloc(this->lines, lines_lengthT * sizeof(jsk_recognition_msgs::Line));
      offset += 3;
      lines_length = lines_lengthT;
      for( uint8_t i = 0; i < lines_length; i++){
      offset += this->st_lines.deserialize(inbuffer + offset);
        memcpy( &(this->lines[i]), &(this->st_lines), sizeof(jsk_recognition_msgs::Line));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/LineArray"; };
    const char * getMD5(){ return "1571346a320fd11e0b7dc11a90a72ddf"; };

  };

}
#endif