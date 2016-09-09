#ifndef _ROS_robot_calibration_msgs_CaptureConfig_h
#define _ROS_robot_calibration_msgs_CaptureConfig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"

namespace robot_calibration_msgs
{

  class CaptureConfig : public ros::Msg
  {
    public:
      sensor_msgs::JointState joint_states;
      uint8_t features_length;
      char* st_features;
      char* * features;

    CaptureConfig():
      joint_states(),
      features_length(0), features(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_states.serialize(outbuffer + offset);
      *(outbuffer + offset++) = features_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < features_length; i++){
      uint32_t length_featuresi = strlen(this->features[i]);
      memcpy(outbuffer + offset, &length_featuresi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->features[i], length_featuresi);
      offset += length_featuresi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_states.deserialize(inbuffer + offset);
      uint8_t features_lengthT = *(inbuffer + offset++);
      if(features_lengthT > features_length)
        this->features = (char**)realloc(this->features, features_lengthT * sizeof(char*));
      offset += 3;
      features_length = features_lengthT;
      for( uint8_t i = 0; i < features_length; i++){
      uint32_t length_st_features;
      memcpy(&length_st_features, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_features; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_features-1]=0;
      this->st_features = (char *)(inbuffer + offset-1);
      offset += length_st_features;
        memcpy( &(this->features[i]), &(this->st_features), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "robot_calibration_msgs/CaptureConfig"; };
    const char * getMD5(){ return "f347b595aa5cb3d9820e25d6d41f25cd"; };

  };

}
#endif