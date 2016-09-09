#ifndef _ROS_power_msgs_BatteryState_h
#define _ROS_power_msgs_BatteryState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace power_msgs
{

  class BatteryState : public ros::Msg
  {
    public:
      const char* name;
      float charge_level;
      bool is_charging;
      ros::Duration remaining_time;

    BatteryState():
      name(""),
      charge_level(0),
      is_charging(0),
      remaining_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        float real;
        uint32_t base;
      } u_charge_level;
      u_charge_level.real = this->charge_level;
      *(outbuffer + offset + 0) = (u_charge_level.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charge_level.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charge_level.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charge_level.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charge_level);
      union {
        bool real;
        uint8_t base;
      } u_is_charging;
      u_is_charging.real = this->is_charging;
      *(outbuffer + offset + 0) = (u_is_charging.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_charging);
      *(outbuffer + offset + 0) = (this->remaining_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->remaining_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->remaining_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->remaining_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remaining_time.sec);
      *(outbuffer + offset + 0) = (this->remaining_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->remaining_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->remaining_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->remaining_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remaining_time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        float real;
        uint32_t base;
      } u_charge_level;
      u_charge_level.base = 0;
      u_charge_level.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charge_level.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charge_level.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charge_level.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->charge_level = u_charge_level.real;
      offset += sizeof(this->charge_level);
      union {
        bool real;
        uint8_t base;
      } u_is_charging;
      u_is_charging.base = 0;
      u_is_charging.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_charging = u_is_charging.real;
      offset += sizeof(this->is_charging);
      this->remaining_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->remaining_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->remaining_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->remaining_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->remaining_time.sec);
      this->remaining_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->remaining_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->remaining_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->remaining_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->remaining_time.nsec);
     return offset;
    }

    const char * getType(){ return "power_msgs/BatteryState"; };
    const char * getMD5(){ return "4b7120fcba08944ca050890d5cbdd68c"; };

  };

}
#endif