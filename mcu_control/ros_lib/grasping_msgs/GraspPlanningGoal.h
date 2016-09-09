#ifndef _ROS_grasping_msgs_GraspPlanningGoal_h
#define _ROS_grasping_msgs_GraspPlanningGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "grasping_msgs/Object.h"

namespace grasping_msgs
{

  class GraspPlanningGoal : public ros::Msg
  {
    public:
      grasping_msgs::Object object;
      const char* group_name;

    GraspPlanningGoal():
      object(),
      group_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->object.serialize(outbuffer + offset);
      uint32_t length_group_name = strlen(this->group_name);
      memcpy(outbuffer + offset, &length_group_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->object.deserialize(inbuffer + offset);
      uint32_t length_group_name;
      memcpy(&length_group_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
     return offset;
    }

    const char * getType(){ return "grasping_msgs/GraspPlanningGoal"; };
    const char * getMD5(){ return "1c3f3ed2a31c4c865c3032a4789c0df9"; };

  };

}
#endif