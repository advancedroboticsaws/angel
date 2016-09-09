#ifndef _ROS_posedetection_msgs_Feature1D_h
#define _ROS_posedetection_msgs_Feature1D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "posedetection_msgs/Curve1D.h"

namespace posedetection_msgs
{

  class Feature1D : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t lines_length;
      posedetection_msgs::Curve1D st_lines;
      posedetection_msgs::Curve1D * lines;
      uint8_t descriptors_length;
      float st_descriptors;
      float * descriptors;
      uint8_t confidences_length;
      float st_confidences;
      float * confidences;
      int32_t descriptor_dim;

    Feature1D():
      header(),
      lines_length(0), lines(NULL),
      descriptors_length(0), descriptors(NULL),
      confidences_length(0), confidences(NULL),
      descriptor_dim(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = lines_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < lines_length; i++){
      offset += this->lines[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = descriptors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < descriptors_length; i++){
      union {
        float real;
        uint32_t base;
      } u_descriptorsi;
      u_descriptorsi.real = this->descriptors[i];
      *(outbuffer + offset + 0) = (u_descriptorsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_descriptorsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_descriptorsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_descriptorsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->descriptors[i]);
      }
      *(outbuffer + offset++) = confidences_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < confidences_length; i++){
      union {
        float real;
        uint32_t base;
      } u_confidencesi;
      u_confidencesi.real = this->confidences[i];
      *(outbuffer + offset + 0) = (u_confidencesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidencesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidencesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidencesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidences[i]);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_descriptor_dim;
      u_descriptor_dim.real = this->descriptor_dim;
      *(outbuffer + offset + 0) = (u_descriptor_dim.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_descriptor_dim.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_descriptor_dim.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_descriptor_dim.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->descriptor_dim);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t lines_lengthT = *(inbuffer + offset++);
      if(lines_lengthT > lines_length)
        this->lines = (posedetection_msgs::Curve1D*)realloc(this->lines, lines_lengthT * sizeof(posedetection_msgs::Curve1D));
      offset += 3;
      lines_length = lines_lengthT;
      for( uint8_t i = 0; i < lines_length; i++){
      offset += this->st_lines.deserialize(inbuffer + offset);
        memcpy( &(this->lines[i]), &(this->st_lines), sizeof(posedetection_msgs::Curve1D));
      }
      uint8_t descriptors_lengthT = *(inbuffer + offset++);
      if(descriptors_lengthT > descriptors_length)
        this->descriptors = (float*)realloc(this->descriptors, descriptors_lengthT * sizeof(float));
      offset += 3;
      descriptors_length = descriptors_lengthT;
      for( uint8_t i = 0; i < descriptors_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_descriptors;
      u_st_descriptors.base = 0;
      u_st_descriptors.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_descriptors.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_descriptors.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_descriptors.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_descriptors = u_st_descriptors.real;
      offset += sizeof(this->st_descriptors);
        memcpy( &(this->descriptors[i]), &(this->st_descriptors), sizeof(float));
      }
      uint8_t confidences_lengthT = *(inbuffer + offset++);
      if(confidences_lengthT > confidences_length)
        this->confidences = (float*)realloc(this->confidences, confidences_lengthT * sizeof(float));
      offset += 3;
      confidences_length = confidences_lengthT;
      for( uint8_t i = 0; i < confidences_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_confidences;
      u_st_confidences.base = 0;
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_confidences.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_confidences = u_st_confidences.real;
      offset += sizeof(this->st_confidences);
        memcpy( &(this->confidences[i]), &(this->st_confidences), sizeof(float));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_descriptor_dim;
      u_descriptor_dim.base = 0;
      u_descriptor_dim.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_descriptor_dim.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_descriptor_dim.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_descriptor_dim.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->descriptor_dim = u_descriptor_dim.real;
      offset += sizeof(this->descriptor_dim);
     return offset;
    }

    const char * getType(){ return "posedetection_msgs/Feature1D"; };
    const char * getMD5(){ return "4568f21f2dd0840ca2d658d4d1710f33"; };

  };

}
#endif