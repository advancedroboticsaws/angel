#ifndef _ROS_jsk_recognition_msgs_Circle2DArray_h
#define _ROS_jsk_recognition_msgs_Circle2DArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/Circle2D.h"

namespace jsk_recognition_msgs
{

  class Circle2DArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t circles_length;
      jsk_recognition_msgs::Circle2D st_circles;
      jsk_recognition_msgs::Circle2D * circles;

    Circle2DArray():
      header(),
      circles_length(0), circles(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = circles_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < circles_length; i++){
      offset += this->circles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t circles_lengthT = *(inbuffer + offset++);
      if(circles_lengthT > circles_length)
        this->circles = (jsk_recognition_msgs::Circle2D*)realloc(this->circles, circles_lengthT * sizeof(jsk_recognition_msgs::Circle2D));
      offset += 3;
      circles_length = circles_lengthT;
      for( uint8_t i = 0; i < circles_length; i++){
      offset += this->st_circles.deserialize(inbuffer + offset);
        memcpy( &(this->circles[i]), &(this->st_circles), sizeof(jsk_recognition_msgs::Circle2D));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/Circle2DArray"; };
    const char * getMD5(){ return "7c3f0f08758538a1e02ce600cf99132f"; };

  };

}
#endif