## 2. Estimate Initial Pose

Initial Pose Estimation must be performed before running the Navigation as this process initializes the AMCL parameters that are critical in Navigation. TurtleBot3 has to be correctly located on the map with the LDS sensor data that neatly overlaps the displayed map.

1. Click the 2D Pose Estimate button in the RViz2 menu.
2. Click on the map where the actual robot is located and drag the large green arrow toward the direction where the robot is facing.
3. Repeat step 1 and 2 until the LDS sensor data is overlayed on the saved map. 
4. Launch keyboard teleoperation node to precisely locate the robot on the map.

```
ros2 run turtlebot3_teleop teleop_keyboard
```

5. Move the robot back and forth a bit to collect the surrounding environment information and narrow down the estimated location of the TurtleBot3 on the map which is displayed with tiny green arrows.
 
6. Terminate the keyboard teleoperation node by entering Ctrl + C to the teleop node terminal in order to prevent different cmd_vel values are published from multiple nodes during Navigation.

## 3. Set Navigation Goal

1. Click the Navigation2 Goal button in the RViz2 menu.
2. Click on the map to set the destination of the robot and drag the green arrow toward the direction where the robot will be facing.
a. This green arrow is a marker that can specify the destination of the robot.
b. The root of the arrow is x, y coordinate of the destination, and the angle θ is determined by the orientation of the arrow.
c. As soon as x, y, θ are set, TurtleBot3 will start moving to the destination immediately. 

## 4. Tuning Guide

Navigation2 stack has many parameters to change performances for different robots. Although it’s similar to the ROS1 Navigation, please refer to the Configuration Guide of Navigation2 or ROS Navigation Tuning Guide by Kaiyu Zheng for more details.

1. Costmap Parameters
a. inflation_layer.inflation_radius
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
This parameter makes inflation area from the obstacle. Path would be planned in order that it does not across this area. It is safe that to set this to be bigger than robot radius. For more information, please refer to the costmap_2d wiki.


b. inflation_layer.cost_scaling_factor
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
This is an inverse proportional factor that is multiplied by the value of the costmap. If this parameter is increased, the value of the costmap is decreased.

The optimal path for the robot to pass through obstacles is to take a median path between them. Setting a smaller value for this parameter will create a farther path from the obstacles.

2. dwb_controller
a. max_vel_x
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
This factor is set the maximum value of translational velocity.
b. min_vel_x
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
This factor is set the minimum value of translational velocity. If set this negative, the robot can move backwards.
c. max_vel_y
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The maximum y velocity for the robot in m/s.
d. min_vel_y
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The minimum y velocity for the robot in m/s.
e. max_vel_theta
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
Actual value of the maximum rotational velocity. The robot can not be faster than this.
f. min_speed_theta
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
Actual value of the minimum rotational speed. The robot can not be slower than this.
g. max_speed_xy
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The absolute value of the maximum translational velocity for the robot in m/s.
h. min_speed_xy
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The absolute value of the minimum translational velocity for the robot in m/s.
i. acc_lim_x
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The x acceleration limit of the robot in meters/sec^2.
j. acc_lim_y
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The y acceleration limit of the robot in meters/sec^2.
k. acc_lim_theta
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The rotational acceleration limit of the robot in radians/sec^2.
l. decel_lim_x
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The deceleration limit of the robot in the x direction in m/s^2.
m. decel_lim_y
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The deceleration limit of the robot in the y direction in m/s^2.
n. decel_lim_theta
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The deceleration limit of the robot in the theta direction in rad/s^2.
o. xy_goal_tolerance
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The x,y distance allowed when the robot reaches its goal pose.
p. yaw_goal_tolerance
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
The yaw angle allowed when the robot reaches its goal pose.
q. transform_tolerance
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
It allows the latency for tf messages.
r. sim_time
Defined in turtlebot3_navigation2/param/${TB3_MODEL}.yaml
This factor is set forward simulation in seconds. Setting this too small makes robot difficult to pass a narrow space while large value limits dynamic turns. You can observe the defferences of length of the yellow line in below image that represents the simulation path.
