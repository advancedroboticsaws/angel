#ifndef _ROS_posedetection_msgs_Feature0D_h
#define _ROS_posedetection_msgs_Feature0D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace posedetection_msgs
{

  class Feature0D : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t positions_length;
      float st_positions;
      float * positions;
      uint8_t scales_length;
      float st_scales;
      float * scales;
      uint8_t orientations_length;
      float st_orientations;
      float * orientations;
      uint8_t confidences_length;
      float st_confidences;
      float * confidences;
      uint8_t descriptors_length;
      float st_descriptors;
      float * descriptors;
      int32_t descriptor_dim;
      const char* type;

    Feature0D():
      header(),
      positions_length(0), positions(NULL),
      scales_length(0), scales(NULL),
      orientations_length(0), orientations(NULL),
      confidences_length(0), confidences(NULL),
      descriptors_length(0), descriptors(NULL),
      descriptor_dim(0),
      type("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = positions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < positions_length; i++){
      union {
        float real;
        uint32_t base;
      } u_positionsi;
      u_positionsi.real = this->positions[i];
      *(outbuffer + offset + 0) = (u_positionsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_positionsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_positionsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_positionsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions[i]);
      }
      *(outbuffer + offset++) = scales_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < scales_length; i++){
      union {
        float real;
        uint32_t base;
      } u_scalesi;
      u_scalesi.real = this->scales[i];
      *(outbuffer + offset + 0) = (u_scalesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scalesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scalesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scalesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scales[i]);
      }
      *(outbuffer + offset++) = orientations_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < orientations_length; i++){
      union {
        float real;
        uint32_t base;
      } u_orientationsi;
      u_orientationsi.real = this->orientations[i];
      *(outbuffer + offset + 0) = (u_orientationsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_orientationsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_orientationsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_orientationsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientations[i]);
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
      uint32_t length_type = strlen(this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t positions_lengthT = *(inbuffer + offset++);
      if(positions_lengthT > positions_length)
        this->positions = (float*)realloc(this->positions, positions_lengthT * sizeof(float));
      offset += 3;
      positions_length = positions_lengthT;
      for( uint8_t i = 0; i < positions_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_positions;
      u_st_positions.base = 0;
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_positions.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_positions = u_st_positions.real;
      offset += sizeof(this->st_positions);
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(float));
      }
      uint8_t scales_lengthT = *(inbuffer + offset++);
      if(scales_lengthT > scales_length)
        this->scales = (float*)realloc(this->scales, scales_lengthT * sizeof(float));
      offset += 3;
      scales_length = scales_lengthT;
      for( uint8_t i = 0; i < scales_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_scales;
      u_st_scales.base = 0;
      u_st_scales.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_scales.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_scales.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_scales.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_scales = u_st_scales.real;
      offset += sizeof(this->st_scales);
        memcpy( &(this->scales[i]), &(this->st_scales), sizeof(float));
      }
      uint8_t orientations_lengthT = *(inbuffer + offset++);
      if(orientations_lengthT > orientations_length)
        this->orientations = (float*)realloc(this->orientations, orientations_lengthT * sizeof(float));
      offset += 3;
      orientations_length = orientations_lengthT;
      for( uint8_t i = 0; i < orientations_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_orientations;
      u_st_orientations.base = 0;
      u_st_orientations.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_orientations.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_orientations.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_orientations.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_orientations = u_st_orientations.real;
      offset += sizeof(this->st_orientations);
        memcpy( &(this->orientations[i]), &(this->st_orientations), sizeof(float));
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
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
     return offset;
    }

    const char * getType(){ return "posedetection_msgs/Feature0D"; };
    const char * getMD5(){ return "fcb3ba42a42cf972f3838cdb171f5e04"; };

  };

}
#endif