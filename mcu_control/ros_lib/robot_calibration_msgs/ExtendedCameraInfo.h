#ifndef _ROS_robot_calibration_msgs_ExtendedCameraInfo_h
#define _ROS_robot_calibration_msgs_ExtendedCameraInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/CameraInfo.h"
#include "robot_calibration_msgs/CameraParameter.h"

namespace robot_calibration_msgs
{

  class ExtendedCameraInfo : public ros::Msg
  {
    public:
      sensor_msgs::CameraInfo camera_info;
      uint8_t parameters_length;
      robot_calibration_msgs::CameraParameter st_parameters;
      robot_calibration_msgs::CameraParameter * parameters;

    ExtendedCameraInfo():
      camera_info(),
      parameters_length(0), parameters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->camera_info.serialize(outbuffer + offset);
      *(outbuffer + offset++) = parameters_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < parameters_length; i++){
      offset += this->parameters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->camera_info.deserialize(inbuffer + offset);
      uint8_t parameters_lengthT = *(inbuffer + offset++);
      if(parameters_lengthT > parameters_length)
        this->parameters = (robot_calibration_msgs::CameraParameter*)realloc(this->parameters, parameters_lengthT * sizeof(robot_calibration_msgs::CameraParameter));
      offset += 3;
      parameters_length = parameters_lengthT;
      for( uint8_t i = 0; i < parameters_length; i++){
      offset += this->st_parameters.deserialize(inbuffer + offset);
        memcpy( &(this->parameters[i]), &(this->st_parameters), sizeof(robot_calibration_msgs::CameraParameter));
      }
     return offset;
    }

    const char * getType(){ return "robot_calibration_msgs/ExtendedCameraInfo"; };
    const char * getMD5(){ return "d35c5c887e3d90c7f6f9c5a697f44485"; };

  };

}
#endif