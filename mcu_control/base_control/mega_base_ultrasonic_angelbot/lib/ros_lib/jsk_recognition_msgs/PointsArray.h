#ifndef _ROS_jsk_recognition_msgs_PointsArray_h
#define _ROS_jsk_recognition_msgs_PointsArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/PointCloud2.h"

namespace jsk_recognition_msgs
{

  class PointsArray : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t cloud_list_length;
      sensor_msgs::PointCloud2 st_cloud_list;
      sensor_msgs::PointCloud2 * cloud_list;

    PointsArray():
      header(),
      cloud_list_length(0), cloud_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = cloud_list_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < cloud_list_length; i++){
      offset += this->cloud_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t cloud_list_lengthT = *(inbuffer + offset++);
      if(cloud_list_lengthT > cloud_list_length)
        this->cloud_list = (sensor_msgs::PointCloud2*)realloc(this->cloud_list, cloud_list_lengthT * sizeof(sensor_msgs::PointCloud2));
      offset += 3;
      cloud_list_length = cloud_list_lengthT;
      for( uint8_t i = 0; i < cloud_list_length; i++){
      offset += this->st_cloud_list.deserialize(inbuffer + offset);
        memcpy( &(this->cloud_list[i]), &(this->st_cloud_list), sizeof(sensor_msgs::PointCloud2));
      }
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/PointsArray"; };
    const char * getMD5(){ return "0aa7e57c9da77fc1a0d8277bba5672b1"; };

  };

}
#endif