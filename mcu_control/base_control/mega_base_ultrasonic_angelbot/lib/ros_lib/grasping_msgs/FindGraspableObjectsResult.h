#ifndef _ROS_grasping_msgs_FindGraspableObjectsResult_h
#define _ROS_grasping_msgs_FindGraspableObjectsResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "grasping_msgs/GraspableObject.h"
#include "grasping_msgs/Object.h"

namespace grasping_msgs
{

  class FindGraspableObjectsResult : public ros::Msg
  {
    public:
      uint8_t objects_length;
      grasping_msgs::GraspableObject st_objects;
      grasping_msgs::GraspableObject * objects;
      uint8_t support_surfaces_length;
      grasping_msgs::Object st_support_surfaces;
      grasping_msgs::Object * support_surfaces;

    FindGraspableObjectsResult():
      objects_length(0), objects(NULL),
      support_surfaces_length(0), support_surfaces(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset++) = objects_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->objects[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = support_surfaces_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < support_surfaces_length; i++){
      offset += this->support_surfaces[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint8_t objects_lengthT = *(inbuffer + offset++);
      if(objects_lengthT > objects_length)
        this->objects = (grasping_msgs::GraspableObject*)realloc(this->objects, objects_lengthT * sizeof(grasping_msgs::GraspableObject));
      offset += 3;
      objects_length = objects_lengthT;
      for( uint8_t i = 0; i < objects_length; i++){
      offset += this->st_objects.deserialize(inbuffer + offset);
        memcpy( &(this->objects[i]), &(this->st_objects), sizeof(grasping_msgs::GraspableObject));
      }
      uint8_t support_surfaces_lengthT = *(inbuffer + offset++);
      if(support_surfaces_lengthT > support_surfaces_length)
        this->support_surfaces = (grasping_msgs::Object*)realloc(this->support_surfaces, support_surfaces_lengthT * sizeof(grasping_msgs::Object));
      offset += 3;
      support_surfaces_length = support_surfaces_lengthT;
      for( uint8_t i = 0; i < support_surfaces_length; i++){
      offset += this->st_support_surfaces.deserialize(inbuffer + offset);
        memcpy( &(this->support_surfaces[i]), &(this->st_support_surfaces), sizeof(grasping_msgs::Object));
      }
     return offset;
    }

    const char * getType(){ return "grasping_msgs/FindGraspableObjectsResult"; };
    const char * getMD5(){ return "b0e2a5b10c524db813b26378dd6d8559"; };

  };

}
#endif