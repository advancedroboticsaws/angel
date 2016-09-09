#ifndef _ROS_robot_controllers_msgs_QueryControllerStatesFeedback_h
#define _ROS_robot_controllers_msgs_QueryControllerStatesFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robot_controllers_msgs/ControllerState.h"

namespace robot_controllers_msgs
{

  class QueryControllerStatesFeedback : public ros::Msg
  {
    public:
      uint8_t state_diff_length;
      robot_controllers_msgs::ControllerState st_state_diff;
      robot_controllers_msgs::ControllerState * state_diff;

    QueryControllerStatesFeedback():
      state_diff_length(0), state_diff(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = state_diff_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < state_diff_length; i++){
      offset += this->state_diff[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t state_diff_lengthT = *(inbuffer + offset++);
      if(state_diff_lengthT > state_diff_length)
        this->state_diff = (robot_controllers_msgs::ControllerState*)realloc(this->state_diff, state_diff_lengthT * sizeof(robot_controllers_msgs::ControllerState));
      offset += 3;
      state_diff_length = state_diff_lengthT;
      for( uint8_t i = 0; i < state_diff_length; i++){
      offset += this->st_state_diff.deserialize(inbuffer + offset);
        memcpy( &(this->state_diff[i]), &(this->st_state_diff), sizeof(robot_controllers_msgs::ControllerState));
      }
     return offset;
    }

    const char * getType(){ return "robot_controllers_msgs/QueryControllerStatesFeedback"; };
    const char * getMD5(){ return "884ebbcebb33b2855209539dadfa0dc6"; };

  };

}
#endif