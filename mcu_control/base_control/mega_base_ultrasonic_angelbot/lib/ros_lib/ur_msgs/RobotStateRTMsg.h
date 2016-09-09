#ifndef _ROS_ur_msgs_RobotStateRTMsg_h
#define _ROS_ur_msgs_RobotStateRTMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ur_msgs
{

  class RobotStateRTMsg : public ros::Msg
  {
    public:
      float time;
      uint8_t q_target_length;
      float st_q_target;
      float * q_target;
      uint8_t qd_target_length;
      float st_qd_target;
      float * qd_target;
      uint8_t qdd_target_length;
      float st_qdd_target;
      float * qdd_target;
      uint8_t i_target_length;
      float st_i_target;
      float * i_target;
      uint8_t m_target_length;
      float st_m_target;
      float * m_target;
      uint8_t q_actual_length;
      float st_q_actual;
      float * q_actual;
      uint8_t qd_actual_length;
      float st_qd_actual;
      float * qd_actual;
      uint8_t i_actual_length;
      float st_i_actual;
      float * i_actual;
      uint8_t tool_acc_values_length;
      float st_tool_acc_values;
      float * tool_acc_values;
      uint8_t tcp_force_length;
      float st_tcp_force;
      float * tcp_force;
      uint8_t tool_vector_length;
      float st_tool_vector;
      float * tool_vector;
      uint8_t tcp_speed_length;
      float st_tcp_speed;
      float * tcp_speed;
      float digital_input_bits;
      uint8_t motor_temperatures_length;
      float st_motor_temperatures;
      float * motor_temperatures;
      float controller_timer;
      float test_value;
      float robot_mode;
      uint8_t joint_modes_length;
      float st_joint_modes;
      float * joint_modes;

    RobotStateRTMsg():
      time(0),
      q_target_length(0), q_target(NULL),
      qd_target_length(0), qd_target(NULL),
      qdd_target_length(0), qdd_target(NULL),
      i_target_length(0), i_target(NULL),
      m_target_length(0), m_target(NULL),
      q_actual_length(0), q_actual(NULL),
      qd_actual_length(0), qd_actual(NULL),
      i_actual_length(0), i_actual(NULL),
      tool_acc_values_length(0), tool_acc_values(NULL),
      tcp_force_length(0), tcp_force(NULL),
      tool_vector_length(0), tool_vector(NULL),
      tcp_speed_length(0), tcp_speed(NULL),
      digital_input_bits(0),
      motor_temperatures_length(0), motor_temperatures(NULL),
      controller_timer(0),
      test_value(0),
      robot_mode(0),
      joint_modes_length(0), joint_modes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->time);
      *(outbuffer + offset++) = q_target_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < q_target_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->q_target[i]);
      }
      *(outbuffer + offset++) = qd_target_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < qd_target_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qd_target[i]);
      }
      *(outbuffer + offset++) = qdd_target_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < qdd_target_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qdd_target[i]);
      }
      *(outbuffer + offset++) = i_target_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < i_target_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->i_target[i]);
      }
      *(outbuffer + offset++) = m_target_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < m_target_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->m_target[i]);
      }
      *(outbuffer + offset++) = q_actual_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < q_actual_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->q_actual[i]);
      }
      *(outbuffer + offset++) = qd_actual_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < qd_actual_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->qd_actual[i]);
      }
      *(outbuffer + offset++) = i_actual_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < i_actual_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->i_actual[i]);
      }
      *(outbuffer + offset++) = tool_acc_values_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tool_acc_values_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tool_acc_values[i]);
      }
      *(outbuffer + offset++) = tcp_force_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tcp_force_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tcp_force[i]);
      }
      *(outbuffer + offset++) = tool_vector_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tool_vector_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tool_vector[i]);
      }
      *(outbuffer + offset++) = tcp_speed_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tcp_speed_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tcp_speed[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->digital_input_bits);
      *(outbuffer + offset++) = motor_temperatures_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < motor_temperatures_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_temperatures[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->controller_timer);
      offset += serializeAvrFloat64(outbuffer + offset, this->test_value);
      offset += serializeAvrFloat64(outbuffer + offset, this->robot_mode);
      *(outbuffer + offset++) = joint_modes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < joint_modes_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->joint_modes[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->time));
      uint8_t q_target_lengthT = *(inbuffer + offset++);
      if(q_target_lengthT > q_target_length)
        this->q_target = (float*)realloc(this->q_target, q_target_lengthT * sizeof(float));
      offset += 3;
      q_target_length = q_target_lengthT;
      for( uint8_t i = 0; i < q_target_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_q_target));
        memcpy( &(this->q_target[i]), &(this->st_q_target), sizeof(float));
      }
      uint8_t qd_target_lengthT = *(inbuffer + offset++);
      if(qd_target_lengthT > qd_target_length)
        this->qd_target = (float*)realloc(this->qd_target, qd_target_lengthT * sizeof(float));
      offset += 3;
      qd_target_length = qd_target_lengthT;
      for( uint8_t i = 0; i < qd_target_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_qd_target));
        memcpy( &(this->qd_target[i]), &(this->st_qd_target), sizeof(float));
      }
      uint8_t qdd_target_lengthT = *(inbuffer + offset++);
      if(qdd_target_lengthT > qdd_target_length)
        this->qdd_target = (float*)realloc(this->qdd_target, qdd_target_lengthT * sizeof(float));
      offset += 3;
      qdd_target_length = qdd_target_lengthT;
      for( uint8_t i = 0; i < qdd_target_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_qdd_target));
        memcpy( &(this->qdd_target[i]), &(this->st_qdd_target), sizeof(float));
      }
      uint8_t i_target_lengthT = *(inbuffer + offset++);
      if(i_target_lengthT > i_target_length)
        this->i_target = (float*)realloc(this->i_target, i_target_lengthT * sizeof(float));
      offset += 3;
      i_target_length = i_target_lengthT;
      for( uint8_t i = 0; i < i_target_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_i_target));
        memcpy( &(this->i_target[i]), &(this->st_i_target), sizeof(float));
      }
      uint8_t m_target_lengthT = *(inbuffer + offset++);
      if(m_target_lengthT > m_target_length)
        this->m_target = (float*)realloc(this->m_target, m_target_lengthT * sizeof(float));
      offset += 3;
      m_target_length = m_target_lengthT;
      for( uint8_t i = 0; i < m_target_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_m_target));
        memcpy( &(this->m_target[i]), &(this->st_m_target), sizeof(float));
      }
      uint8_t q_actual_lengthT = *(inbuffer + offset++);
      if(q_actual_lengthT > q_actual_length)
        this->q_actual = (float*)realloc(this->q_actual, q_actual_lengthT * sizeof(float));
      offset += 3;
      q_actual_length = q_actual_lengthT;
      for( uint8_t i = 0; i < q_actual_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_q_actual));
        memcpy( &(this->q_actual[i]), &(this->st_q_actual), sizeof(float));
      }
      uint8_t qd_actual_lengthT = *(inbuffer + offset++);
      if(qd_actual_lengthT > qd_actual_length)
        this->qd_actual = (float*)realloc(this->qd_actual, qd_actual_lengthT * sizeof(float));
      offset += 3;
      qd_actual_length = qd_actual_lengthT;
      for( uint8_t i = 0; i < qd_actual_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_qd_actual));
        memcpy( &(this->qd_actual[i]), &(this->st_qd_actual), sizeof(float));
      }
      uint8_t i_actual_lengthT = *(inbuffer + offset++);
      if(i_actual_lengthT > i_actual_length)
        this->i_actual = (float*)realloc(this->i_actual, i_actual_lengthT * sizeof(float));
      offset += 3;
      i_actual_length = i_actual_lengthT;
      for( uint8_t i = 0; i < i_actual_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_i_actual));
        memcpy( &(this->i_actual[i]), &(this->st_i_actual), sizeof(float));
      }
      uint8_t tool_acc_values_lengthT = *(inbuffer + offset++);
      if(tool_acc_values_lengthT > tool_acc_values_length)
        this->tool_acc_values = (float*)realloc(this->tool_acc_values, tool_acc_values_lengthT * sizeof(float));
      offset += 3;
      tool_acc_values_length = tool_acc_values_lengthT;
      for( uint8_t i = 0; i < tool_acc_values_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_tool_acc_values));
        memcpy( &(this->tool_acc_values[i]), &(this->st_tool_acc_values), sizeof(float));
      }
      uint8_t tcp_force_lengthT = *(inbuffer + offset++);
      if(tcp_force_lengthT > tcp_force_length)
        this->tcp_force = (float*)realloc(this->tcp_force, tcp_force_lengthT * sizeof(float));
      offset += 3;
      tcp_force_length = tcp_force_lengthT;
      for( uint8_t i = 0; i < tcp_force_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_tcp_force));
        memcpy( &(this->tcp_force[i]), &(this->st_tcp_force), sizeof(float));
      }
      uint8_t tool_vector_lengthT = *(inbuffer + offset++);
      if(tool_vector_lengthT > tool_vector_length)
        this->tool_vector = (float*)realloc(this->tool_vector, tool_vector_lengthT * sizeof(float));
      offset += 3;
      tool_vector_length = tool_vector_lengthT;
      for( uint8_t i = 0; i < tool_vector_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_tool_vector));
        memcpy( &(this->tool_vector[i]), &(this->st_tool_vector), sizeof(float));
      }
      uint8_t tcp_speed_lengthT = *(inbuffer + offset++);
      if(tcp_speed_lengthT > tcp_speed_length)
        this->tcp_speed = (float*)realloc(this->tcp_speed, tcp_speed_lengthT * sizeof(float));
      offset += 3;
      tcp_speed_length = tcp_speed_lengthT;
      for( uint8_t i = 0; i < tcp_speed_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_tcp_speed));
        memcpy( &(this->tcp_speed[i]), &(this->st_tcp_speed), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->digital_input_bits));
      uint8_t motor_temperatures_lengthT = *(inbuffer + offset++);
      if(motor_temperatures_lengthT > motor_temperatures_length)
        this->motor_temperatures = (float*)realloc(this->motor_temperatures, motor_temperatures_lengthT * sizeof(float));
      offset += 3;
      motor_temperatures_length = motor_temperatures_lengthT;
      for( uint8_t i = 0; i < motor_temperatures_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_motor_temperatures));
        memcpy( &(this->motor_temperatures[i]), &(this->st_motor_temperatures), sizeof(float));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->controller_timer));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->test_value));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->robot_mode));
      uint8_t joint_modes_lengthT = *(inbuffer + offset++);
      if(joint_modes_lengthT > joint_modes_length)
        this->joint_modes = (float*)realloc(this->joint_modes, joint_modes_lengthT * sizeof(float));
      offset += 3;
      joint_modes_length = joint_modes_lengthT;
      for( uint8_t i = 0; i < joint_modes_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_joint_modes));
        memcpy( &(this->joint_modes[i]), &(this->st_joint_modes), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "ur_msgs/RobotStateRTMsg"; };
    const char * getMD5(){ return "ce6feddd3ccb4ca7dbcd0ff105b603c7"; };

  };

}
#endif