#ifndef _ROS_fetch_auto_dock_msgs_DockResult_h
#define _ROS_fetch_auto_dock_msgs_DockResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fetch_auto_dock_msgs
{

  class DockResult : public ros::Msg
  {
    public:
      bool docked;
      const char* dock_id;

    DockResult():
      docked(0),
      dock_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_docked;
      u_docked.real = this->docked;
      *(outbuffer + offset + 0) = (u_docked.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->docked);
      uint32_t length_dock_id = strlen(this->dock_id);
      memcpy(outbuffer + offset, &length_dock_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->dock_id, length_dock_id);
      offset += length_dock_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_docked;
      u_docked.base = 0;
      u_docked.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->docked = u_docked.real;
      offset += sizeof(this->docked);
      uint32_t length_dock_id;
      memcpy(&length_dock_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_dock_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_dock_id-1]=0;
      this->dock_id = (char *)(inbuffer + offset-1);
      offset += length_dock_id;
     return offset;
    }

    const char * getType(){ return "fetch_auto_dock_msgs/DockResult"; };
    const char * getMD5(){ return "3c9af1b0b876b5336e9869a2cfc41c1c"; };

  };

}
#endif