#ifndef _ROS_play_motion_msgs_PlayMotionActionGoal_h
#define _ROS_play_motion_msgs_PlayMotionActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "play_motion_msgs/PlayMotionGoal.h"

namespace play_motion_msgs
{

  class PlayMotionActionGoal : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalID goal_id;
      play_motion_msgs::PlayMotionGoal goal;

    PlayMotionActionGoal():
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

    const char * getType(){ return "play_motion_msgs/PlayMotionActionGoal"; };
    const char * getMD5(){ return "ce0017b9347897304a66c70a78c9408b"; };

  };

}
#endif