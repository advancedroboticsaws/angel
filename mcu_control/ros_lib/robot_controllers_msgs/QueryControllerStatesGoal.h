#ifndef _ROS_robot_controllers_msgs_QueryControllerStatesGoal_h
#define _ROS_robot_controllers_msgs_QueryControllerStatesGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robot_controllers_msgs/ControllerState.h"

namespace robot_controllers_msgs
{

  class QueryControllerStatesGoal : public ros::Msg
  {
    public:
      uint8_t updates_length;
      robot_controllers_msgs::ControllerState st_updates;
      robot_controllers_msgs::ControllerState * updates;

    QueryControllerStatesGoal():
      updates_length(0), updates(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = updates_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < updates_length; i++){
      offset += this->updates[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t updates_lengthT = *(inbuffer + offset++);
      if(updates_lengthT > updates_length)
        this->updates = (robot_controllers_msgs::ControllerState*)realloc(this->updates, updates_lengthT * sizeof(robot_controllers_msgs::ControllerState));
      offset += 3;
      updates_length = updates_lengthT;
      for( uint8_t i = 0; i < updates_length; i++){
      offset += this->st_updates.deserialize(inbuffer + offset);
        memcpy( &(this->updates[i]), &(this->st_updates), sizeof(robot_controllers_msgs::ControllerState));
      }
     return offset;
    }

    const char * getType(){ return "robot_controllers_msgs/QueryControllerStatesGoal"; };
    const char * getMD5(){ return "6ecbb837d1e8545d81a831a4c1c4bfcc"; };

  };

}
#endif