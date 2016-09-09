#ifndef _ROS_SERVICE_SaveClassifier_h
#define _ROS_SERVICE_SaveClassifier_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ml_classifiers
{

static const char SAVECLASSIFIER[] = "ml_classifiers/SaveClassifier";

  class SaveClassifierRequest : public ros::Msg
  {
    public:
      const char* identifier;
      const char* filename;

    SaveClassifierRequest():
      identifier(""),
      filename("")
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
      uint32_t length_filename = strlen(this->filename);
      memcpy(outbuffer + offset, &length_filename, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->filename, length_filename);
      offset += length_filename;
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
      uint32_t length_filename;
      memcpy(&length_filename, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filename-1]=0;
      this->filename = (char *)(inbuffer + offset-1);
      offset += length_filename;
     return offset;
    }

    const char * getType(){ return SAVECLASSIFIER; };
    const char * getMD5(){ return "2d50ff86a65c82a45987a006318bcb00"; };

  };

  class SaveClassifierResponse : public ros::Msg
  {
    public:
      bool success;

    SaveClassifierResponse():
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

    const char * getType(){ return SAVECLASSIFIER; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SaveClassifier {
    public:
    typedef SaveClassifierRequest Request;
    typedef SaveClassifierResponse Response;
  };

}
#endif
