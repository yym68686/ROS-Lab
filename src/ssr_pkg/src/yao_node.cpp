#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "yao_node");

    // nh 负责管理话题创建，消息发送
    ros::NodeHandle nh;
    // 规定发布信道的主题名和信道容量，这里最多可以接收10个消息
    ros::Publisher pub = nh.advertise<std_msgs::String>("Topic2", 10);
    ros:: Rate loop_rate(10);

    while(ros::ok()) {
        printf("yao ok\n");
        // 初始化消息对象
        std_msgs::String msg;
        // 消息内容
        msg.data = "飞+++";
        // 发送消息
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}