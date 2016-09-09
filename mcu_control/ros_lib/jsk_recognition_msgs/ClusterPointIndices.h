#ifndef _ROS_jsk_recognition_msgs_ClusterPointIndices_h
#define _ROS_jsk_recognition_msgs_ClusterPointIndices_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "pcl_msgs/PointIndices.h"

namespace jsk_recognition_msgs
{

  class ClusterPointIndices : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t cluster_indices_length;
      pcl_msgs::PointIndices st_cluster_indices;
      pcl_msgs::PointIndices * cluster_indices;

    ClusterPointIndices():
      header(),
      cluster_indices_length(0), cluster_indices(NULL)
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
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ClusterPointIndices"; };
    const char * getMD5(){ return "d43e94ea5e491effac7685a42b7b9d14"; };

  };

}
#endif