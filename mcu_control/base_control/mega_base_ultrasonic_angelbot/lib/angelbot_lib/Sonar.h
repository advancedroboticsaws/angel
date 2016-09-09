#ifndef _ROS_angelbot_Sonar_h
#define _ROS_angelbot_Sonar_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace angelbot
{

  class Sonar : public ros::Msg
  {
    public:
      uint8_t sonar1;
      uint8_t sonar2;
      uint8_t sonar3;
      uint8_t sonar4;
      uint8_t sonar5;
      uint8_t sonar6;
      uint8_t sonar7;
      uint8_t sonar8;

    Sonar():
      sonar1(0),
      sonar2(0),
      sonar3(0),
      sonar4(0),
      sonar5(0),
      sonar6(0),
      sonar7(0),
      sonar8(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sonar1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sonar1);
      *(outbuffer + offset + 0) = (this->sonar2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sonar2);
      *(outbuffer + offset + 0) = (this->sonar3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sonar3);
      *(outbuffer + offset + 0) = (this->sonar4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sonar4);
      *(outbuffer + offset + 0) = (this->sonar5 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sonar5);
      *(outbuffer + offset + 0) = (this->sonar6 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sonar6);
      *(outbuffer + offset + 0) = (this->sonar7 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sonar7);
      *(outbuffer + offset + 0) = (this->sonar8 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sonar8);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->sonar1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sonar1);
      this->sonar2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sonar2);
      this->sonar3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sonar3);
      this->sonar4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sonar4);
      this->sonar5 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sonar5);
      this->sonar6 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sonar6);
      this->sonar7 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sonar7);
      this->sonar8 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sonar8);
     return offset;
    }

    const char * getType(){ return "angelbot/Sonar"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
