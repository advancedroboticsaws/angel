#ifndef _ROS_SERVICE_CreateClassifier_h
#define _ROS_SERVICE_CreateClassifier_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ml_classifiers
{

static const char CREATECLASSIFIER[] = "ml_classifiers/CreateClassifier";

  class CreateClassifierRequest : public ros::Msg
  {
    public:
      const char* identifier;
      const char* class_type;

    CreateClassifierRequest():
      identifier(""),
      class_type("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_identifier = strlen(this->identifier);
      memcpy(outbuffer + offset, &length_identifier, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->identifier, length_identifier);
      offset += length_identifier;
      uint32_t length_class_type = strlen(this->class_type);
      memcpy(outbuffer + offset, &length_class_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->class_type, length_class_type);
      offset += length_class_type;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_identifier;
      memcpy(&length_identifier, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_identifier; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_identifier-1]=0;
      this->identifier = (char *)(inbuffer + offset-1);
      offset += length_identifier;
      uint32_t length_class_type;
      memcpy(&length_class_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_class_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_class_type-1]=0;
      this->class_type = (char *)(inbuffer + offset-1);
      offset += length_class_type;
     return offset;
    }

    const char * getType(){ return CREATECLASSIFIER; };
    const char * getMD5(){ return "36ef13003ee3b780829219bc11e3359a"; };

  };

  class CreateClassifierResponse : public ros::Msg
  {
    public:
      bool success;

    CreateClassifierResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return CREATECLASSIFIER; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class CreateClassifier {
    public:
    typedef CreateClassifierRequest Request;
    typedef CreateClassifierResponse Response;
  };

}
#endif
