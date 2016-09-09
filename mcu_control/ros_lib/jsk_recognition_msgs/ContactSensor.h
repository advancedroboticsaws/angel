#ifndef _ROS_jsk_recognition_msgs_ContactSensor_h
#define _ROS_jsk_recognition_msgs_ContactSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace jsk_recognition_msgs
{

  class ContactSensor : public ros::Msg
  {
    public:
      std_msgs::Header header;
      bool contact;
      const char* link_name;

    ContactSensor():
      header(),
      contact(0),
      link_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_contact;
      u_contact.real = this->contact;
      *(outbuffer + offset + 0) = (u_contact.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contact);
      uint32_t length_link_name = strlen(this->link_name);
      memcpy(outbuffer + offset, &length_link_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_contact;
      u_contact.base = 0;
      u_contact.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contact = u_contact.real;
      offset += sizeof(this->contact);
      uint32_t length_link_name;
      memcpy(&length_link_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
     return offset;
    }

    const char * getType(){ return "jsk_recognition_msgs/ContactSensor"; };
    const char * getMD5(){ return "364b2b952a51d85dfa877e334264e361"; };

  };

}
#endif