#ifndef _ROS_pr2_mechanism_controllers_OdometryMatrix_h
#define _ROS_pr2_mechanism_controllers_OdometryMatrix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace pr2_mechanism_controllers
{

  class OdometryMatrix : public ros::Msg
  {
    public:
      uint8_t m_length;
      float st_m;
      float * m;

    OdometryMatrix():
      m_length(0), m(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = m_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < m_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->m[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t m_lengthT = *(inbuffer + offset++);
      if(m_lengthT > m_length)
        this->m = (float*)realloc(this->m, m_lengthT * sizeof(float));
      offset += 3;
      m_length = m_lengthT;
      for( uint8_t i = 0; i < m_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_m));
        memcpy( &(this->m[i]), &(this->st_m), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "pr2_mechanism_controllers/OdometryMatrix"; };
    const char * getMD5(){ return "1f7818e7ce16454badf1bee936b0ff16"; };

  };

}
#endif