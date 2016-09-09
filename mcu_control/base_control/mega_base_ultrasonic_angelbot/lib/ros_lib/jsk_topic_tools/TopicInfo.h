#ifndef _ROS_jsk_topic_tools_TopicInfo_h
#define _ROS_jsk_topic_tools_TopicInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_topic_tools
{

  class TopicInfo : public ros::Msg
  {
    public:
      const char* topic_name;
      float rate;

    TopicInfo():
      topic_name(""),
      rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic_name = strlen(this->topic_name);
      memcpy(outbuffer + offset, &length_topic_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topic_name, length_topic_name);
      offset += length_topic_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic_name;
      memcpy(&length_topic_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic_name-1]=0;
      this->topic_name = (char *)(inbuffer + offset-1);
      offset += length_topic_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rate));
     return offset;
    }

    const char * getType(){ return "jsk_topic_tools/TopicInfo"; };
    const char * getMD5(){ return "78edf14defd72c2fcd29e4fad0165ea9"; };

  };

}
#endif