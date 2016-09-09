#ifndef _ROS_frontier_exploration_Frontier_h
#define _ROS_frontier_exploration_Frontier_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace frontier_exploration
{

  class Frontier : public ros::Msg
  {
    public:
      uint32_t size;
      float min_distance;
      geometry_msgs::Point initial;
      geometry_msgs::Point centroid;
      geometry_msgs::Point middle;

    Frontier():
      size(0),
      min_distance(0),
      initial(),
      centroid(),
      middle()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->size >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->size >> (8 * 3)) & 0xFF;
      offset += sizeof(this->size);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_distance);
      offset += this->initial.serialize(outbuffer + offset);
      offset += this->centroid.serialize(outbuffer + offset);
      offset += this->middle.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->size =  ((uint32_t) (*(inbuffer + offset)));
      this->size |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->size |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->size |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->size);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_distance));
      offset += this->initial.deserialize(inbuffer + offset);
      offset += this->centroid.deserialize(inbuffer + offset);
      offset += this->middle.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "frontier_exploration/Frontier"; };
    const char * getMD5(){ return "1325c0e43f607455fdee9e36462f6ba0"; };

  };

}
#endif