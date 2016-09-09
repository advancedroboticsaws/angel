#ifndef _ROS_grasping_msgs_Object_h
#define _ROS_grasping_msgs_Object_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "grasping_msgs/ObjectProperty.h"
#include "sensor_msgs/PointCloud2.h"
#include "shape_msgs/SolidPrimitive.h"
#include "geometry_msgs/Pose.h"
#include "shape_msgs/Mesh.h"
#include "shape_msgs/Plane.h"

namespace grasping_msgs
{

  class Object : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* name;
      const char* support_surface;
      uint8_t properties_length;
      grasping_msgs::ObjectProperty st_properties;
      grasping_msgs::ObjectProperty * properties;
      sensor_msgs::PointCloud2 point_cluster;
      uint8_t primitives_length;
      shape_msgs::SolidPrimitive st_primitives;
      shape_msgs::SolidPrimitive * primitives;
      uint8_t primitive_poses_length;
      geometry_msgs::Pose st_primitive_poses;
      geometry_msgs::Pose * primitive_poses;
      uint8_t meshes_length;
      shape_msgs::Mesh st_meshes;
      shape_msgs::Mesh * meshes;
      uint8_t mesh_poses_length;
      geometry_msgs::Pose st_mesh_poses;
      geometry_msgs::Pose * mesh_poses;
      shape_msgs::Plane surface;

    Object():
      header(),
      name(""),
      support_surface(""),
      properties_length(0), properties(NULL),
      point_cluster(),
      primitives_length(0), primitives(NULL),
      primitive_poses_length(0), primitive_poses(NULL),
      meshes_length(0), meshes(NULL),
      mesh_poses_length(0), mesh_poses(NULL),
      surface()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_name = strlen(this->name);
      memcpy(outbuffer + offset, &length_name, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_support_surface = strlen(this->support_surface);
      memcpy(outbuffer + offset, &length_support_surface, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->support_surface, length_support_surface);
      offset += length_support_surface;
      *(outbuffer + offset++) = properties_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < properties_length; i++){
      offset += this->properties[i].serialize(outbuffer + offset);
      }
      offset += this->point_cluster.serialize(outbuffer + offset);
      *(outbuffer + offset++) = primitives_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < primitives_length; i++){
      offset += this->primitives[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = primitive_poses_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < primitive_poses_length; i++){
      offset += this->primitive_poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = meshes_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < meshes_length; i++){
      offset += this->meshes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = mesh_poses_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < mesh_poses_length; i++){
      offset += this->mesh_poses[i].serialize(outbuffer + offset);
      }
      offset += this->surface.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_name;
      memcpy(&length_name, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_support_surface;
      memcpy(&length_support_surface, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_support_surface; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_support_surface-1]=0;
      this->support_surface = (char *)(inbuffer + offset-1);
      offset += length_support_surface;
      uint8_t properties_lengthT = *(inbuffer + offset++);
      if(properties_lengthT > properties_length)
        this->properties = (grasping_msgs::ObjectProperty*)realloc(this->properties, properties_lengthT * sizeof(grasping_msgs::ObjectProperty));
      offset += 3;
      properties_length = properties_lengthT;
      for( uint8_t i = 0; i < properties_length; i++){
      offset += this->st_properties.deserialize(inbuffer + offset);
        memcpy( &(this->properties[i]), &(this->st_properties), sizeof(grasping_msgs::ObjectProperty));
      }
      offset += this->point_cluster.deserialize(inbuffer + offset);
      uint8_t primitives_lengthT = *(inbuffer + offset++);
      if(primitives_lengthT > primitives_length)
        this->primitives = (shape_msgs::SolidPrimitive*)realloc(this->primitives, primitives_lengthT * sizeof(shape_msgs::SolidPrimitive));
      offset += 3;
      primitives_length = primitives_lengthT;
      for( uint8_t i = 0; i < primitives_length; i++){
      offset += this->st_primitives.deserialize(inbuffer + offset);
        memcpy( &(this->primitives[i]), &(this->st_primitives), sizeof(shape_msgs::SolidPrimitive));
      }
      uint8_t primitive_poses_lengthT = *(inbuffer + offset++);
      if(primitive_poses_lengthT > primitive_poses_length)
        this->primitive_poses = (geometry_msgs::Pose*)realloc(this->primitive_poses, primitive_poses_lengthT * sizeof(geometry_msgs::Pose));
      offset += 3;
      primitive_poses_length = primitive_poses_lengthT;
      for( uint8_t i = 0; i < primitive_poses_length; i++){
      offset += this->st_primitive_poses.deserialize(inbuffer + offset);
        memcpy( &(this->primitive_poses[i]), &(this->st_primitive_poses), sizeof(geometry_msgs::Pose));
      }
      uint8_t meshes_lengthT = *(inbuffer + offset++);
      if(meshes_lengthT > meshes_length)
        this->meshes = (shape_msgs::Mesh*)realloc(this->meshes, meshes_lengthT * sizeof(shape_msgs::Mesh));
      offset += 3;
      meshes_length = meshes_lengthT;
      for( uint8_t i = 0; i < meshes_length; i++){
      offset += this->st_meshes.deserialize(inbuffer + offset);
        memcpy( &(this->meshes[i]), &(this->st_meshes), sizeof(shape_msgs::Mesh));
      }
      uint8_t mesh_poses_lengthT = *(inbuffer + offset++);
      if(mesh_poses_lengthT > mesh_poses_length)
        this->mesh_poses = (geometry_msgs::Pose*)realloc(this->mesh_poses, mesh_poses_lengthT * sizeof(geometry_msgs::Pose));
      offset += 3;
      mesh_poses_length = mesh_poses_lengthT;
      for( uint8_t i = 0; i < mesh_poses_length; i++){
      offset += this->st_mesh_poses.deserialize(inbuffer + offset);
        memcpy( &(this->mesh_poses[i]), &(this->st_mesh_poses), sizeof(geometry_msgs::Pose));
      }
      offset += this->surface.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "grasping_msgs/Object"; };
    const char * getMD5(){ return "0770e300363d18954f6fd25963e4d536"; };

  };

}
#endif