#!/usr/bin/python
# -*- coding: utf-8 -*-

# Start up ROS pieces.
#PKG = 'my_pkg'
import roslib;# roslib.load_manifest(PKG)
import rospy
import tf

# ROS messages.

from geometry_msgs.msg import PoseStamped


class conversionMocap():
    def __init__(self):
        self.got_new_msg = False
        
        print("created")
        # Create subscribers and publishers.
        sub_pose  = rospy.Subscriber("/vrpn_client_node/arana/pose", PoseStamped, self.pose_mocap_callback)
        self.pub_pose_mocap = rospy.Publisher("convertedMocapNED", PoseStamped)
        self.counter = 0


    # Odometry callback function.
    def pose_mocap_callback(self, msg):
        self.counter = self.counter + 1
        if self.counter % 2 == 0: #to reduce to 50 hz
            new_pose = PoseStamped()
            new_pose = msg
            #self.got_new_msg = False
            new_pose.pose.position.x = msg.pose.position.x
            new_pose.pose.position.y = -msg.pose.position.z
            new_pose.pose.position.z = msg.pose.position.y
            new_pose.pose.orientation.x = msg.pose.orientation.x
            new_pose.pose.orientation.y = -msg.pose.orientation.z
            new_pose.pose.orientation.z = msg.pose.orientation.y
            new_pose.pose.orientation.w = msg.pose.orientation.w
            self.pub_pose_mocap.publish(new_pose)

# Main function.    
if __name__ == '__main__':
    # Initialize the node and name it.
    rospy.init_node('quatCo')
    try:
        conversion = conversionMocap()
        while not rospy.is_shutdown():
            a=1
            #if self.got_new_msg:
                #conversion.publish(self.euler_msg)
                #self.got_new_msg = False
    except rospy.ROSInterruptException: pass
