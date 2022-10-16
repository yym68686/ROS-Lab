使用 ros_control 运动控制

```
sudo apt-get install -y ros-noetic-teleop-twist-keyboard
cd ~
git clone -b arbotix https://github.com/yym68686/ROS-Lab.git
cd ~/catkin_ws/src
oslaunch urdf02_gezebo demo03_env.launch
rosrun teleop_twist_keyboard teleop_twist_keyoard
```

利用键盘控制

```
git add . && git commit -m "运动控制" && git push origin $(git name-rev --name-only HEAD)
```
