#ifndef _ROS_robot_controllers_msgs_QueryControllerStatesActionGoal_h
#define _ROS_robot_controllers_msgs_QueryControllerStatesActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "robot_controllers_msgs/QueryControllerStatesGoal.h"

namespace robot_controllers_msgs
{

  class QueryControllerStatesActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      robot_controllers_msgs::QueryControllerStatesGoal goal;

    QueryControllerStatesActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "robot_controllers_msgs/QueryControllerStatesActionGoal"; };
    const char * getMD5(){ return "291a917d724f37ef2a137fb40fae4e4a"; };

  };

}
#endif