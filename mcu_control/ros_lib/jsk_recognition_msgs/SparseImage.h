#ifndef _ROS_jsk_recognition_msgs_SparseImage_h
#define _ROS_jsk_recognition_msgs_SparseImage_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class SparseImage : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint32_t width;
      uint32_t height;
      uint8_t data16_length;
      uint16_t st_data16;
      uint16_t * data16;
      uint8_t data32_length;
      uint32_t st_data32;
      uint32_t * data32;

    SparseImage():
      header(),
      width(0),
      height(0),
      data16_length(0), data16(NULL),
      data32_length(0), data32(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset++) = data16_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data16_length; i++){
      *(outbuffer + offset + 0) = (this->data16[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data16[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->data16[i]);
      }
      *(outbuffer + offset++) = data32_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < data32_length; i++){
      *(outbuffer + offset + 0) = (this->data32[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data32[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data32[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data32[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data32[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      uint8_t data16_lengthT = *(inbuffer + offset++);
      if(data16_lengthT > data16_length)
        this->data16 = (uint16_t*)realloc(this->data16, data16_lengthT * sizeof(uint16_t));
      offset += 3;
      data16_length = data16_lengthT;
      for( uint8_t i = 0; i < data16_length; i++){
      this->st_data16 =  ((uint16_t) (*(inbuffer + offset)));
      this->st_data16 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_data16);
        memcpy( &(this->data16[i]), &(this->st_data16), sizeof(uint16_t));
      }
      uint8_t data32_lengthT = *(inbuffer + offset++);
      if(data32_lengthT > data32_length)
        this->data32 = (uint32_t*)realloc(this->data32, data32_lengthT * sizeof(uint32_t));
      offset += 3;
      data32_length = data32_lengthT;
      for( uint8_t i = 0; i < data32_length; i++){
      this->st_data32 =  ((uint32_t) (*(inbuffer + offset)));
      this->st_data32 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_data32 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_data32 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_data32);
        memcpy( &(this->data32[i]), &(this->st_data32), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SparseImage"; };
    const char * getMD5(){ return "7c361d829424bc5984fc0a1831f84751"; };

  };

}
#endif