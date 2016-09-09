#ifndef _ROS_robot_mechanism_controllers_JTCartesianControllerState_h
#define _ROS_robot_mechanism_controllers_JTCartesianControllerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Wrench.h"
#include "std_msgs/Float64MultiArray.h"

namespace robot_mechanism_controllers
{

  class JTCartesianControllerState : public ros::Msg
  {
    public:
      std_msgs::Header header;
      geometry_msgs::PoseStamped x;
      geometry_msgs::PoseStamped x_desi;
      geometry_msgs::PoseStamped x_desi_filtered;
      geometry_msgs::Twist x_err;
      geometry_msgs::Twist xd;
      geometry_msgs::Twist xd_desi;
      geometry_msgs::Wrench F;
      uint8_t tau_pose_length;
      float st_tau_pose;
      float * tau_pose;
      uint8_t tau_posture_length;
      float st_tau_posture;
      float * tau_posture;
      uint8_t tau_length;
      float st_tau;
      float * tau;
      std_msgs::Float64MultiArray J;
      std_msgs::Float64MultiArray N;

    JTCartesianControllerState():
      header(),
      x(),
      x_desi(),
      x_desi_filtered(),
      x_err(),
      xd(),
      xd_desi(),
      F(),
      tau_pose_length(0), tau_pose(NULL),
      tau_posture_length(0), tau_posture(NULL),
      tau_length(0), tau(NULL),
      J(),
      N()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->x.serialize(outbuffer + offset);
      offset += this->x_desi.serialize(outbuffer + offset);
      offset += this->x_desi_filtered.serialize(outbuffer + offset);
      offset += this->x_err.serialize(outbuffer + offset);
      offset += this->xd.serialize(outbuffer + offset);
      offset += this->xd_desi.serialize(outbuffer + offset);
      offset += this->F.serialize(outbuffer + offset);
      *(outbuffer + offset++) = tau_pose_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tau_pose_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tau_pose[i]);
      }
      *(outbuffer + offset++) = tau_posture_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tau_posture_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tau_posture[i]);
      }
      *(outbuffer + offset++) = tau_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < tau_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->tau[i]);
      }
      offset += this->J.serialize(outbuffer + offset);
      offset += this->N.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->x.deserialize(inbuffer + offset);
      offset += this->x_desi.deserialize(inbuffer + offset);
      offset += this->x_desi_filtered.deserialize(inbuffer + offset);
      offset += this->x_err.deserialize(inbuffer + offset);
      offset += this->xd.deserialize(inbuffer + offset);
      offset += this->xd_desi.deserialize(inbuffer + offset);
      offset += this->F.deserialize(inbuffer + offset);
      uint8_t tau_pose_lengthT = *(inbuffer + offset++);
      if(tau_pose_lengthT > tau_pose_length)
        this->tau_pose = (float*)realloc(this->tau_pose, tau_pose_lengthT * sizeof(float));
      offset += 3;
      tau_pose_length = tau_pose_lengthT;
      for( uint8_t i = 0; i < tau_pose_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_tau_pose));
        memcpy( &(this->tau_pose[i]), &(this->st_tau_pose), sizeof(float));
      }
      uint8_t tau_posture_lengthT = *(inbuffer + offset++);
      if(tau_posture_lengthT > tau_posture_length)
        this->tau_posture = (float*)realloc(this->tau_posture, tau_posture_lengthT * sizeof(float));
      offset += 3;
      tau_posture_length = tau_posture_lengthT;
      for( uint8_t i = 0; i < tau_posture_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_tau_posture));
        memcpy( &(this->tau_posture[i]), &(this->st_tau_posture), sizeof(float));
      }
      uint8_t tau_lengthT = *(inbuffer + offset++);
      if(tau_lengthT > tau_length)
        this->tau = (float*)realloc(this->tau, tau_lengthT * sizeof(float));
      offset += 3;
      tau_length = tau_lengthT;
      for( uint8_t i = 0; i < tau_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_tau));
        memcpy( &(this->tau[i]), &(this->st_tau), sizeof(float));
      }
      offset += this->J.deserialize(inbuffer + offset);
      offset += this->N.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "robot_mechanism_controllers/JTCartesianControllerState"; };
    const char * getMD5(){ return "6ecdaa599ea0d27643819ae4cd4c43d0"; };

  };

}
#endif