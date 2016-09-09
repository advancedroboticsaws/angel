#ifndef _ROS_robot_controllers_msgs_QueryControllerStatesResult_h
#define _ROS_robot_controllers_msgs_QueryControllerStatesResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robot_controllers_msgs/ControllerState.h"

namespace robot_controllers_msgs
{

  class QueryControllerStatesResult : public ros::Msg
  {
    public:
      uint8_t state_length;
      robot_controllers_msgs::ControllerState st_state;
      robot_controllers_msgs::ControllerState * state;

    QueryControllerStatesResult():
      state_length(0), state(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = state_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < state_length; i++){
      offset += this->state[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t state_lengthT = *(inbuffer + offset++);
      if(state_lengthT > state_length)
        this->state = (robot_controllers_msgs::ControllerState*)realloc(this->state, state_lengthT * sizeof(robot_controllers_msgs::ControllerState));
      offset += 3;
      state_length = state_lengthT;
      for( uint8_t i = 0; i < state_length; i++){
      offset += this->st_state.deserialize(inbuffer + offset);
        memcpy( &(this->state[i]), &(this->st_state), sizeof(robot_controllers_msgs::ControllerState));
      }
     return offset;
    }

    const char * getType(){ return "robot_controllers_msgs/QueryControllerStatesResult"; };
    const char * getMD5(){ return "95b3426d59527deffe501158443b26c9"; };

  };

}
#endif