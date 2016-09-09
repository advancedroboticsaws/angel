#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperFindContactData_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperFindContactData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "pr2_gripper_sensor_msgs/PR2GripperSensorRTState.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperFindContactData : public ros::Msg
  {
    public:
      ros::Time stamp;
      bool contact_conditions_met;
      bool left_fingertip_pad_contact;
      bool right_fingertip_pad_contact;
      float left_fingertip_pad_force;
      float right_fingertip_pad_force;
      float joint_position;
      float joint_effort;
      pr2_gripper_sensor_msgs::PR2GripperSensorRTState rtstate;

    PR2GripperFindContactData():
      stamp(),
      contact_conditions_met(0),
      left_fingertip_pad_contact(0),
      right_fingertip_pad_contact(0),
      left_fingertip_pad_force(0),
      right_fingertip_pad_force(0),
      joint_position(0),
      joint_effort(0),
      rtstate()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      union {
        bool real;
        uint8_t base;
      } u_contact_conditions_met;
      u_contact_conditions_met.real = this->contact_conditions_met;
      *(outbuffer + offset + 0) = (u_contact_conditions_met.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contact_conditions_met);
      union {
        bool real;
        uint8_t base;
      } u_left_fingertip_pad_contact;
      u_left_fingertip_pad_contact.real = this->left_fingertip_pad_contact;
      *(outbuffer + offset + 0) = (u_left_fingertip_pad_contact.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_fingertip_pad_contact);
      union {
        bool real;
        uint8_t base;
      } u_right_fingertip_pad_contact;
      u_right_fingertip_pad_contact.real = this->right_fingertip_pad_contact;
      *(outbuffer + offset + 0) = (u_right_fingertip_pad_contact.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_fingertip_pad_contact);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_fingertip_pad_force);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_fingertip_pad_force);
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_position);
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_effort);
      offset += this->rtstate.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      union {
        bool real;
        uint8_t base;
      } u_contact_conditions_met;
      u_contact_conditions_met.base = 0;
      u_contact_conditions_met.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contact_conditions_met = u_contact_conditions_met.real;
      offset += sizeof(this->contact_conditions_met);
      union {
        bool real;
        uint8_t base;
      } u_left_fingertip_pad_contact;
      u_left_fingertip_pad_contact.base = 0;
      u_left_fingertip_pad_contact.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_fingertip_pad_contact = u_left_fingertip_pad_contact.real;
      offset += sizeof(this->left_fingertip_pad_contact);
      union {
        bool real;
        uint8_t base;
      } u_right_fingertip_pad_contact;
      u_right_fingertip_pad_contact.base = 0;
      u_right_fingertip_pad_contact.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_fingertip_pad_contact = u_right_fingertip_pad_contact.real;
      offset += sizeof(this->right_fingertip_pad_contact);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_fingertip_pad_force));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_fingertip_pad_force));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->joint_position));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->joint_effort));
      offset += this->rtstate.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperFindContactData"; };
    const char * getMD5(){ return "bc53e3dc7d19b896ca9b5ea205d54b91"; };

  };

}
#endif