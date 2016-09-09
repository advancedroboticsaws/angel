#ifndef _ROS_SERVICE_ListMotions_h
#define _ROS_SERVICE_ListMotions_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "play_motion_msgs/MotionInfo.h"

namespace play_motion_msgs
{

static const char LISTMOTIONS[] = "play_motion_msgs/ListMotions";

  class ListMotionsRequest : public ros::Msg
  {
    public:

    ListMotionsRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return LISTMOTIONS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListMotionsResponse : public ros::Msg
  {
    public:
      uint8_t motions_length;
      play_motion_msgs::MotionInfo st_motions;
      play_motion_msgs::MotionInfo * motions;

    ListMotionsResponse():
      motions_length(0), motions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = motions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < motions_length; i++){
      offset += this->motions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t motions_lengthT = *(inbuffer + offset++);
      if(motions_lengthT > motions_length)
        this->motions = (play_motion_msgs::MotionInfo*)realloc(this->motions, motions_lengthT * sizeof(play_motion_msgs::MotionInfo));
      offset += 3;
      motions_length = motions_lengthT;
      for( uint8_t i = 0; i < motions_length; i++){
      offset += this->st_motions.deserialize(inbuffer + offset);
        memcpy( &(this->motions[i]), &(this->st_motions), sizeof(play_motion_msgs::MotionInfo));
      }
     return offset;
    }

    const char * getType(){ return LISTMOTIONS; };
    const char * getMD5(){ return "151d88e888f918ab21ebda2cef4dd23c"; };

  };

  class ListMotions {
    public:
    typedef ListMotionsRequest Request;
    typedef ListMotionsResponse Response;
  };

}
#endif
