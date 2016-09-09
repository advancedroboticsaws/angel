#ifndef _ROS_fetch_auto_dock_msgs_DockActionResult_h
#define _ROS_fetch_auto_dock_msgs_DockActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "fetch_auto_dock_msgs/DockResult.h"

namespace fetch_auto_dock_msgs
{

  class DockActionResult : public ros::Msg
  {
    public:
      std_msgs::Header header;
      actionlib_msgs::GoalStatus status;
      fetch_auto_dock_msgs::DockResult result;

    DockActionResult():
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

    const char * getType(){ return "fetch_auto_dock_msgs/DockActionResult"; };
    const char * getMD5(){ return "62d3add0cb6cbe61284964df4bb1e09b"; };

  };

}
#endif