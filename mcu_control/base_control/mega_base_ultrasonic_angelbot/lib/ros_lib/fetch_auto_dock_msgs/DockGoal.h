#ifndef _ROS_fetch_auto_dock_msgs_DockGoal_h
#define _ROS_fetch_auto_dock_msgs_DockGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"

namespace fetch_auto_dock_msgs
{

  class DockGoal : public ros::Msg
  {
    public:
      geometry_msgs::PoseStamped dock_pose;
      const char* dock_id;
      bool use_move_base;

    DockGoal():
      dock_pose(),
      dock_id(""),
      use_move_base(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->dock_pose.serialize(outbuffer + offset);
      uint32_t length_dock_id = strlen(this->dock_id);
      memcpy(outbuffer + offset, &length_dock_id, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->dock_id, length_dock_id);
      offset += length_dock_id;
      union {
        bool real;
        uint8_t base;
      } u_use_move_base;
      u_use_move_base.real = this->use_move_base;
      *(outbuffer + offset + 0) = (u_use_move_base.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_move_base);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->dock_pose.deserialize(inbuffer + offset);
      uint32_t length_dock_id;
      memcpy(&length_dock_id, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_dock_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_dock_id-1]=0;
      this->dock_id = (char *)(inbuffer + offset-1);
      offset += length_dock_id;
      union {
        bool real;
        uint8_t base;
      } u_use_move_base;
      u_use_move_base.base = 0;
      u_use_move_base.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_move_base = u_use_move_base.real;
      offset += sizeof(this->use_move_base);
     return offset;
    }

    const char * getType(){ return "fetch_auto_dock_msgs/DockGoal"; };
    const char * getMD5(){ return "3802143c05afa4995a977654bae73c88"; };

  };

}
#endif