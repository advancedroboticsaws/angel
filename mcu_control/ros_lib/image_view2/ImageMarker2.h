#ifndef _ROS_image_view2_ImageMarker2_h
#define _ROS_image_view2_ImageMarker2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/PoseStamped.h"
#include "std_msgs/ColorRGBA.h"
#include "ros/duration.h"
#include "image_view2/PointArrayStamped.h"

namespace image_view2
{

  class ImageMarker2 : public ros::Msg
  {
    public:
      std_msgs::Header header;
      const char* ns;
      int32_t id;
      int32_t type;
      int32_t action;
      geometry_msgs::Point position;
      geometry_msgs::PointStamped position3D;
      geometry_msgs::PoseStamped pose;
      float scale;
      float width;
      std_msgs::ColorRGBA outline_color;
      int8_t filled;
      std_msgs::ColorRGBA fill_color;
      ros::Duration lifetime;
      int8_t arc;
      float angle;
      uint8_t points_length;
      geometry_msgs::Point st_points;
      geometry_msgs::Point * points;
      image_view2::PointArrayStamped points3D;
      uint8_t outline_colors_length;
      std_msgs::ColorRGBA st_outline_colors;
      std_msgs::ColorRGBA * outline_colors;
      uint8_t frames_length;
      char* st_frames;
      char* * frames;
      const char* text;
      bool left_up_origin;
      bool ratio_scale;
      enum { CIRCLE = 0 };
      enum { LINE_STRIP = 1 };
      enum { LINE_LIST = 2 };
      enum { POLYGON = 3 };
      enum { POINTS = 4 };
      enum { FRAMES = 5 };
      enum { TEXT = 6 };
      enum { LINE_STRIP3D = 7 };
      enum { LINE_LIST3D = 8 };
      enum { POLYGON3D = 9 };
      enum { POINTS3D = 10 };
      enum { TEXT3D = 11 };
      enum { CIRCLE3D = 12 };
      enum { ADD = 0 };
      enum { REMOVE = 1 };

    ImageMarker2():
      header(),
      ns(""),
      id(0),
      type(0),
      action(0),
      position(),
      position3D(),
      pose(),
      scale(0),
      width(0),
      outline_color(),
      filled(0),
      fill_color(),
      lifetime(),
      arc(0),
      angle(0),
      points_length(0), points(NULL),
      points3D(),
      outline_colors_length(0), outline_colors(NULL),
      frames_length(0), frames(NULL),
      text(""),
      left_up_origin(0),
      ratio_scale(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_ns = strlen(this->ns);
      memcpy(outbuffer + offset, &length_ns, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->ns, length_ns);
      offset += length_ns;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_action.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_action.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_action.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->action);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->position3D.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_scale;
      u_scale.real = this->scale;
      *(outbuffer + offset + 0) = (u_scale.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scale.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scale.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scale.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scale);
      union {
        float real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      offset += this->outline_color.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_filled;
      u_filled.real = this->filled;
      *(outbuffer + offset + 0) = (u_filled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->filled);
      offset += this->fill_color.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->lifetime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lifetime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lifetime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lifetime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lifetime.sec);
      *(outbuffer + offset + 0) = (this->lifetime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lifetime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lifetime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lifetime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lifetime.nsec);
      union {
        int8_t real;
        uint8_t base;
      } u_arc;
      u_arc.real = this->arc;
      *(outbuffer + offset + 0) = (u_arc.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->arc);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      *(outbuffer + offset++) = points_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      offset += this->points3D.serialize(outbuffer + offset);
      *(outbuffer + offset++) = outline_colors_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < outline_colors_length; i++){
      offset += this->outline_colors[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset++) = frames_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < frames_length; i++){
      uint32_t length_framesi = strlen(this->frames[i]);
      memcpy(outbuffer + offset, &length_framesi, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->frames[i], length_framesi);
      offset += length_framesi;
      }
      uint32_t length_text = strlen(this->text);
      memcpy(outbuffer + offset, &length_text, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      union {
        bool real;
        uint8_t base;
      } u_left_up_origin;
      u_left_up_origin.real = this->left_up_origin;
      *(outbuffer + offset + 0) = (u_left_up_origin.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_up_origin);
      union {
        bool real;
        uint8_t base;
      } u_ratio_scale;
      u_ratio_scale.real = this->ratio_scale;
      *(outbuffer + offset + 0) = (u_ratio_scale.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ratio_scale);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_ns;
      memcpy(&length_ns, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ns; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ns-1]=0;
      this->ns = (char *)(inbuffer + offset-1);
      offset += length_ns;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->action = u_action.real;
      offset += sizeof(this->action);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->position3D.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_scale;
      u_scale.base = 0;
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scale = u_scale.real;
      offset += sizeof(this->scale);
      union {
        float real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      offset += this->outline_color.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_filled;
      u_filled.base = 0;
      u_filled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->filled = u_filled.real;
      offset += sizeof(this->filled);
      offset += this->fill_color.deserialize(inbuffer + offset);
      this->lifetime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->lifetime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lifetime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lifetime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lifetime.sec);
      this->lifetime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->lifetime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lifetime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lifetime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lifetime.nsec);
      union {
        int8_t real;
        uint8_t base;
      } u_arc;
      u_arc.base = 0;
      u_arc.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->arc = u_arc.real;
      offset += sizeof(this->arc);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
      uint8_t points_lengthT = *(inbuffer + offset++);
      if(points_lengthT > points_length)
        this->points = (geometry_msgs::Point*)realloc(this->points, points_lengthT * sizeof(geometry_msgs::Point));
      offset += 3;
      points_length = points_lengthT;
      for( uint8_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(geometry_msgs::Point));
      }
      offset += this->points3D.deserialize(inbuffer + offset);
      uint8_t outline_colors_lengthT = *(inbuffer + offset++);
      if(outline_colors_lengthT > outline_colors_length)
        this->outline_colors = (std_msgs::ColorRGBA*)realloc(this->outline_colors, outline_colors_lengthT * sizeof(std_msgs::ColorRGBA));
      offset += 3;
      outline_colors_length = outline_colors_lengthT;
      for( uint8_t i = 0; i < outline_colors_length; i++){
      offset += this->st_outline_colors.deserialize(inbuffer + offset);
        memcpy( &(this->outline_colors[i]), &(this->st_outline_colors), sizeof(std_msgs::ColorRGBA));
      }
      uint8_t frames_lengthT = *(inbuffer + offset++);
      if(frames_lengthT > frames_length)
        this->frames = (char**)realloc(this->frames, frames_lengthT * sizeof(char*));
      offset += 3;
      frames_length = frames_lengthT;
      for( uint8_t i = 0; i < frames_length; i++){
      uint32_t length_st_frames;
      memcpy(&length_st_frames, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_frames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_frames-1]=0;
      this->st_frames = (char *)(inbuffer + offset-1);
      offset += length_st_frames;
        memcpy( &(this->frames[i]), &(this->st_frames), sizeof(char*));
      }
      uint32_t length_text;
      memcpy(&length_text, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
      union {
        bool real;
        uint8_t base;
      } u_left_up_origin;
      u_left_up_origin.base = 0;
      u_left_up_origin.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_up_origin = u_left_up_origin.real;
      offset += sizeof(this->left_up_origin);
      union {
        bool real;
        uint8_t base;
      } u_ratio_scale;
      u_ratio_scale.base = 0;
      u_ratio_scale.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ratio_scale = u_ratio_scale.real;
      offset += sizeof(this->ratio_scale);
     return offset;
    }

    const char * getType(){ return "image_view2/ImageMarker2"; };
    const char * getMD5(){ return "8efc23e411f94f2c04288719c078c291"; };

  };

}
#endif