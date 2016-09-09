#ifndef _ROS_pr2_msgs_PeriodicCmd_h
#define _ROS_pr2_msgs_PeriodicCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace pr2_msgs
{

  class PeriodicCmd : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* profile;
      float period;
      float amplitude;
      float offset;

    PeriodicCmd():
      header(),
      profile(""),
      period(0),
      amplitude(0),
      offset(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_profile = strlen(this->profile);
      memcpy(outbuffer + offset, &length_profile, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->profile, length_profile);
      offset += length_profile;
      offset += serializeAvrFloat64(outbuffer + offset, this->period);
      offset += serializeAvrFloat64(outbuffer + offset, this->amplitude);
      offset += serializeAvrFloat64(outbuffer + offset, this->offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_profile;
      memcpy(&length_profile, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_profile; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_profile-1]=0;
      this->profile = (char *)(inbuffer + offset-1);
      offset += length_profile;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->period));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->amplitude));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->offset));
     return offset;
    }

    const char * getType(){ return "pr2_msgs/PeriodicCmd"; };
    const char * getMD5(){ return "95ab7e548e3d4274f83393129dd96c2e"; };

  };

}
#endif