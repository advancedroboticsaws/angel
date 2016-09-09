#ifndef _ROS_jsk_recognition_msgs_SparseOccupancyGrid_h
#define _ROS_jsk_recognition_msgs_SparseOccupancyGrid_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "jsk_recognition_msgs/SparseOccupancyGridColumn.h"

namespace jsk_recognition_msgs
{

  class SparseOccupancyGrid : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::Pose origin_pose;
      float resolution;
      uint8_t columns_length;
      jsk_recognition_msgs::SparseOccupancyGridColumn st_columns;
      jsk_recognition_msgs::SparseOccupancyGridColumn * columns;

    SparseOccupancyGrid():
      header(),
      origin_pose(),
      resolution(0),
      columns_length(0), columns(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->origin_pose.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.real = this->resolution;
      *(outbuffer + offset + 0) = (u_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resolution);
      *(outbuffer + offset++) = columns_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < columns_length; i++){
      offset += this->columns[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->origin_pose.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.base = 0;
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resolution = u_resolution.real;
      offset += sizeof(this->resolution);
      uint8_t columns_lengthT = *(inbuffer + offset++);
      if(columns_lengthT > columns_length)
        this->columns = (jsk_recognition_msgs::SparseOccupancyGridColumn*)realloc(this->columns, columns_lengthT * sizeof(jsk_recognition_msgs::SparseOccupancyGridColumn));
      offset += 3;
      columns_length = columns_lengthT;
      for( uint8_t i = 0; i < columns_length; i++){
      offset += this->st_columns.deserialize(inbuffer + offset);
        memcpy( &(this->columns[i]), &(this->st_columns), sizeof(jsk_recognition_msgs::SparseOccupancyGridColumn));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SparseOccupancyGrid"; };
    const char * getMD5(){ return "497269ddab6058d0d4860f25dc49448f"; };

  };

}
#endif