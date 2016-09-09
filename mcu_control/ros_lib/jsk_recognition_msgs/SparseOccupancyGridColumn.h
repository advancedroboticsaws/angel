#ifndef _ROS_jsk_recognition_msgs_SparseOccupancyGridColumn_h
#define _ROS_jsk_recognition_msgs_SparseOccupancyGridColumn_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/SparseOccupancyGridCell.h"

namespace jsk_recognition_msgs
{

  class SparseOccupancyGridColumn : public ros::Msg
  {
    public:
      int32_t column_index;
      uint8_t cells_length;
      jsk_recognition_msgs::SparseOccupancyGridCell st_cells;
      jsk_recognition_msgs::SparseOccupancyGridCell * cells;

    SparseOccupancyGridColumn():
      column_index(0),
      cells_length(0), cells(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_column_index;
      u_column_index.real = this->column_index;
      *(outbuffer + offset + 0) = (u_column_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_column_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_column_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_column_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->column_index);
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
      union {
        int32_t real;
        uint32_t base;
      } u_column_index;
      u_column_index.base = 0;
      u_column_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_column_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_column_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_column_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->column_index = u_column_index.real;
      offset += sizeof(this->column_index);
      uint8_t cells_lengthT = *(inbuffer + offset++);
      if(cells_lengthT > cells_length)
        this->cells = (jsk_recognition_msgs::SparseOccupancyGridCell*)realloc(this->cells, cells_lengthT * sizeof(jsk_recognition_msgs::SparseOccupancyGridCell));
      offset += 3;
      cells_length = cells_lengthT;
      for( uint8_t i = 0; i < cells_length; i++){
      offset += this->st_cells.deserialize(inbuffer + offset);
        memcpy( &(this->cells[i]), &(this->st_cells), sizeof(jsk_recognition_msgs::SparseOccupancyGridCell));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SparseOccupancyGridColumn"; };
    const char * getMD5(){ return "55074b193e722d5ead092ffe27f06522"; };

  };

}
#endif