#ifndef _ROS_ethercat_hardware_BoardInfo_h
#define _ROS_ethercat_hardware_BoardInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ethercat_hardware
{

  class BoardInfo : public ros::Msg
  {
    public:
      const char* description;
      uint32_t product_code;
      uint32_t pcb;
      uint32_t pca;
      uint32_t serial;
      uint32_t firmware_major;
      uint32_t firmware_minor;
      float board_resistance;
      float max_pwm_ratio;
      float hw_max_current;
      bool poor_measured_motor_voltage;

    BoardInfo():
      description(""),
      product_code(0),
      pcb(0),
      pca(0),
      serial(0),
      firmware_major(0),
      firmware_minor(0),
      board_resistance(0),
      max_pwm_ratio(0),
      hw_max_current(0),
      poor_measured_motor_voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_description = strlen(this->description);
      memcpy(outbuffer + offset, &length_description, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      *(outbuffer + offset + 0) = (this->product_code >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->product_code >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->product_code >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->product_code >> (8 * 3)) & 0xFF;
      offset += sizeof(this->product_code);
      *(outbuffer + offset + 0) = (this->pcb >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pcb >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pcb >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pcb >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pcb);
      *(outbuffer + offset + 0) = (this->pca >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pca >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pca >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pca >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pca);
      *(outbuffer + offset + 0) = (this->serial >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->serial >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->serial >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->serial >> (8 * 3)) & 0xFF;
      offset += sizeof(this->serial);
      *(outbuffer + offset + 0) = (this->firmware_major >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->firmware_major >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->firmware_major >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->firmware_major >> (8 * 3)) & 0xFF;
      offset += sizeof(this->firmware_major);
      *(outbuffer + offset + 0) = (this->firmware_minor >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->firmware_minor >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->firmware_minor >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->firmware_minor >> (8 * 3)) & 0xFF;
      offset += sizeof(this->firmware_minor);
      offset += serializeAvrFloat64(outbuffer + offset, this->board_resistance);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_pwm_ratio);
      offset += serializeAvrFloat64(outbuffer + offset, this->hw_max_current);
      union {
        bool real;
        uint8_t base;
      } u_poor_measured_motor_voltage;
      u_poor_measured_motor_voltage.real = this->poor_measured_motor_voltage;
      *(outbuffer + offset + 0) = (u_poor_measured_motor_voltage.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->poor_measured_motor_voltage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_description;
      memcpy(&length_description, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      this->product_code =  ((uint32_t) (*(inbuffer + offset)));
      this->product_code |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->product_code |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->product_code |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->product_code);
      this->pcb =  ((uint32_t) (*(inbuffer + offset)));
      this->pcb |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pcb |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->pcb |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->pcb);
      this->pca =  ((uint32_t) (*(inbuffer + offset)));
      this->pca |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pca |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->pca |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->pca);
      this->serial =  ((uint32_t) (*(inbuffer + offset)));
      this->serial |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->serial |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->serial |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->serial);
      this->firmware_major =  ((uint32_t) (*(inbuffer + offset)));
      this->firmware_major |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->firmware_major |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->firmware_major |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->firmware_major);
      this->firmware_minor =  ((uint32_t) (*(inbuffer + offset)));
      this->firmware_minor |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->firmware_minor |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->firmware_minor |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->firmware_minor);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->board_resistance));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_pwm_ratio));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->hw_max_current));
      union {
        bool real;
        uint8_t base;
      } u_poor_measured_motor_voltage;
      u_poor_measured_motor_voltage.base = 0;
      u_poor_measured_motor_voltage.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->poor_measured_motor_voltage = u_poor_measured_motor_voltage.real;
      offset += sizeof(this->poor_measured_motor_voltage);
     return offset;
    }

    const char * getType(){ return "ethercat_hardware/BoardInfo"; };
    const char * getMD5(){ return "ffcb87ef2725c5fab7d0d8fcd4c7e7bc"; };

  };

}
#endif