#ifndef _ROS_jsk_recognition_msgs_SimpleOccupancyGridArray_h
#define _ROS_jsk_recognition_msgs_SimpleOccupancyGridArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/SimpleOccupancyGrid.h"

namespace jsk_recognition_msgs
{

  class SimpleOccupancyGridArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t grids_length;
      jsk_recognition_msgs::SimpleOccupancyGrid st_grids;
      jsk_recognition_msgs::SimpleOccupancyGrid * grids;

    SimpleOccupancyGridArray():
      header(),
      grids_length(0), grids(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = grids_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < grids_length; i++){
      offset += this->grids[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t grids_lengthT = *(inbuffer + offset++);
      if(grids_lengthT > grids_length)
        this->grids = (jsk_recognition_msgs::SimpleOccupancyGrid*)realloc(this->grids, grids_lengthT * sizeof(jsk_recognition_msgs::SimpleOccupancyGrid));
      offset += 3;
      grids_length = grids_lengthT;
      for( uint8_t i = 0; i < grids_length; i++){
      offset += this->st_grids.deserialize(inbuffer + offset);
        memcpy( &(this->grids[i]), &(this->st_grids), sizeof(jsk_recognition_msgs::SimpleOccupancyGrid));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/SimpleOccupancyGridArray"; };
    const char * getMD5(){ return "e448b458270a6ec465d66169c4180932"; };

  };

}
#endif