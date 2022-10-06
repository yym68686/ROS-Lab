#include <ros/ros.h>
#include <std_msgs/String.h>

// 订阅对象回调函数，用于接收消息，并做处理
void chao_callback(std_msgs::String msg){
	ROS_INFO(msg.data.c_str());
}

void yao_callback(std_msgs::String msg){
	ROS_WARN(msg.data.c_str());
}

int main(int argc, char *argv[])
{
	// ROS_INFO 编码方式受 lacale 环境设置影响，输出函数只支持英文字符显示
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "ma_node");

    // nh 负责管理话题创建，消息发送
    ros::NodeHandle nh;
    // 新建消息订阅对象，确定话题名称和订阅对象消息容量，这里最多可以接收10个消息，话题名称不能是中文，定义回调函数名
    ros::Subscriber sub1 = nh.subscribe("Topic1", 10, chao_callback);
    ros::Subscriber sub2 = nh.subscribe("Topic2", 10, yao_callback);

    while(ros::ok()) {
        // 不断查看有无新的消息，并调用回调函数
        ros::spinOnce();
    }
    return 0;
}