#ifndef _ROS_robot_calibration_msgs_CalibrationData_h
#define _ROS_robot_calibration_msgs_CalibrationData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"
#include "robot_calibration_msgs/Observation.h"

namespace robot_calibration_msgs
{

  class CalibrationData : public ros::Msg
  {
    public:
      sensor_msgs::JointState joint_states;
      uint8_t observations_length;
      robot_calibration_msgs::Observation st_observations;
      robot_calibration_msgs::Observation * observations;

    CalibrationData():
      joint_states(),
      observations_length(0), observations(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_states.serialize(outbuffer + offset);
      *(outbuffer + offset++) = observations_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < observations_length; i++){
      offset += this->observations[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_states.deserialize(inbuffer + offset);
      uint8_t observations_lengthT = *(inbuffer + offset++);
      if(observations_lengthT > observations_length)
        this->observations = (robot_calibration_msgs::Observation*)realloc(this->observations, observations_lengthT * sizeof(robot_calibration_msgs::Observation));
      offset += 3;
      observations_length = observations_lengthT;
      for( uint8_t i = 0; i < observations_length; i++){
      offset += this->st_observations.deserialize(inbuffer + offset);
        memcpy( &(this->observations[i]), &(this->st_observations), sizeof(robot_calibration_msgs::Observation));
      }
     return offset;
    }

    const char * getType(){ return "robot_calibration_msgs/CalibrationData"; };
    const char * getMD5(){ return "a9a1a8b53ea9e13de6dae25608004191"; };

  };

}
#endif