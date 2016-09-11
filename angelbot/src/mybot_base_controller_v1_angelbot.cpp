#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <angelbot/WheelCmd.h>
#include <iostream>

using namespace std;
double wheelRadius, wheelSeparation;

ros::Publisher cmd_wheel_angularVel_pub;
ros::Subscriber cmd_vel_sub;
double rate;

void cmd_velCallback(const geometry_msgs::Twist &twist_aux)
{
  angelbot::WheelCmd wheel;
  geometry_msgs::Twist twist = twist_aux;
  double vel_x = twist_aux.linear.x;
  double vel_th = twist_aux.angular.z;
  double right_vel = 0.0;
  double left_vel = 0.0;

  // (vel_x, vel_th) --> (vl, vr)
  left_vel = (2*vel_x - vel_th * wheelSeparation) / 2 / wheelRadius;
  right_vel =(2*vel_x + vel_th * wheelSeparation) / 2 / wheelRadius;

  // publish to /cmd_wheel_angularVel
  wheel.speed1 = left_vel;
  wheel.speed2 = right_vel;
  wheel.driverstate = true;
  cmd_wheel_angularVel_pub.publish(wheel);
  
}

int main(int argc, char** argv){
  ros::init(argc, argv, "mybot_base_controller");
  ros::NodeHandle n1, n2;
  if(n1.getParam("rate", rate))
  {
	ROS_INFO_STREAM("rate from param =" << rate);
  }
  if(n1.getParam("wheelSeparation", wheelSeparation))
  {
	ROS_INFO_STREAM("wheelSeparation from param =" << wheelSeparation);
  }

  if(n1.getParam("wheelRadius", wheelRadius))
  {
	ROS_INFO_STREAM("wheelRadius from param =" << wheelRadius);
  }

  cmd_vel_sub = n1.subscribe("/angelbot/cmd_vel", 10, cmd_velCallback);
  cmd_wheel_angularVel_pub = n2.advertise<angelbot::WheelCmd>("cmd_wheel_angularVel", 50);
  ros::Rate loop_rate(rate);

  while(ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }
}


