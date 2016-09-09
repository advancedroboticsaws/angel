#ifndef _ROS_SERVICE_PolygonOnEnvironment_h
#define _ROS_SERVICE_PolygonOnEnvironment_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PolygonStamped.h"

namespace jsk_pcl_ros
{

static const char POLYGONONENVIRONMENT[] = "jsk_pcl_ros/PolygonOnEnvironment";

  class PolygonOnEnvironmentRequest : public ros::Msg
  {
    public:
      uint32_t environment_id;
      uint32_t plane_index;
      geometry_msgs::PolygonStamped polygon;

    PolygonOnEnvironmentRequest():
      environment_id(0),
      plane_index(0),
      polygon()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->environment_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->environment_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->environment_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->environment_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->environment_id);
      *(outbuffer + offset + 0) = (this->plane_index >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->plane_index >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->plane_index >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->plane_index >> (8 * 3)) & 0xFF;
      offset += sizeof(this->plane_index);
      offset += this->polygon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->environment_id =  ((uint32_t) (*(inbuffer + offset)));
      this->environment_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->environment_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->environment_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->environment_id);
      this->plane_index =  ((uint32_t) (*(inbuffer + offset)));
      this->plane_index |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->plane_index |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->plane_index |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->plane_index);
      offset += this->polygon.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return POLYGONONENVIRONMENT; };
    const char * getMD5(){ return "5c876f97015e6a599aa3c09455882c02"; };

  };

  class PolygonOnEnvironmentResponse : public ros::Msg
  {
    public:
      bool result;
      const char* reason;

    PolygonOnEnvironmentResponse():
      result(0),
      reason("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      uint32_t length_reason = strlen(this->reason);
      memcpy(outbuffer + offset, &length_reason, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->reason, length_reason);
      offset += length_reason;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
      uint32_t length_reason;
      memcpy(&length_reason, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_reason; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_reason-1]=0;
      this->reason = (char *)(inbuffer + offset-1);
      offset += length_reason;
     return offset;
    }

    const char * getType(){ return POLYGONONENVIRONMENT; };
    const char * getMD5(){ return "5d3fee08bf23ddff8ab543476a855d3f"; };

  };

  class PolygonOnEnvironment {
    public:
    typedef PolygonOnEnvironmentRequest Request;
    typedef PolygonOnEnvironmentResponse Response;
  };

}
#endif
