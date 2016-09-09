#ifndef _ROS_SERVICE_CallPolygon_h
#define _ROS_SERVICE_CallPolygon_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PolygonStamped.h"

namespace jsk_pcl_ros
{

static const char CALLPOLYGON[] = "jsk_pcl_ros/CallPolygon";

  class CallPolygonRequest : public ros::Msg
  {
    public:
      const char* filename;

    CallPolygonRequest():
      filename("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_filename = strlen(this->filename);
      memcpy(outbuffer + offset, &length_filename, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->filename, length_filename);
      offset += length_filename;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_filename;
      memcpy(&length_filename, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filename-1]=0;
      this->filename = (char *)(inbuffer + offset-1);
      offset += length_filename;
     return offset;
    }

    const char * getType(){ return CALLPOLYGON; };
    const char * getMD5(){ return "030824f52a0628ead956fb9d67e66ae9"; };

  };

  class CallPolygonResponse : public ros::Msg
  {
    public:
      geometry_msgs::PolygonStamped points;

    CallPolygonResponse():
      points()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->points.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->points.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CALLPOLYGON; };
    const char * getMD5(){ return "5f7fab179463c3091ade3556924563da"; };

  };

  class CallPolygon {
    public:
    typedef CallPolygonRequest Request;
    typedef CallPolygonResponse Response;
  };

}
#endif
