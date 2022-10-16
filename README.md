使用 ros_control 运动控制 结合 rviz gazebo

```
sudo apt-get install -y ros-noetic-teleop-twist-keyboard
cd ~
git clone -b move-rviz https://github.com/yym68686/ROS-Lab.git
cd ~/catkin_ws/src
roslaunch urdf02_gezebo demo03_env.launch
roslaunch urdf02_gezebo demo04_sensor.launch
rosrun teleop_twist_keyboard teleop_twist_keyboard.py
rostopic pub -r 10 /cmd_vel geometry_msgs/Twist "linear:
  x: 1.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 1.0"
```

利用键盘控制

```
git add . && git commit -m "move-rviz" && git push origin $(git name-rev --name-only HEAD)
```
