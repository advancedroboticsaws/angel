#ifndef _ROS_fetch_auto_dock_msgs_UndockActionResult_h
#define _ROS_fetch_auto_dock_msgs_UndockActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "fetch_auto_dock_msgs/UndockResult.h"

namespace fetch_auto_dock_msgs
{

  class UndockActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      fetch_auto_dock_msgs::UndockResult result;

    UndockActionResult():
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

    const char * getType(){ return "fetch_auto_dock_msgs/UndockActionResult"; };
    const char * getMD5(){ return "6868978f7aa1c3f7fba76547d2092ae9"; };

  };

}
#endif