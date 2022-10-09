#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "map_pub_node");

    // nh 负责管理话题创建，消息发送
    ros::NodeHandle nh;
    // 新建消息订阅对象，确定话题名称和订阅对象消息容量，这里最多可以接收10个消息，话题名称不能是中文，定义回调函数名
    ros::Publisher pub = nh.advertise<nav_msgs::OccupancyGrid>("/map", 10);
    
    ros::Rate r(1);
    
    while (ros::ok()){
        nav_msgs::OccupancyGrid msg;
        
        msg.header.frame_id = "map";
        msg.header.stamp = ros::Time::now();
        
        // 坐标（0，0）是地图左下角
        msg.info.origin.position.x = 0;
        msg.info.origin.position.y = 0;
        // 栅格边长 单位m
        msg.info.resolution = 1.0;
        // 地图宽度
        msg.info.width = 4;
        // 地图高度
        msg.info.height = 2;
        
        // 地图形状
        msg.data.resize(4*2);
        // 栅格数据 -1 表示未知
        msg.data[0] = 100;
        msg.data[1] = 100;
        msg.data[2] = 0;
        msg.data[3] = -1;
        
        pub.publish(msg);
        r.sleep();
    }
    return 0;
}