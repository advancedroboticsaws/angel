#ifndef _ROS_jsk_recognition_msgs_ParallelEdgeArray_h
#define _ROS_jsk_recognition_msgs_ParallelEdgeArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "jsk_recognition_msgs/ParallelEdge.h"

namespace jsk_recognition_msgs
{

  class ParallelEdgeArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t edge_groups_length;
      jsk_recognition_msgs::ParallelEdge st_edge_groups;
      jsk_recognition_msgs::ParallelEdge * edge_groups;

    ParallelEdgeArray():
      header(),
      edge_groups_length(0), edge_groups(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = edge_groups_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < edge_groups_length; i++){
      offset += this->edge_groups[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t edge_groups_lengthT = *(inbuffer + offset++);
      if(edge_groups_lengthT > edge_groups_length)
        this->edge_groups = (jsk_recognition_msgs::ParallelEdge*)realloc(this->edge_groups, edge_groups_lengthT * sizeof(jsk_recognition_msgs::ParallelEdge));
      offset += 3;
      edge_groups_length = edge_groups_lengthT;
      for( uint8_t i = 0; i < edge_groups_length; i++){
      offset += this->st_edge_groups.deserialize(inbuffer + offset);
        memcpy( &(this->edge_groups[i]), &(this->st_edge_groups), sizeof(jsk_recognition_msgs::ParallelEdge));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ParallelEdgeArray"; };
    const char * getMD5(){ return "7c8ef4f5976c55fb32293ceaa19a1189"; };

  };

}
#endif