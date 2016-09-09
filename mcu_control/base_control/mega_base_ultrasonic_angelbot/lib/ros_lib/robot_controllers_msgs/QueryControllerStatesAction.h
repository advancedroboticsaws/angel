#ifndef _ROS_robot_controllers_msgs_QueryControllerStatesAction_h
#define _ROS_robot_controllers_msgs_QueryControllerStatesAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robot_controllers_msgs/QueryControllerStatesActionGoal.h"
#include "robot_controllers_msgs/QueryControllerStatesActionResult.h"
#include "robot_controllers_msgs/QueryControllerStatesActionFeedback.h"

namespace robot_controllers_msgs
{

  class QueryControllerStatesAction : public ros::Msg
  {
    public:
      robot_controllers_msgs::QueryControllerStatesActionGoal action_goal;
      robot_controllers_msgs::QueryControllerStatesActionResult action_result;
      robot_controllers_msgs::QueryControllerStatesActionFeedback action_feedback;

    QueryControllerStatesAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "robot_controllers_msgs/QueryControllerStatesAction"; };
    const char * getMD5(){ return "09c0acaa5ed1f30d01515baab9a95895"; };

  };

}
#endif