#ifndef _ROS_grasping_msgs_FindGraspableObjectsGoal_h
#define _ROS_grasping_msgs_FindGraspableObjectsGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace grasping_msgs
{

  class FindGraspableObjectsGoal : public ros::Msg
  {
    public:
      bool plan_grasps;

    FindGraspableObjectsGoal():
      plan_grasps(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_plan_grasps;
      u_plan_grasps.real = this->plan_grasps;
      *(outbuffer + offset + 0) = (u_plan_grasps.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->plan_grasps);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_plan_grasps;
      u_plan_grasps.base = 0;
      u_plan_grasps.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->plan_grasps = u_plan_grasps.real;
      offset += sizeof(this->plan_grasps);
     return offset;
    }

    const char * getType(){ return "grasping_msgs/FindGraspableObjectsGoal"; };
    const char * getMD5(){ return "4aadd364d1b04bf1e9e9fdbdce5637d4"; };

  };

}
#endif