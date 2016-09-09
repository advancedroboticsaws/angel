#ifndef _ROS_jsk_recognition_msgs_BoundingBoxArray_h
#define _ROS_jsk_recognition_msgs_BoundingBoxArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/BoundingBox.h"

namespace jsk_recognition_msgs
{

  class BoundingBoxArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t boxes_length;
      jsk_recognition_msgs::BoundingBox st_boxes;
      jsk_recognition_msgs::BoundingBox * boxes;

    BoundingBoxArray():
      header(),
      boxes_length(0), boxes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = boxes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < boxes_length; i++){
      offset += this->boxes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t boxes_lengthT = *(inbuffer + offset++);
      if(boxes_lengthT > boxes_length)
        this->boxes = (jsk_recognition_msgs::BoundingBox*)realloc(this->boxes, boxes_lengthT * sizeof(jsk_recognition_msgs::BoundingBox));
      offset += 3;
      boxes_length = boxes_lengthT;
      for( uint8_t i = 0; i < boxes_length; i++){
      offset += this->st_boxes.deserialize(inbuffer + offset);
        memcpy( &(this->boxes[i]), &(this->st_boxes), sizeof(jsk_recognition_msgs::BoundingBox));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/BoundingBoxArray"; };
    const char * getMD5(){ return "c8f4a8bb1acd18ce778d183912bb472d"; };

  };

}
#endif