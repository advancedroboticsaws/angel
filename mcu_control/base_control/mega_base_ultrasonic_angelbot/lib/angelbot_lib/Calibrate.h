#ifndef _ROS_SERVICE_Calibrate_h
#define _ROS_SERVICE_Calibrate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace angelbot
{

static const char CALIBRATE[] = "angelbot/Calibrate";

  class CalibrateRequest : public ros::Msg
  {
    public:
      uint8_t id;
      uint8_t kp;
      uint8_t ki;
      uint8_t kd;
      uint8_t currentlim;

    CalibrateRequest():
      id(0),
      kp(0),
      ki(0),
      kd(0),
      currentlim(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->kp >> (8 * 0)) & 0xFF;
      offset += sizeof(this->kp);
      *(outbuffer + offset + 0) = (this->ki >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ki);
      *(outbuffer + offset + 0) = (this->kd >> (8 * 0)) & 0xFF;
      offset += sizeof(this->kd);
      *(outbuffer + offset + 0) = (this->currentlim >> (8 * 0)) & 0xFF;
      offset += sizeof(this->currentlim);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      this->kp =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->kp);
      this->ki =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ki);
      this->kd =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->kd);
      this->currentlim =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->currentlim);
     return offset;
    }

    const char * getType(){ return CALIBRATE; };
    const char * getMD5(){ return "e00d58bea6536ff6e61f3944a797a9d7"; };

  };

  class CalibrateResponse : public ros::Msg
  {
    public:
      uint8_t id;
      uint8_t kp;
      uint8_t ki;
      uint8_t kd;
      uint8_t currentlim;

    CalibrateResponse():
      id(0),
      kp(0),
      ki(0),
      kd(0),
      currentlim(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->kp >> (8 * 0)) & 0xFF;
      offset += sizeof(this->kp);
      *(outbuffer + offset + 0) = (this->ki >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ki);
      *(outbuffer + offset + 0) = (this->kd >> (8 * 0)) & 0xFF;
      offset += sizeof(this->kd);
      *(outbuffer + offset + 0) = (this->currentlim >> (8 * 0)) & 0xFF;
      offset += sizeof(this->currentlim);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      this->kp =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->kp);
      this->ki =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ki);
      this->kd =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->kd);
      this->currentlim =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->currentlim);
     return offset;
    }

    const char * getType(){ return CALIBRATE; };
    const char * getMD5(){ return "e00d58bea6536ff6e61f3944a797a9d7"; };

  };

  class Calibrate {
    public:
    typedef CalibrateRequest Request;
    typedef CalibrateResponse Response;
  };

}
#endif
