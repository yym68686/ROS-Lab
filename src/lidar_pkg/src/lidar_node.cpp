#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

// 全局变量可以在回调函数中使用
ros::Publisher vel_pub;

// 有障碍物，维持转向状态
int nCount = 0;

// 订阅对象回调函数，用于接收消息，并做处理
void Lidar_callback(const sensor_msgs::LaserScan msg){
    float fMidDist = msg.ranges[180];
	ROS_INFO("%f m", fMidDist);
    
    // nCount 大于零说明遇到障碍物了，所以一直减减，屏蔽向前走的代码
    if (nCount > 0) {
        nCount--;
        return;
    }
    
    // 定义速度消息包
    geometry_msgs::Twist vel_cmd;
    if (fMidDist < 1.5) {
        // 遇到障碍物，转弯
        vel_cmd.angular.z = 0.3;
        nCount = 50;
    }
    else {
        // 没有障碍物，向前走
        vel_cmd.linear.x = 0.05;
    }
    // 发布消息，控制小车
    vel_pub.publish(vel_cmd);
}

int main(int argc, char *argv[])
{
	// ROS_INFO 编码方式受 lacale 环境设置影响，输出函数只支持英文字符显示
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "lidar_node");

    // nh 负责管理话题创建，消息发送
    ros::NodeHandle nh;
    // 新建消息订阅对象，确定话题名称和订阅对象消息容量，这里最多可以接收10个消息，话题名称不能是中文，定义回调函数名
    ros::Subscriber lidar_sub = nh.subscribe("/scan", 10, Lidar_callback);
    vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    
    ros::spin();
    return 0;
}