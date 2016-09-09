#ifndef _ROS_fetch_driver_msgs_ChargerState_h
#define _ROS_fetch_driver_msgs_ChargerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fetch_driver_msgs
{

  class ChargerState : public ros::Msg
  {
    public:
      uint8_t state;
      uint8_t error;
      uint8_t charging_mode;
      uint8_t limit_cause;
      uint8_t balancing_mode;
      float battery_voltage;
      float battery_half_voltage;
      float charger_voltage;
      float supply_voltage;
      float phase1_current;
      float phase2_current;
      float charger_temp;
      float battery_temp;
      float supply_connector_temp;
      float fan_speed;
      float battery_capacity;
      float battery_energy;

    ChargerState():
      state(0),
      error(0),
      charging_mode(0),
      limit_cause(0),
      balancing_mode(0),
      battery_voltage(0),
      battery_half_voltage(0),
      charger_voltage(0),
      supply_voltage(0),
      phase1_current(0),
      phase2_current(0),
      charger_temp(0),
      battery_temp(0),
      supply_connector_temp(0),
      fan_speed(0),
      battery_capacity(0),
      battery_energy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      *(outbuffer + offset + 0) = (this->error >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error);
      *(outbuffer + offset + 0) = (this->charging_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charging_mode);
      *(outbuffer + offset + 0) = (this->limit_cause >> (8 * 0)) & 0xFF;
      offset += sizeof(this->limit_cause);
      *(outbuffer + offset + 0) = (this->balancing_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->balancing_mode);
      union {
        float real;
        uint32_t base;
      } u_battery_voltage;
      u_battery_voltage.real = this->battery_voltage;
      *(outbuffer + offset + 0) = (u_battery_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_battery_half_voltage;
      u_battery_half_voltage.real = this->battery_half_voltage;
      *(outbuffer + offset + 0) = (u_battery_half_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_half_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_half_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_half_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_half_voltage);
      union {
        float real;
        uint32_t base;
      } u_charger_voltage;
      u_charger_voltage.real = this->charger_voltage;
      *(outbuffer + offset + 0) = (u_charger_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charger_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charger_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charger_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charger_voltage);
      union {
        float real;
        uint32_t base;
      } u_supply_voltage;
      u_supply_voltage.real = this->supply_voltage;
      *(outbuffer + offset + 0) = (u_supply_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_supply_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_supply_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_supply_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->supply_voltage);
      union {
        float real;
        uint32_t base;
      } u_phase1_current;
      u_phase1_current.real = this->phase1_current;
      *(outbuffer + offset + 0) = (u_phase1_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_phase1_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_phase1_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_phase1_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phase1_current);
      union {
        float real;
        uint32_t base;
      } u_phase2_current;
      u_phase2_current.real = this->phase2_current;
      *(outbuffer + offset + 0) = (u_phase2_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_phase2_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_phase2_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_phase2_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phase2_current);
      union {
        float real;
        uint32_t base;
      } u_charger_temp;
      u_charger_temp.real = this->charger_temp;
      *(outbuffer + offset + 0) = (u_charger_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charger_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charger_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charger_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charger_temp);
      union {
        float real;
        uint32_t base;
      } u_battery_temp;
      u_battery_temp.real = this->battery_temp;
      *(outbuffer + offset + 0) = (u_battery_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_temp);
      union {
        float real;
        uint32_t base;
      } u_supply_connector_temp;
      u_supply_connector_temp.real = this->supply_connector_temp;
      *(outbuffer + offset + 0) = (u_supply_connector_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_supply_connector_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_supply_connector_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_supply_connector_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->supply_connector_temp);
      union {
        float real;
        uint32_t base;
      } u_fan_speed;
      u_fan_speed.real = this->fan_speed;
      *(outbuffer + offset + 0) = (u_fan_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fan_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fan_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fan_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fan_speed);
      union {
        float real;
        uint32_t base;
      } u_battery_capacity;
      u_battery_capacity.real = this->battery_capacity;
      *(outbuffer + offset + 0) = (u_battery_capacity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_capacity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_capacity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_capacity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_capacity);
      union {
        float real;
        uint32_t base;
      } u_battery_energy;
      u_battery_energy.real = this->battery_energy;
      *(outbuffer + offset + 0) = (u_battery_energy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_energy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_energy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_energy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_energy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
      this->error =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error);
      this->charging_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->charging_mode);
      this->limit_cause =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->limit_cause);
      this->balancing_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->balancing_mode);
      union {
        float real;
        uint32_t base;
      } u_battery_voltage;
      u_battery_voltage.base = 0;
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_voltage = u_battery_voltage.real;
      offset += sizeof(this->battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_battery_half_voltage;
      u_battery_half_voltage.base = 0;
      u_battery_half_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_half_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_half_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_half_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_half_voltage = u_battery_half_voltage.real;
      offset += sizeof(this->battery_half_voltage);
      union {
        float real;
        uint32_t base;
      } u_charger_voltage;
      u_charger_voltage.base = 0;
      u_charger_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charger_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charger_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charger_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->charger_voltage = u_charger_voltage.real;
      offset += sizeof(this->charger_voltage);
      union {
        float real;
        uint32_t base;
      } u_supply_voltage;
      u_supply_voltage.base = 0;
      u_supply_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_supply_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_supply_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_supply_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->supply_voltage = u_supply_voltage.real;
      offset += sizeof(this->supply_voltage);
      union {
        float real;
        uint32_t base;
      } u_phase1_current;
      u_phase1_current.base = 0;
      u_phase1_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_phase1_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_phase1_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_phase1_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->phase1_current = u_phase1_current.real;
      offset += sizeof(this->phase1_current);
      union {
        float real;
        uint32_t base;
      } u_phase2_current;
      u_phase2_current.base = 0;
      u_phase2_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_phase2_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_phase2_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_phase2_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->phase2_current = u_phase2_current.real;
      offset += sizeof(this->phase2_current);
      union {
        float real;
        uint32_t base;
      } u_charger_temp;
      u_charger_temp.base = 0;
      u_charger_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charger_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charger_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charger_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->charger_temp = u_charger_temp.real;
      offset += sizeof(this->charger_temp);
      union {
        float real;
        uint32_t base;
      } u_battery_temp;
      u_battery_temp.base = 0;
      u_battery_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_temp = u_battery_temp.real;
      offset += sizeof(this->battery_temp);
      union {
        float real;
        uint32_t base;
      } u_supply_connector_temp;
      u_supply_connector_temp.base = 0;
      u_supply_connector_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_supply_connector_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_supply_connector_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_supply_connector_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->supply_connector_temp = u_supply_connector_temp.real;
      offset += sizeof(this->supply_connector_temp);
      union {
        float real;
        uint32_t base;
      } u_fan_speed;
      u_fan_speed.base = 0;
      u_fan_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fan_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fan_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fan_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fan_speed = u_fan_speed.real;
      offset += sizeof(this->fan_speed);
      union {
        float real;
        uint32_t base;
      } u_battery_capacity;
      u_battery_capacity.base = 0;
      u_battery_capacity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_capacity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_capacity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_capacity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_capacity = u_battery_capacity.real;
      offset += sizeof(this->battery_capacity);
      union {
        float real;
        uint32_t base;
      } u_battery_energy;
      u_battery_energy.base = 0;
      u_battery_energy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_energy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_energy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_energy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_energy = u_battery_energy.real;
      offset += sizeof(this->battery_energy);
     return offset;
    }

    const char * getType(){ return "fetch_driver_msgs/ChargerState"; };
    const char * getMD5(){ return "ec28a2b551b0a76f44243d270192fe11"; };

  };

}
#endif