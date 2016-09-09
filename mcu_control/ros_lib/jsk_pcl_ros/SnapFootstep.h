#ifndef _ROS_SERVICE_SnapFootstep_h
#define _ROS_SERVICE_SnapFootstep_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_footstep_msgs/FootstepArray.h"

namespace jsk_pcl_ros
{

static const char SNAPFOOTSTEP[] = "jsk_pcl_ros/SnapFootstep";

  class SnapFootstepRequest : public ros::Msg
  {
    public:
      jsk_footstep_msgs::FootstepArray input;

    SnapFootstepRequest():
      input()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->input.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->input.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SNAPFOOTSTEP; };
    const char * getMD5(){ return "b2fab553060b184c09aa1c8697183b82"; };

  };

  class SnapFootstepResponse : public ros::Msg
  {
    public:
      jsk_footstep_msgs::FootstepArray output;

    SnapFootstepResponse():
      output()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->output.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->output.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SNAPFOOTSTEP; };
    const char * getMD5(){ return "5f90736567f86e33a9f02223a346bee2"; };

  };

  class SnapFootstep {
    public:
    typedef SnapFootstepRequest Request;
    typedef SnapFootstepResponse Response;
  };

}
#endif
