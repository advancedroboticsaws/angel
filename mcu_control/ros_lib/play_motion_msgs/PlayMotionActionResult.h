#ifndef _ROS_play_motion_msgs_PlayMotionActionResult_h
#define _ROS_play_motion_msgs_PlayMotionActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "play_motion_msgs/PlayMotionResult.h"

namespace play_motion_msgs
{

  class PlayMotionActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      play_motion_msgs::PlayMotionResult result;

    PlayMotionActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "play_motion_msgs/PlayMotionActionResult"; };
    const char * getMD5(){ return "99680b95d3bd3f96e403ed053918b8d1"; };

  };

}
#endif