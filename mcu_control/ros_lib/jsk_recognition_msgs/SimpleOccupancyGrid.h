#ifndef _ROS_jsk_recognition_msgs_SimpleOccupancyGrid_h
#define _ROS_jsk_recognition_msgs_SimpleOccupancyGrid_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace jsk_recognition_msgs
{

  class SimpleOccupancyGrid : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float coefficients[4];
      float resolution;
      uint8_t cells_length;
      geometry_msgs::Point st_cells;
      geometry_msgs::Point * cells;

    SimpleOccupancyGrid():
      header(),
      coefficients(),
      resolution(0),
      cells_length(0), cells(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint8_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_coefficientsi;
      u_coefficientsi.real = this->coefficients[i];
      *(outbuffer + offset + 0) = (u_coefficientsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_coefficientsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_coefficientsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_coefficientsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->coefficients[i]);
      }
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
      *(outbuffer + offset++) = cells_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < cells_length; i++){
      offset += this->cells[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint8_t i = 0; i < 4; i++){
      union {
        float real;
        uint32_t base;
      } u_coefficientsi;
      u_coefficientsi.base = 0;
      u_coefficientsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_coefficientsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_coefficientsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_coefficientsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->coefficients[i] = u_coefficientsi.real;
      offset += sizeof(this->coefficients[i]);
      }
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
      uint8_t cells_lengthT = *(inbuffer + offset++);
      if(cells_lengthT > cells_length)
        this->cells = (geometry_msgs::Point*)realloc(this->cells, cells_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      cells_length = cells_lengthT;
      for( uint8_t i = 0; i < cells_length; i++){
      offset += this->st_cells.deserialize(inbuffer + offset);
        memcpy( &(this->cells[i]), &(this->st_cells), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SimpleOccupancyGrid"; };
    const char * getMD5(){ return "25fb4ce5a31aab052ba1250fcdda9da7"; };

  };

}
#endif