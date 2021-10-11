# hexacopter_optitrack
Repository to operate PX4 based hexacopter using as externel refernce Position from Optitrack


# requires

* Motive
* ROS melodic
* Mavros
* Vrpn client

# How to Run

It considers that Motive is calibrated and computers are on the me network with differents IP addresses.

On Motive:

* Creates a Rigid Body on motive and name it (this name will be used).
* Stream the position over VRPN using the up axis as Y.


On ROS:

```
# Clone this workspace on ROS

git clone 

```
 
```
# install mavros and vrpn

sudo apt install ros-melodic-mavros ros-melodic-mavros-extras

sudo apt install ros-melodic-vrpn-client-ros 

```

On the file `/src/conversion_coordinates/scripts/conversion_mocap.py` found the line `sub_pose  = rospy.Subscriber("/vrpn_client_node/arana/pose", PoseStamped, self.pose_mocap_callback)` and replace the name `arana` with the name of your rigid body.

# Build

```
# Build workspace with

catkin_make

```




