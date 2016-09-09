#ifndef _ROS_angelbot_JointFb_h
#define _ROS_angelbot_JointFb_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "angelbot/Fb.h"

namespace angelbot
{

  class JointFb : public ros::Msg
  {
    public:
      angelbot::Fb joint0;
      angelbot::Fb joint1;
      angelbot::Fb joint2;
      angelbot::Fb joint3;

    JointFb():
      joint0(),
      joint1(),
      joint2(),
      joint3()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint0.serialize(outbuffer + offset);
      offset += this->joint1.serialize(outbuffer + offset);
      offset += this->joint2.serialize(outbuffer + offset);
      offset += this->joint3.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint0.deserialize(inbuffer + offset);
      offset += this->joint1.deserialize(inbuffer + offset);
      offset += this->joint2.deserialize(inbuffer + offset);
      offset += this->joint3.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "angelbot/JointFb"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
