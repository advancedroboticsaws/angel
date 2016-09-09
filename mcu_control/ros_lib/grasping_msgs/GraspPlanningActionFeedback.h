#ifndef _ROS_grasping_msgs_GraspPlanningActionFeedback_h
#define _ROS_grasping_msgs_GraspPlanningActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "grasping_msgs/GraspPlanningFeedback.h"

namespace grasping_msgs
{

  class GraspPlanningActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      grasping_msgs::GraspPlanningFeedback feedback;

    GraspPlanningActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "grasping_msgs/GraspPlanningActionFeedback"; };
    const char * getMD5(){ return "947765100fcb339c2c35349f12eee057"; };

  };

}
#endif