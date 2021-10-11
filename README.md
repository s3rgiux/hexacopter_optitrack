# hexacopter_optitrack
Repository to operate PX4 based hexacopter using as externel refernce Position from Optitrack


# requires

* Motive
* ROS melodic
* Mavros
* Vrpn client
* PX4 device

# How to Run

This project consider that PX4 is correctly seted up followring the next links.

- https://docs.px4.io/master/en/ros/external_position_estimation.html
- https://risc.readthedocs.io/1-indoor-flight.html

It considers that Motive is calibrated and computers are on the me network with differents IP addresses.

On Motive:

* Creates a Rigid Body on motive and name it (this name will be used).
* Stream the position over VRPN using the up axis as Y.


On ROS:

```
# Clone this workspace on ROS

git clone 

```

install mavros and vrpn
 
```

sudo apt install ros-melodic-mavros ros-melodic-mavros-extras

sudo apt install ros-melodic-vrpn-client-ros 

```

On the file `/src/conversion_coordinates/scripts/conversion_mocap.py` found the line `sub_pose  = rospy.Subscriber("/vrpn_client_node/arana/pose", PoseStamped, self.pose_mocap_callback)` and replace the name `arana` with the name of your rigid body.

# Build

Build workspace with

```
catkin_make
```

#Launch

To launch replace the ip of the next line, with the ip adress of the Motive computer that is stremming over VRPN.

```
 roslaunch control_drone launch_vrpn.launch server:=192.168.11.2:3883
```

# Test

To Test run the script:

```
 rosrun control_drone control_drone_node
```

This dorne wil put PX4 on Offboard mode and could be dangerous so preferently use a RC tranmitter to change the mode just in case








