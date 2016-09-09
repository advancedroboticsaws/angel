#ifndef _ROS_robot_calibration_msgs_Observation_h
#define _ROS_robot_calibration_msgs_Observation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PointStamped.h"
#include "robot_calibration_msgs/ExtendedCameraInfo.h"
#include "sensor_msgs/PointCloud2.h"
#include "sensor_msgs/Image.h"

namespace robot_calibration_msgs
{

  class Observation : public ros::Msg
  {
    public:
      const char* sensor_name;
      uint8_t features_length;
      geometry_msgs::PointStamped st_features;
      geometry_msgs::PointStamped * features;
      robot_calibration_msgs::ExtendedCameraInfo ext_camera_info;
      sensor_msgs::PointCloud2 cloud;
      sensor_msgs::Image image;

    Observation():
      sensor_name(""),
      features_length(0), features(NULL),
      ext_camera_info(),
      cloud(),
      image()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_sensor_name = strlen(this->sensor_name);
      memcpy(outbuffer + offset, &length_sensor_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->sensor_name, length_sensor_name);
      offset += length_sensor_name;
      *(outbuffer + offset++) = features_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < features_length; i++){
      offset += this->features[i].serialize(outbuffer + offset);
      }
      offset += this->ext_camera_info.serialize(outbuffer + offset);
      offset += this->cloud.serialize(outbuffer + offset);
      offset += this->image.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_sensor_name;
      memcpy(&length_sensor_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_sensor_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_sensor_name-1]=0;
      this->sensor_name = (char *)(inbuffer + offset-1);
      offset += length_sensor_name;
      uint8_t features_lengthT = *(inbuffer + offset++);
      if(features_lengthT > features_length)
        this->features = (geometry_msgs::PointStamped*)realloc(this->features, features_lengthT * sizeof(geometry_msgs::PointStamped));
      offset += 3;
      features_length = features_lengthT;
      for( uint8_t i = 0; i < features_length; i++){
      offset += this->st_features.deserialize(inbuffer + offset);
        memcpy( &(this->features[i]), &(this->st_features), sizeof(geometry_msgs::PointStamped));
      }
      offset += this->ext_camera_info.deserialize(inbuffer + offset);
      offset += this->cloud.deserialize(inbuffer + offset);
      offset += this->image.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "robot_calibration_msgs/Observation"; };
    const char * getMD5(){ return "b5e5b7c2eb5f83de33806b676db440c9"; };

  };

}
#endif