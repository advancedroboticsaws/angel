#ifndef _ROS_SERVICE_List_h
#define _ROS_SERVICE_List_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_topic_tools
{

static const char LIST[] = "jsk_topic_tools/List";

  class ListRequest : public ros::Msg
  {
    public:

    ListRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return LIST; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListResponse : public ros::Msg
  {
    public:
      uint8_t topic_names_length;
      char* st_topic_names;
      char* * topic_names;

    ListResponse():
      topic_names_length(0), topic_names(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = topic_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < topic_names_length; i++){
      uint32_t length_topic_namesi = strlen(this->topic_names[i]);
      memcpy(outbuffer + offset, &length_topic_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->topic_names[i], length_topic_namesi);
      offset += length_topic_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t topic_names_lengthT = *(inbuffer + offset++);
      if(topic_names_lengthT > topic_names_length)
        this->topic_names = (char**)realloc(this->topic_names, topic_names_lengthT * sizeof(char*));
      offset += 3;
      topic_names_length = topic_names_lengthT;
      for( uint8_t i = 0; i < topic_names_length; i++){
      uint32_t length_st_topic_names;
      memcpy(&length_st_topic_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_topic_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_topic_names-1]=0;
      this->st_topic_names = (char *)(inbuffer + offset-1);
      offset += length_st_topic_names;
        memcpy( &(this->topic_names[i]), &(this->st_topic_names), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return LIST; };
    const char * getMD5(){ return "f88f7a076bf16dde010b2480af40dcdb"; };

  };

  class List {
    public:
    typedef ListRequest Request;
    typedef ListResponse Response;
  };

}
#endif
