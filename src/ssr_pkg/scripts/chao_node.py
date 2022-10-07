#!/usr/bin/env python3
#coding=utf-8

import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("chao_node")
    rospy.logwarn("chao ok!")
    # 新建发布对象，指定消息标题，消息包内容类型，消息包容量
    pub = rospy.Publisher("Topic1", String, queue_size=10)
    # 发布消息频率为10HZ
    rate = rospy.Rate(10)
    
    while not rospy.is_shutdown():
        rospy.loginfo("chao going!")
        msg = String()
        msg.data = "chao fly!"
        pub.publish(msg)
        rate.sleep()