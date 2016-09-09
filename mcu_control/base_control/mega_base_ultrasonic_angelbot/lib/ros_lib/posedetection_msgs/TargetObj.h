#ifndef _ROS_SERVICE_TargetObj_h
#define _ROS_SERVICE_TargetObj_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "posedetection_msgs/Object6DPose.h"

namespace posedetection_msgs
{

static const char TARGETOBJ[] = "posedetection_msgs/TargetObj";

  class TargetObjRequest : public ros::Msg
  {
    public:
      const char* type;

    TargetObjRequest():
      type("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      memcpy(outbuffer + offset, &length_type, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      memcpy(&length_type, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
     return offset;
    }

    const char * getType(){ return TARGETOBJ; };
    const char * getMD5(){ return "dc67331de85cf97091b7d45e5c64ab75"; };

  };

  class TargetObjResponse : public ros::Msg
  {
    public:
      posedetection_msgs::Object6DPose object_pose;

    TargetObjResponse():
      object_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->object_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->object_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return TARGETOBJ; };
    const char * getMD5(){ return "9e3e0d9a56ba420ae5c3854c1194abf0"; };

  };

  class TargetObj {
    public:
    typedef TargetObjRequest Request;
    typedef TargetObjResponse Response;
  };

}
#endif
