#ifndef _ROS_SERVICE_SwitchTopic_h
#define _ROS_SERVICE_SwitchTopic_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_pcl_ros
{

static const char SWITCHTOPIC[] = "jsk_pcl_ros/SwitchTopic";

  class SwitchTopicRequest : public ros::Msg
  {
    public:
      const char* camera_info;
      const char* points;

    SwitchTopicRequest():
      camera_info(""),
      points("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_camera_info = strlen(this->camera_info);
      memcpy(outbuffer + offset, &length_camera_info, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->camera_info, length_camera_info);
      offset += length_camera_info;
      uint32_t length_points = strlen(this->points);
      memcpy(outbuffer + offset, &length_points, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->points, length_points);
      offset += length_points;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_camera_info;
      memcpy(&length_camera_info, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_camera_info; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_camera_info-1]=0;
      this->camera_info = (char *)(inbuffer + offset-1);
      offset += length_camera_info;
      uint32_t length_points;
      memcpy(&length_points, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_points; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_points-1]=0;
      this->points = (char *)(inbuffer + offset-1);
      offset += length_points;
     return offset;
    }

    const char * getType(){ return SWITCHTOPIC; };
    const char * getMD5(){ return "e4a276b5a9b7b8fd97441d0fd991bdb9"; };

  };

  class SwitchTopicResponse : public ros::Msg
  {
    public:

    SwitchTopicResponse()
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

    const char * getType(){ return SWITCHTOPIC; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SwitchTopic {
    public:
    typedef SwitchTopicRequest Request;
    typedef SwitchTopicResponse Response;
  };

}
#endif
