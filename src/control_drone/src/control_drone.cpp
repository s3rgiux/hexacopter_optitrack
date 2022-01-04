/*
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 10, state_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            ("mavros/setpoint_position/local", 10);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 0.35;

    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    //while (current_state.mode != "OFFBOARD"){
	if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
        }
    //}
*/
    /*if( current_state.mode != "OFFBOARD" &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
            }
            last_request = ros::Time::now();
    }
    */
/*
    ros::Duration(3).sleep();

    if( !current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0))){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                }
                last_request = ros::Time::now();
     }


    ros::Duration(3).sleep();
*/
/*
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 0.35;

    for(int i = 150; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }
    
    pose.pose.position.x = -0.35;
    pose.pose.position.y = 0;
    pose.pose.position.z = 0.35;

    for(int i = 150; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    pose.pose.position.x = -0.35;
    pose.pose.position.y = 0;
    pose.pose.position.z = 0.0;

    for(int i = 150; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

*/
/*
    arm_cmd.request.value = false;


    if( current_state.armed){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle disarmed");
                }
                last_request = ros::Time::now();
     }

    while(ros::ok()){
         
        local_pos_pub.publish(pose);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
*/




/**
 * @file offb_node.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 10, state_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            ("mavros/setpoint_position/local", 10);
    ros::Publisher local_vel_pub = nh.advertise<geometry_msgs::TwistStamped>
            ("/mavros/setpoint_velocity/cmd_vel", 10);
    
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");
    ros::ServiceClient land_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/land");

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = 0;
    pose.pose.position.y = 0;
    pose.pose.position.z = 0.6;  

    geometry_msgs::TwistStamped velocity_cmd;
    velocity_cmd.twist.linear.x = 0;
    velocity_cmd.twist.linear.y = 0;
    //velocity_cmd.twist.linear.z = -0.6;  

    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    mavros_msgs::CommandBool land_cmd;
    land_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();
    bool enabled_first_time = false;
    bool vehicle_armed = false;
    bool finished = false;
    ros::Time started_mission_time = ros::Time::now();
    while(ros::ok()){

        if( current_state.mode != "OFFBOARD" &&
            (ros::Time::now() - last_request > ros::Duration(5.0)) && enabled_first_time == false){
            if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
                enabled_first_time = true;
            }
            last_request = ros::Time::now();
        } else {
            if( !current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0)) && vehicle_armed == false){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                    vehicle_armed = true;
                }
                last_request = ros::Time::now();
                started_mission_time = ros::Time::now();
            }
        }

        if(enabled_first_time && vehicle_armed && ros::Time::now() - started_mission_time < ros::Duration(5.0)){
		ROS_INFO("take off");
        	
	}else if(enabled_first_time && vehicle_armed && ros::Time::now() - started_mission_time > ros::Duration(6.0) && ros::Time::now() - started_mission_time < ros::Duration(10.0) ){
        	pose.pose.position.x = 0;
    		pose.pose.position.y = 0.0;
    		pose.pose.position.z = 0.6;
                local_pos_pub.publish(pose);
                ROS_INFO("new_pose 1");
		
                //local_vel_pub.publish(velocity_cmd);
        	
	}else if(enabled_first_time && vehicle_armed && ros::Time::now() - started_mission_time > ros::Duration(10.0) && ros::Time::now() - started_mission_time < ros::Duration(14.0) ){
        	pose.pose.position.x = 0;
    		pose.pose.position.y = 0.3;
    		pose.pose.position.z = 0.6;
                local_pos_pub.publish(pose);
                ROS_INFO("new_pose 1");
		
                //local_vel_pub.publish(velocity_cmd);
        	
	}else if(enabled_first_time && vehicle_armed && ros::Time::now() - started_mission_time > ros::Duration(14.0) && ros::Time::now() - started_mission_time < ros::Duration(18.0) ){
        	pose.pose.position.x = 0;
    		pose.pose.position.y = 0.0;
    		pose.pose.position.z = 0.6;
                local_pos_pub.publish(pose);
                ROS_INFO("new_pose 2");
		
                //local_vel_pub.publish(velocity_cmd);
        	
	}else if(enabled_first_time && vehicle_armed && ros::Time::now() - started_mission_time > ros::Duration(18.0) && ros::Time::now() - started_mission_time < ros::Duration(22.0) ){
        	pose.pose.position.x = 0;
    		pose.pose.position.y = -0.3;
    		pose.pose.position.z = 0.6;
                local_pos_pub.publish(pose);
                ROS_INFO("returning");
		
                //local_vel_pub.publish(velocity_cmd);
        	
	}else if(enabled_first_time && vehicle_armed && ros::Time::now() - started_mission_time > ros::Duration(22.0) && ros::Time::now() - started_mission_time < ros::Duration(26.0) ){
        	pose.pose.position.x = 0;
    		pose.pose.position.y = 0.0;
    		pose.pose.position.z = 0.6;
                local_pos_pub.publish(pose);
                ROS_INFO("returning");
		
                //local_vel_pub.publish(velocity_cmd);
        	
	}else if(enabled_first_time && vehicle_armed && ros::Time::now() - started_mission_time > ros::Duration(26.0) && ros::Time::now() - started_mission_time < ros::Duration(30.0) ){
        	pose.pose.position.x = 0;
    		pose.pose.position.y = 0;
    		pose.pose.position.z = -0.3;
                local_pos_pub.publish(pose);
                ROS_INFO("land");
		
                //local_vel_pub.publish(velocity_cmd);
        	
	}else if(ros::Time::now() - started_mission_time > ros::Duration(30.0)){
                finished = true;
                //local_vel_pub.publish(velocity_cmd);
		ROS_INFO("disarm");
                arm_cmd.request.value = false;
 		if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle disarme");

                    vehicle_armed = true;
                }
		

        }
	if (finished == false){
		local_pos_pub.publish(pose);
	}
	

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}


