#ifndef _ROS_dynamixel_msgs_MotorStateList_h
#define _ROS_dynamixel_msgs_MotorStateList_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "dynamixel_msgs/MotorState.h"

namespace dynamixel_msgs
{

  class MotorStateList : public ros::Msg
  {
    public:
      uint8_t motor_states_length;
      dynamixel_msgs::MotorState st_motor_states;
      dynamixel_msgs::MotorState * motor_states;

    MotorStateList():
      motor_states_length(0), motor_states(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = motor_states_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < motor_states_length; i++){
      offset += this->motor_states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t motor_states_lengthT = *(inbuffer + offset++);
      if(motor_states_lengthT > motor_states_length)
        this->motor_states = (dynamixel_msgs::MotorState*)realloc(this->motor_states, motor_states_lengthT * sizeof(dynamixel_msgs::MotorState));
      offset += 3;
      motor_states_length = motor_states_lengthT;
      for( uint8_t i = 0; i < motor_states_length; i++){
      offset += this->st_motor_states.deserialize(inbuffer + offset);
        memcpy( &(this->motor_states[i]), &(this->st_motor_states), sizeof(dynamixel_msgs::MotorState));
      }
     return offset;
    }

    const char * getType(){ return "dynamixel_msgs/MotorStateList"; };
    const char * getMD5(){ return "9e94ccf6563ca78afce19eb097f9343c"; };

  };

}
#endif