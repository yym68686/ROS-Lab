arbotix

```
cd ~
git clone -b arbotix https://github.com/yym68686/ROS-Lab.git
cd ~/catkin_ws/src
oslaunch urdf01_rviz demo07_control.launch
rostopic pub -r 10 /cmd_vel geometry_msgs/Twist "linear:
  x: 1.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 1.0"
```

如果地图跟着小车一起动，需要在 Grid 设置里把 Reference Frame 设置为 odom

```
git add . && git commit -m "arbotix" && git push origin $(git name-rev --name-only HEAD)
```
