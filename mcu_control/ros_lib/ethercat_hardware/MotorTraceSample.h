#ifndef _ROS_ethercat_hardware_MotorTraceSample_h
#define _ROS_ethercat_hardware_MotorTraceSample_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ethercat_hardware
{

  class MotorTraceSample : public ros::Msg
  {
    public:
      float timestamp;
      bool enabled;
      float supply_voltage;
      float measured_motor_voltage;
      float programmed_pwm;
      float executed_current;
      float measured_current;
      float velocity;
      float encoder_position;
      uint32_t encoder_error_count;
      float motor_voltage_error_limit;
      float filtered_motor_voltage_error;
      float filtered_abs_motor_voltage_error;
      float filtered_measured_voltage_error;
      float filtered_abs_measured_voltage_error;
      float filtered_current_error;
      float filtered_abs_current_error;

    MotorTraceSample():
      timestamp(0),
      enabled(0),
      supply_voltage(0),
      measured_motor_voltage(0),
      programmed_pwm(0),
      executed_current(0),
      measured_current(0),
      velocity(0),
      encoder_position(0),
      encoder_error_count(0),
      motor_voltage_error_limit(0),
      filtered_motor_voltage_error(0),
      filtered_abs_motor_voltage_error(0),
      filtered_measured_voltage_error(0),
      filtered_abs_measured_voltage_error(0),
      filtered_current_error(0),
      filtered_abs_current_error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->timestamp);
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.real = this->enabled;
      *(outbuffer + offset + 0) = (u_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enabled);
      offset += serializeAvrFloat64(outbuffer + offset, this->supply_voltage);
      offset += serializeAvrFloat64(outbuffer + offset, this->measured_motor_voltage);
      offset += serializeAvrFloat64(outbuffer + offset, this->programmed_pwm);
      offset += serializeAvrFloat64(outbuffer + offset, this->executed_current);
      offset += serializeAvrFloat64(outbuffer + offset, this->measured_current);
      offset += serializeAvrFloat64(outbuffer + offset, this->velocity);
      offset += serializeAvrFloat64(outbuffer + offset, this->encoder_position);
      *(outbuffer + offset + 0) = (this->encoder_error_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->encoder_error_count >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->encoder_error_count >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->encoder_error_count >> (8 * 3)) & 0xFF;
      offset += sizeof(this->encoder_error_count);
      offset += serializeAvrFloat64(outbuffer + offset, this->motor_voltage_error_limit);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_motor_voltage_error);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_abs_motor_voltage_error);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_measured_voltage_error);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_abs_measured_voltage_error);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_current_error);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_abs_current_error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->timestamp));
      union {
        bool real;
        uint8_t base;
      } u_enabled;
      u_enabled.base = 0;
      u_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enabled = u_enabled.real;
      offset += sizeof(this->enabled);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->supply_voltage));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->measured_motor_voltage));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->programmed_pwm));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->executed_current));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->measured_current));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->velocity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->encoder_position));
      this->encoder_error_count =  ((uint32_t) (*(inbuffer + offset)));
      this->encoder_error_count |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->encoder_error_count |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->encoder_error_count |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->encoder_error_count);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->motor_voltage_error_limit));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_motor_voltage_error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_abs_motor_voltage_error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_measured_voltage_error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_abs_measured_voltage_error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_current_error));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_abs_current_error));
     return offset;
    }

    const char * getType(){ return "ethercat_hardware/MotorTraceSample"; };
    const char * getMD5(){ return "3734a66334bc2033448f9c561d39c5e0"; };

  };

}
#endif