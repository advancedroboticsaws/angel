#ifndef _ROS_grasping_msgs_GraspableObject_h
#define _ROS_grasping_msgs_GraspableObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "grasping_msgs/Object.h"
#include "moveit_msgs/Grasp.h"

namespace grasping_msgs
{

  class GraspableObject : public ros::Msg
  {
    public:
      grasping_msgs::Object object;
      uint8_t grasps_length;
      moveit_msgs::Grasp st_grasps;
      moveit_msgs::Grasp * grasps;

    GraspableObject():
      object(),
      grasps_length(0), grasps(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->object.serialize(outbuffer + offset);
      *(outbuffer + offset++) = grasps_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < grasps_length; i++){
      offset += this->grasps[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->object.deserialize(inbuffer + offset);
      uint8_t grasps_lengthT = *(inbuffer + offset++);
      if(grasps_lengthT > grasps_length)
        this->grasps = (moveit_msgs::Grasp*)realloc(this->grasps, grasps_lengthT * sizeof(moveit_msgs::Grasp));
      offset += 3;
      grasps_length = grasps_lengthT;
      for( uint8_t i = 0; i < grasps_length; i++){
      offset += this->st_grasps.deserialize(inbuffer + offset);
        memcpy( &(this->grasps[i]), &(this->st_grasps), sizeof(moveit_msgs::Grasp));
      }
     return offset;
    }

    const char * getType(){ return "grasping_msgs/GraspableObject"; };
    const char * getMD5(){ return "ec31ebe9db31c8d3ccab1b66aedd1293"; };

  };

}
#endif