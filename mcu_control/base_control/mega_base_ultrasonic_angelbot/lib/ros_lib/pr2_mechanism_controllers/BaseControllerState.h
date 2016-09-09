#ifndef _ROS_pr2_mechanism_controllers_BaseControllerState_h
#define _ROS_pr2_mechanism_controllers_BaseControllerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Twist.h"

namespace pr2_mechanism_controllers
{

  class BaseControllerState : public ros::Msg
  {
    public:
      geometry_msgs::Twist command;
      uint8_t joint_velocity_measured_length;
      float st_joint_velocity_measured;
      float * joint_velocity_measured;
      uint8_t joint_velocity_commanded_length;
      float st_joint_velocity_commanded;
      float * joint_velocity_commanded;
      uint8_t joint_velocity_error_length;
      float st_joint_velocity_error;
      float * joint_velocity_error;
      uint8_t joint_effort_measured_length;
      float st_joint_effort_measured;
      float * joint_effort_measured;
      uint8_t joint_effort_commanded_length;
      float st_joint_effort_commanded;
      float * joint_effort_commanded;
      uint8_t joint_effort_error_length;
      float st_joint_effort_error;
      float * joint_effort_error;
      uint8_t joint_names_length;
      char* st_joint_names;
      char* * joint_names;

    BaseControllerState():
      command(),
      joint_velocity_measured_length(0), joint_velocity_measured(NULL),
      joint_velocity_commanded_length(0), joint_velocity_commanded(NULL),
      joint_velocity_error_length(0), joint_velocity_error(NULL),
      joint_effort_measured_length(0), joint_effort_measured(NULL),
      joint_effort_commanded_length(0), joint_effort_commanded(NULL),
      joint_effort_error_length(0), joint_effort_error(NULL),
      joint_names_length(0), joint_names(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->command.serialize(outbuffer + offset);
      *(outbuffer + offset++) = joint_velocity_measured_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_velocity_measured_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_velocity_measured[i]);
      }
      *(outbuffer + offset++) = joint_velocity_commanded_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_velocity_commanded_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_velocity_commanded[i]);
      }
      *(outbuffer + offset++) = joint_velocity_error_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_velocity_error_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_velocity_error[i]);
      }
      *(outbuffer + offset++) = joint_effort_measured_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_effort_measured_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_effort_measured[i]);
      }
      *(outbuffer + offset++) = joint_effort_commanded_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_effort_commanded_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_effort_commanded[i]);
      }
      *(outbuffer + offset++) = joint_effort_error_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_effort_error_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_effort_error[i]);
      }
      *(outbuffer + offset++) = joint_names_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_names_length; i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      memcpy(outbuffer + offset, &length_joint_namesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->command.deserialize(inbuffer + offset);
      uint8_t joint_velocity_measured_lengthT = *(inbuffer + offset++);
      if(joint_velocity_measured_lengthT > joint_velocity_measured_length)
        this->joint_velocity_measured = (float*)realloc(this->joint_velocity_measured, joint_velocity_measured_lengthT * sizeof(float));
      offset += 3;
      joint_velocity_measured_length = joint_velocity_measured_lengthT;
      for( uint8_t i = 0; i < joint_velocity_measured_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_joint_velocity_measured));
        memcpy( &(this->joint_velocity_measured[i]), &(this->st_joint_velocity_measured), sizeof(float));
      }
      uint8_t joint_velocity_commanded_lengthT = *(inbuffer + offset++);
      if(joint_velocity_commanded_lengthT > joint_velocity_commanded_length)
        this->joint_velocity_commanded = (float*)realloc(this->joint_velocity_commanded, joint_velocity_commanded_lengthT * sizeof(float));
      offset += 3;
      joint_velocity_commanded_length = joint_velocity_commanded_lengthT;
      for( uint8_t i = 0; i < joint_velocity_commanded_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_joint_velocity_commanded));
        memcpy( &(this->joint_velocity_commanded[i]), &(this->st_joint_velocity_commanded), sizeof(float));
      }
      uint8_t joint_velocity_error_lengthT = *(inbuffer + offset++);
      if(joint_velocity_error_lengthT > joint_velocity_error_length)
        this->joint_velocity_error = (float*)realloc(this->joint_velocity_error, joint_velocity_error_lengthT * sizeof(float));
      offset += 3;
      joint_velocity_error_length = joint_velocity_error_lengthT;
      for( uint8_t i = 0; i < joint_velocity_error_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_joint_velocity_error));
        memcpy( &(this->joint_velocity_error[i]), &(this->st_joint_velocity_error), sizeof(float));
      }
      uint8_t joint_effort_measured_lengthT = *(inbuffer + offset++);
      if(joint_effort_measured_lengthT > joint_effort_measured_length)
        this->joint_effort_measured = (float*)realloc(this->joint_effort_measured, joint_effort_measured_lengthT * sizeof(float));
      offset += 3;
      joint_effort_measured_length = joint_effort_measured_lengthT;
      for( uint8_t i = 0; i < joint_effort_measured_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_joint_effort_measured));
        memcpy( &(this->joint_effort_measured[i]), &(this->st_joint_effort_measured), sizeof(float));
      }
      uint8_t joint_effort_commanded_lengthT = *(inbuffer + offset++);
      if(joint_effort_commanded_lengthT > joint_effort_commanded_length)
        this->joint_effort_commanded = (float*)realloc(this->joint_effort_commanded, joint_effort_commanded_lengthT * sizeof(float));
      offset += 3;
      joint_effort_commanded_length = joint_effort_commanded_lengthT;
      for( uint8_t i = 0; i < joint_effort_commanded_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_joint_effort_commanded));
        memcpy( &(this->joint_effort_commanded[i]), &(this->st_joint_effort_commanded), sizeof(float));
      }
      uint8_t joint_effort_error_lengthT = *(inbuffer + offset++);
      if(joint_effort_error_lengthT > joint_effort_error_length)
        this->joint_effort_error = (float*)realloc(this->joint_effort_error, joint_effort_error_lengthT * sizeof(float));
      offset += 3;
      joint_effort_error_length = joint_effort_error_lengthT;
      for( uint8_t i = 0; i < joint_effort_error_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_joint_effort_error));
        memcpy( &(this->joint_effort_error[i]), &(this->st_joint_effort_error), sizeof(float));
      }
      uint8_t joint_names_lengthT = *(inbuffer + offset++);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (char**)realloc(this->joint_names, joint_names_lengthT * sizeof(char*));
      offset += 3;
      joint_names_length = joint_names_lengthT;
      for( uint8_t i = 0; i < joint_names_length; i++){
      uint32_t length_st_joint_names;
      memcpy(&length_st_joint_names, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joint_names-1]=0;
      this->st_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "pr2_mechanism_controllers/BaseControllerState"; };
    const char * getMD5(){ return "7a488aa492f9175d5fa35e22e56c4b28"; };

  };

}
#endif