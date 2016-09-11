#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_broadcaster.h>
#include <sstream>
#include <iostream>

//Declaring a new SimpleActionClient with action of move_base_msgs::MoveBaseAction
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "send_angelbot_goal");
	
	//Initiating move_base client
	MoveBaseClient ac("move_base", true);
	
	//Waiting for server to start
	while(!ac.waitForServer(ros::Duration(5.0))){
		ROS_INFO("Waiting for the move_base action server");
	}

	//Declaring move base goal
	move_base_msgs::MoveBaseGoal goal;
	actionlib_msgs::GoalID cancelgoal;

	//Setting target frame id and time in the goal action
	goal.target_pose.header.frame_id = "map";
	goal.target_pose.header.stamp = ros::Time::now();
	
	//Retrieving pose from command line other wise execute a default value
	switch (argc)
	{
// 		case 4:
// 			goal.target_pose.pose.position.x = atof(argv[1]);
// 			goal.target_pose.pose.position.y = atof(argv[2]);
// 			goal.target_pose.pose.orientation.w = atof(argv[3]);
// 			ROS_INFO("Sending move base goal");
// 		break;
		case 2:
			if (argv[1] == std::string("home"))
			{
				goal.target_pose.pose.position.x = 1.03405;
				goal.target_pose.pose.position.y = -0.908104;
				goal.target_pose.pose.orientation.z = 3.14159;
		// 			goal.target_pose.pose.orientation.w = 0.0306873;
				ROS_INFO("Sending move base goal");
				ROS_INFO("Angel is going back to heaven.");
				//Sending goal
				ac.sendGoal(goal);
				ac.waitForResult();
			}
			else if (argv[1] == std::string("ar_conference_room"))
			{
				goal.target_pose.pose.position.x = 5.24591;
				goal.target_pose.pose.position.y = -3.40158;
				goal.target_pose.pose.orientation.z = -2.094395102;
				//goal.target_pose.pose.orientation.w = 0.576866;
				ROS_INFO("Sending move base goal");
				ac.sendGoal(goal);
				ac.waitForResult();
			}
			else if (argv[1] == std::string("ar_kk_room"))
			{
				goal.target_pose.pose.position.x = 9.9765;
				goal.target_pose.pose.position.y = -1.69872;
				goal.target_pose.pose.orientation.w = 0.0366838;
				ROS_INFO("Sending move base goal");
				ac.sendGoal(goal);
				ac.waitForResult();
			}
			else if (argv[1] == std::string("randomA"))
			{
				goal.target_pose.pose.position.x = 3.0;
				goal.target_pose.pose.position.y = -2.0;
				goal.target_pose.pose.orientation.z = 3.14159;
				ROS_INFO("Sending move base goal");
				ac.sendGoal(goal);
				ac.waitForResult();
			}
			else if (argv[1] == std::string("randomB"))
			{
				goal.target_pose.pose.position.x = -3.0;
				goal.target_pose.pose.position.y = -2.0;
				goal.target_pose.pose.orientation.z = 3.14159;
				ROS_INFO("Sending move base goal");
				ac.sendGoal(goal);
				ac.waitForResult();
			}
			else if (argv[1] == std::string("cancelgoal"))
			{
				if (ac.getState() == actionlib::SimpleClientGoalState::ACTIVE)
				{
					ROS_INFO("Goal cancelling");
					ac.cancelGoal();
					ac.waitForResult();
				}
			}
			else
			{
				ROS_INFO("Sending move base goal");
				ROS_INFO("Invalid goal!!!");
			}

			if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
			{
				ROS_INFO_STREAM("angel has arrived " << argv[1]);
				ROS_INFO("angel: home sweet home! ");
			}
			else if (ac.getState() == actionlib::SimpleClientGoalState::ABORTED)
			{
				ROS_INFO_STREAM("Goal cancelled");
			}
			else
			{
				ROS_INFO("The base failed for some reason");
			}
		break;
		case 4:
			for (int i=0; i < int(atof(argv[3]))*2; i++)
			{
				//Waiting for server to start
				ROS_INFO_STREAM( i << "turn.");
				while(!ac.waitForServer(ros::Duration(5.0))){
					ROS_INFO("Waiting for the move_base action server");
				}
				//Setting target frame id and time in the goal action
				goal.target_pose.header.frame_id = "map";
				goal.target_pose.header.stamp = ros::Time::now();
				int j = int(remainder(i,2))+1;
				if (argv[j] == std::string("home"))
				{
					goal.target_pose.pose.position.x = 1.03405;
					goal.target_pose.pose.position.y = -0.908104;
					goal.target_pose.pose.orientation.z = 3.14159;
			// 			goal.target_pose.pose.orientation.w = 0.0306873;
					ROS_INFO("Sending move base goal");
					ROS_INFO("Angel is going back to heaven.");
					//Sending goal
					ac.sendGoal(goal);
					ac.waitForResult();
				}
				else if (argv[j] == std::string("ar_conference_room"))
				{
					goal.target_pose.pose.position.x = 5.24591;
					goal.target_pose.pose.position.y = -3.40158;
					goal.target_pose.pose.orientation.z = 0.0;
					//goal.target_pose.pose.orientation.w = 0.576866;
					ROS_INFO("Sending move base goal");
					ac.sendGoal(goal);
					ac.waitForResult();
				}
				else if (argv[j] == std::string("ar_kk_room"))
				{
					goal.target_pose.pose.position.x = 9.9765;
					goal.target_pose.pose.position.y = -1.69872;
					goal.target_pose.pose.orientation.w = 0.0366838;
					ROS_INFO("Sending move base goal");
					ac.sendGoal(goal);
					ac.waitForResult();
				}
				else if (argv[j] == std::string("cancelgoal"))
				{
					if (ac.getState() == actionlib::SimpleClientGoalState::ACTIVE)
					{
						ROS_INFO("Goal cancelling");
						ac.cancelGoal();
						ac.waitForResult();
					}
				}
				else
				{
					ROS_INFO("Sending move base goal");
					ROS_INFO("Invalid goal!!!");
				}

				if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
				{
					ROS_INFO_STREAM("angel has arrived " << argv[j]);
					ROS_INFO_STREAM("Begin next round trip to " << argv[j]);
					ROS_INFO("angel: I am exhausted! ");
				}
				else if (ac.getState() == actionlib::SimpleClientGoalState::ABORTED)
				{
					ROS_INFO_STREAM("Goal cancelled");
				}
				else
				{
					ROS_INFO("The base failed for some reason");
				}
			}
		break;
		default:
			ROS_INFO("Invalid command. Nothing happens");
	}
	return 0;
}
