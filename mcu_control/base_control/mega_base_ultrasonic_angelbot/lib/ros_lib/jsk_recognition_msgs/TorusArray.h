#ifndef _ROS_jsk_recognition_msgs_TorusArray_h
#define _ROS_jsk_recognition_msgs_TorusArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/Torus.h"

namespace jsk_recognition_msgs
{

  class TorusArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t toruses_length;
      jsk_recognition_msgs::Torus st_toruses;
      jsk_recognition_msgs::Torus * toruses;

    TorusArray():
      header(),
      toruses_length(0), toruses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = toruses_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < toruses_length; i++){
      offset += this->toruses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t toruses_lengthT = *(inbuffer + offset++);
      if(toruses_lengthT > toruses_length)
        this->toruses = (jsk_recognition_msgs::Torus*)realloc(this->toruses, toruses_lengthT * sizeof(jsk_recognition_msgs::Torus));
      offset += 3;
      toruses_length = toruses_lengthT;
      for( uint8_t i = 0; i < toruses_length; i++){
      offset += this->st_toruses.deserialize(inbuffer + offset);
        memcpy( &(this->toruses[i]), &(this->st_toruses), sizeof(jsk_recognition_msgs::Torus));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/TorusArray"; };
    const char * getMD5(){ return "81d0dbf46016b5714fa4ea9eca5485e0"; };

  };

}
#endif