#ifndef _ROS_fetch_auto_dock_msgs_UndockActionFeedback_h
#define _ROS_fetch_auto_dock_msgs_UndockActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "fetch_auto_dock_msgs/UndockFeedback.h"

namespace fetch_auto_dock_msgs
{

  class UndockActionFeedback : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      fetch_auto_dock_msgs::UndockFeedback feedback;

    UndockActionFeedback():
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

    const char * getType(){ return "fetch_auto_dock_msgs/UndockActionFeedback"; };
    const char * getMD5(){ return "6a07b7150fca355bea027d8c95ed9e67"; };

  };

}
#endif