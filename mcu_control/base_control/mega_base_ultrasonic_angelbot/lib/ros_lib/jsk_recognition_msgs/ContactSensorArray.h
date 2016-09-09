#ifndef _ROS_jsk_recognition_msgs_ContactSensorArray_h
#define _ROS_jsk_recognition_msgs_ContactSensorArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/ContactSensor.h"

namespace jsk_recognition_msgs
{

  class ContactSensorArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t datas_length;
      jsk_recognition_msgs::ContactSensor st_datas;
      jsk_recognition_msgs::ContactSensor * datas;

    ContactSensorArray():
      header(),
      datas_length(0), datas(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = datas_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < datas_length; i++){
      offset += this->datas[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t datas_lengthT = *(inbuffer + offset++);
      if(datas_lengthT > datas_length)
        this->datas = (jsk_recognition_msgs::ContactSensor*)realloc(this->datas, datas_lengthT * sizeof(jsk_recognition_msgs::ContactSensor));
      offset += 3;
      datas_length = datas_lengthT;
      for( uint8_t i = 0; i < datas_length; i++){
      offset += this->st_datas.deserialize(inbuffer + offset);
        memcpy( &(this->datas[i]), &(this->st_datas), sizeof(jsk_recognition_msgs::ContactSensor));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ContactSensorArray"; };
    const char * getMD5(){ return "c65f16fb3a523c0b77d7e31330b214da"; };

  };

}
#endif