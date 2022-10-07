#!/usr/bin/env python3
#coding=utf-8

import rospy
from std_msgs.msg import String

def chao_callback(msg):
    rospy.loginfo(msg.data)

def yao_callback(msg):
    rospy.logwarn(msg.data)

if __name__ == "__main__":
    rospy.init_node("ma_node")
    
    sub1 = rospy.Subscriber("Topic1", String, chao_callback, queue_size=10)
    sub2 = rospy.Subscriber("Topic2", String, yao_callback, queue_size=10)
    
    rospy.spin()