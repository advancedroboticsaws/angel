#ifndef _ROS_angelbot_JointCmd_h
#define _ROS_angelbot_JointCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "angelbot/Cmd.h"

namespace angelbot
{

  class JointCmd : public ros::Msg
  {
    public:
      angelbot::Cmd joint0;
      angelbot::Cmd joint1;
      angelbot::Cmd joint2;
      angelbot::Cmd joint3;

    JointCmd():
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

    const char * getType(){ return "angelbot/JointCmd"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
