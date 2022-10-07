#!/usr/bin/env python3
#coding=utf-8

import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("yao_node")
    rospy.logwarn("yao ok!")
    # 新建发布对象，指定消息标题，消息包内容类型，消息包容量
    pub = rospy.Publisher("Topic2", String, queue_size=10)
    # 发布消息频率为10HZ
    rate = rospy.Rate(10)
    
    while not rospy.is_shutdown():
        rospy.loginfo("yao going!")
        msg = String()
        msg.data = "yao fly!"
        pub.publish(msg)
        rate.sleep()