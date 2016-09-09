#ifndef _ROS_jsk_recognition_msgs_PolygonArray_h
#define _ROS_jsk_recognition_msgs_PolygonArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PolygonStamped.h"

namespace jsk_recognition_msgs
{

  class PolygonArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t polygons_length;
      geometry_msgs::PolygonStamped st_polygons;
      geometry_msgs::PolygonStamped * polygons;
      uint8_t labels_length;
      uint32_t st_labels;
      uint32_t * labels;
      uint8_t likelihood_length;
      float st_likelihood;
      float * likelihood;

    PolygonArray():
      header(),
      polygons_length(0), polygons(NULL),
      labels_length(0), labels(NULL),
      likelihood_length(0), likelihood(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = polygons_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < polygons_length; i++){
      offset += this->polygons[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = labels_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < labels_length; i++){
      *(outbuffer + offset + 0) = (this->labels[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->labels[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->labels[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->labels[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->labels[i]);
      }
      *(outbuffer + offset++) = likelihood_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < likelihood_length; i++){
      union {
        float real;
        uint32_t base;
      } u_likelihoodi;
      u_likelihoodi.real = this->likelihood[i];
      *(outbuffer + offset + 0) = (u_likelihoodi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_likelihoodi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_likelihoodi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_likelihoodi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->likelihood[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t polygons_lengthT = *(inbuffer + offset++);
      if(polygons_lengthT > polygons_length)
        this->polygons = (geometry_msgs::PolygonStamped*)realloc(this->polygons, polygons_lengthT * sizeof(geometry_msgs::PolygonStamped));
      offset += 3;
      polygons_length = polygons_lengthT;
      for( uint8_t i = 0; i < polygons_length; i++){
      offset += this->st_polygons.deserialize(inbuffer + offset);
        memcpy( &(this->polygons[i]), &(this->st_polygons), sizeof(geometry_msgs::PolygonStamped));
      }
      uint8_t labels_lengthT = *(inbuffer + offset++);
      if(labels_lengthT > labels_length)
        this->labels = (uint32_t*)realloc(this->labels, labels_lengthT * sizeof(uint32_t));
      offset += 3;
      labels_length = labels_lengthT;
      for( uint8_t i = 0; i < labels_length; i++){
      this->st_labels =  ((uint32_t) (*(inbuffer + offset)));
      this->st_labels |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_labels |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_labels |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_labels);
        memcpy( &(this->labels[i]), &(this->st_labels), sizeof(uint32_t));
      }
      uint8_t likelihood_lengthT = *(inbuffer + offset++);
      if(likelihood_lengthT > likelihood_length)
        this->likelihood = (float*)realloc(this->likelihood, likelihood_lengthT * sizeof(float));
      offset += 3;
      likelihood_length = likelihood_lengthT;
      for( uint8_t i = 0; i < likelihood_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_likelihood;
      u_st_likelihood.base = 0;
      u_st_likelihood.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_likelihood.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_likelihood.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_likelihood.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_likelihood = u_st_likelihood.real;
      offset += sizeof(this->st_likelihood);
        memcpy( &(this->likelihood[i]), &(this->st_likelihood), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/PolygonArray"; };
    const char * getMD5(){ return "709b37d39871cfdbbfbd5c41cf9bc2be"; };

  };

}
#endif