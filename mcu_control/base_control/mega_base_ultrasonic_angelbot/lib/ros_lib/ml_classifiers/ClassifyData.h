#ifndef _ROS_SERVICE_ClassifyData_h
#define _ROS_SERVICE_ClassifyData_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ml_classifiers/ClassDataPoint.h"

namespace ml_classifiers
{

static const char CLASSIFYDATA[] = "ml_classifiers/ClassifyData";

  class ClassifyDataRequest : public ros::Msg
  {
    public:
      const char* identifier;
      uint8_t data_length;
      ml_classifiers::ClassDataPoint st_data;
      ml_classifiers::ClassDataPoint * data;

    ClassifyDataRequest():
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

    const char * getType(){ return CLASSIFYDATA; };
    const char * getMD5(){ return "572733f6e77cd60bddc5c0b72307999c"; };

  };

  class ClassifyDataResponse : public ros::Msg
  {
    public:
      uint8_t classifications_length;
      char* st_classifications;
      char* * classifications;

    ClassifyDataResponse():
      classifications_length(0), classifications(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = classifications_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < classifications_length; i++){
      uint32_t length_classificationsi = strlen(this->classifications[i]);
      memcpy(outbuffer + offset, &length_classificationsi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->classifications[i], length_classificationsi);
      offset += length_classificationsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t classifications_lengthT = *(inbuffer + offset++);
      if(classifications_lengthT > classifications_length)
        this->classifications = (char**)realloc(this->classifications, classifications_lengthT * sizeof(char*));
      offset += 3;
      classifications_length = classifications_lengthT;
      for( uint8_t i = 0; i < classifications_length; i++){
      uint32_t length_st_classifications;
      memcpy(&length_st_classifications, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_classifications; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_classifications-1]=0;
      this->st_classifications = (char *)(inbuffer + offset-1);
      offset += length_st_classifications;
        memcpy( &(this->classifications[i]), &(this->st_classifications), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return CLASSIFYDATA; };
    const char * getMD5(){ return "5ce145dc8157b011850524b4b0ffd0b7"; };

  };

  class ClassifyData {
    public:
    typedef ClassifyDataRequest Request;
    typedef ClassifyDataResponse Response;
  };

}
#endif
