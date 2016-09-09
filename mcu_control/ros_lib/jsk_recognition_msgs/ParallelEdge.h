#ifndef _ROS_jsk_recognition_msgs_ParallelEdge_h
#define _ROS_jsk_recognition_msgs_ParallelEdge_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pcl_msgs/PointIndices.h"
#include "pcl_msgs/ModelCoefficients.h"

namespace jsk_recognition_msgs
{

  class ParallelEdge : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t cluster_indices_length;
      pcl_msgs::PointIndices st_cluster_indices;
      pcl_msgs::PointIndices * cluster_indices;
      uint8_t coefficients_length;
      pcl_msgs::ModelCoefficients st_coefficients;
      pcl_msgs::ModelCoefficients * coefficients;

    ParallelEdge():
      header(),
      cluster_indices_length(0), cluster_indices(NULL),
      coefficients_length(0), coefficients(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = cluster_indices_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < cluster_indices_length; i++){
      offset += this->cluster_indices[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = coefficients_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < coefficients_length; i++){
      offset += this->coefficients[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t cluster_indices_lengthT = *(inbuffer + offset++);
      if(cluster_indices_lengthT > cluster_indices_length)
        this->cluster_indices = (pcl_msgs::PointIndices*)realloc(this->cluster_indices, cluster_indices_lengthT * sizeof(pcl_msgs::PointIndices));
      offset += 3;
      cluster_indices_length = cluster_indices_lengthT;
      for( uint8_t i = 0; i < cluster_indices_length; i++){
      offset += this->st_cluster_indices.deserialize(inbuffer + offset);
        memcpy( &(this->cluster_indices[i]), &(this->st_cluster_indices), sizeof(pcl_msgs::PointIndices));
      }
      uint8_t coefficients_lengthT = *(inbuffer + offset++);
      if(coefficients_lengthT > coefficients_length)
        this->coefficients = (pcl_msgs::ModelCoefficients*)realloc(this->coefficients, coefficients_lengthT * sizeof(pcl_msgs::ModelCoefficients));
      offset += 3;
      coefficients_length = coefficients_lengthT;
      for( uint8_t i = 0; i < coefficients_length; i++){
      offset += this->st_coefficients.deserialize(inbuffer + offset);
        memcpy( &(this->coefficients[i]), &(this->st_coefficients), sizeof(pcl_msgs::ModelCoefficients));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ParallelEdge"; };
    const char * getMD5(){ return "3a550d5b6275fe0a1580ebf8a62dd336"; };

  };

}
#endif