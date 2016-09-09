#ifndef _ROS_posedetection_msgs_ObjectDetection_h
#define _ROS_posedetection_msgs_ObjectDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "posedetection_msgs/Object6DPose.h"

namespace posedetection_msgs
{

  class ObjectDetection : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint8_t objects_length;
      posedetection_msgs::Object6DPose st_objects;
      posedetection_msgs::Object6DPose * objects;

    ObjectDetection():
      header(),
      objects_length(0), objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset++) = objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint8_t objects_lengthT = *(inbuffer + offset++);
      if(objects_lengthT > objects_length)
        this->objects = (posedetection_msgs::Object6DPose*)realloc(this->objects, objects_lengthT * sizeof(posedetection_msgs::Object6DPose));
      offset += 3;
      objects_length = objects_lengthT;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(posedetection_msgs::Object6DPose));
      }
     return offset;
    }

    const char * getType(){ return "posedetection_msgs/ObjectDetection"; };
    const char * getMD5(){ return "450ee77eda8a92543774df0b858b3605"; };

  };

}
#endif