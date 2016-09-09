#ifndef _ROS_grasping_msgs_GraspPlanningActionGoal_h
#define _ROS_grasping_msgs_GraspPlanningActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "grasping_msgs/GraspPlanningGoal.h"

namespace grasping_msgs
{

  class GraspPlanningActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      grasping_msgs::GraspPlanningGoal goal;

    GraspPlanningActionGoal():
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

    const char * getType(){ return "grasping_msgs/GraspPlanningActionGoal"; };
    const char * getMD5(){ return "caad3d76fe6a67352a76302e837cccbe"; };

  };

}
#endif