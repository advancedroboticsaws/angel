#ifndef _ROS_ethercat_trigger_controllers_MultiWaveform_h
#define _ROS_ethercat_trigger_controllers_MultiWaveform_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ethercat_trigger_controllers/MultiWaveformTransition.h"

namespace ethercat_trigger_controllers
{

  class MultiWaveform : public ros::Msg
  {
    public:
      float period;
      float zero_offset;
      uint8_t transitions_length;
      ethercat_trigger_controllers::MultiWaveformTransition st_transitions;
      ethercat_trigger_controllers::MultiWaveformTransition * transitions;

    MultiWaveform():
      period(0),
      zero_offset(0),
      transitions_length(0), transitions(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->period);
      offset += serializeAvrFloat64(outbuffer + offset, this->zero_offset);
      *(outbuffer + offset++) = transitions_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < transitions_length; i++){
      offset += this->transitions[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->period));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->zero_offset));
      uint8_t transitions_lengthT = *(inbuffer + offset++);
      if(transitions_lengthT > transitions_length)
        this->transitions = (ethercat_trigger_controllers::MultiWaveformTransition*)realloc(this->transitions, transitions_lengthT * sizeof(ethercat_trigger_controllers::MultiWaveformTransition));
      offset += 3;
      transitions_length = transitions_lengthT;
      for( uint8_t i = 0; i < transitions_length; i++){
      offset += this->st_transitions.deserialize(inbuffer + offset);
        memcpy( &(this->transitions[i]), &(this->st_transitions), sizeof(ethercat_trigger_controllers::MultiWaveformTransition));
      }
     return offset;
    }

    const char * getType(){ return "ethercat_trigger_controllers/MultiWaveform"; };
    const char * getMD5(){ return "6a8e166563c159e73f391a302e7b37f6"; };

  };

}
#endif