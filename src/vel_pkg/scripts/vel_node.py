#!/usr/bin/env python3
#coding=utf-8

import rospy
from geometry_msgs.msg import Twist

if __name__ == "__main__":
    rospy.init_node("vel_node")
    
    vel_pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)
    
    vel_msg = Twist()
    vel_msg.linear.x = 0.1
    vel_msg.angular.z = 0.5
    
    rate = rospy.Rate(30)
    while not rospy.is_shutdown():
        vel_pub.publish(vel_msg)
        rate.sleep()