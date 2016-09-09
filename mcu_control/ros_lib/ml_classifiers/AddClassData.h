#ifndef _ROS_SERVICE_AddClassData_h
#define _ROS_SERVICE_AddClassData_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ml_classifiers/ClassDataPoint.h"

namespace ml_classifiers
{

static const char ADDCLASSDATA[] = "ml_classifiers/AddClassData";

  class AddClassDataRequest : public ros::Msg
  {
    public:
      const char* identifier;
      uint8_t data_length;
      ml_classifiers::ClassDataPoint st_data;
      ml_classifiers::ClassDataPoint * data;

    AddClassDataRequest():
      identifier(""),
      data_length(0), data(NULL)
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
      *(outbuffer + offset++) = data_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->data[i].serialize(outbuffer + offset);
      }
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
      uint8_t data_lengthT = *(inbuffer + offset++);
      if(data_lengthT > data_length)
        this->data = (ml_classifiers::ClassDataPoint*)realloc(this->data, data_lengthT * sizeof(ml_classifiers::ClassDataPoint));
      offset += 3;
      data_length = data_lengthT;
      for( uint8_t i = 0; i < data_length; i++){
      offset += this->st_data.deserialize(inbuffer + offset);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(ml_classifiers::ClassDataPoint));
      }
     return offset;
    }

    const char * getType(){ return ADDCLASSDATA; };
    const char * getMD5(){ return "572733f6e77cd60bddc5c0b72307999c"; };

  };

  class AddClassDataResponse : public ros::Msg
  {
    public:
      bool success;

    AddClassDataResponse():
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

    const char * getType(){ return ADDCLASSDATA; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class AddClassData {
    public:
    typedef AddClassDataRequest Request;
    typedef AddClassDataResponse Response;
  };

}
#endif
