#ifndef _ROS_fetch_driver_msgs_GripperState_h
#define _ROS_fetch_driver_msgs_GripperState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "fetch_driver_msgs/BoardState.h"
#include "fetch_driver_msgs/MotorState.h"
#include "fetch_driver_msgs/JointState.h"

namespace fetch_driver_msgs
{

  class GripperState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      bool ready;
      bool faulted;
      uint8_t boards_length;
      fetch_driver_msgs::BoardState st_boards;
      fetch_driver_msgs::BoardState * boards;
      uint8_t motors_length;
      fetch_driver_msgs::MotorState st_motors;
      fetch_driver_msgs::MotorState * motors;
      uint8_t joints_length;
      fetch_driver_msgs::JointState st_joints;
      fetch_driver_msgs::JointState * joints;

    GripperState():
      header(),
      ready(0),
      faulted(0),
      boards_length(0), boards(NULL),
      motors_length(0), motors(NULL),
      joints_length(0), joints(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_ready;
      u_ready.real = this->ready;
      *(outbuffer + offset + 0) = (u_ready.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ready);
      union {
        bool real;
        uint8_t base;
      } u_faulted;
      u_faulted.real = this->faulted;
      *(outbuffer + offset + 0) = (u_faulted.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->faulted);
      *(outbuffer + offset++) = boards_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < boards_length; i++){
      offset += this->boards[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = motors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < motors_length; i++){
      offset += this->motors[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = joints_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joints_length; i++){
      offset += this->joints[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_ready;
      u_ready.base = 0;
      u_ready.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ready = u_ready.real;
      offset += sizeof(this->ready);
      union {
        bool real;
        uint8_t base;
      } u_faulted;
      u_faulted.base = 0;
      u_faulted.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->faulted = u_faulted.real;
      offset += sizeof(this->faulted);
      uint8_t boards_lengthT = *(inbuffer + offset++);
      if(boards_lengthT > boards_length)
        this->boards = (fetch_driver_msgs::BoardState*)realloc(this->boards, boards_lengthT * sizeof(fetch_driver_msgs::BoardState));
      offset += 3;
      boards_length = boards_lengthT;
      for( uint8_t i = 0; i < boards_length; i++){
      offset += this->st_boards.deserialize(inbuffer + offset);
        memcpy( &(this->boards[i]), &(this->st_boards), sizeof(fetch_driver_msgs::BoardState));
      }
      uint8_t motors_lengthT = *(inbuffer + offset++);
      if(motors_lengthT > motors_length)
        this->motors = (fetch_driver_msgs::MotorState*)realloc(this->motors, motors_lengthT * sizeof(fetch_driver_msgs::MotorState));
      offset += 3;
      motors_length = motors_lengthT;
      for( uint8_t i = 0; i < motors_length; i++){
      offset += this->st_motors.deserialize(inbuffer + offset);
        memcpy( &(this->motors[i]), &(this->st_motors), sizeof(fetch_driver_msgs::MotorState));
      }
      uint8_t joints_lengthT = *(inbuffer + offset++);
      if(joints_lengthT > joints_length)
        this->joints = (fetch_driver_msgs::JointState*)realloc(this->joints, joints_lengthT * sizeof(fetch_driver_msgs::JointState));
      offset += 3;
      joints_length = joints_lengthT;
      for( uint8_t i = 0; i < joints_length; i++){
      offset += this->st_joints.deserialize(inbuffer + offset);
        memcpy( &(this->joints[i]), &(this->st_joints), sizeof(fetch_driver_msgs::JointState));
      }
     return offset;
    }

    const char * getType(){ return "fetch_driver_msgs/GripperState"; };
    const char * getMD5(){ return "3b442b195034293254bd9964c5dac688"; };

  };

}
#endif