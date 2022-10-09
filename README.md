本仓库是根据 B 站视频复现的源码，视频地址：

https://space.bilibili.com/411541289/channel/collectiondetail?sid=693700

配合文档食用，理解每个分支的作用

https://yym68686.top/ros

用分支区分了每个实现

- launch-cpp 使用 launch 文件加载两个发布者节点，一个订阅者节点 cpp 实现
- launch-python 使用 launch 文件加载两个发布者节点，一个订阅者节点 python 实现
- lidar-cpp 激光雷达测距实现自动避障 cpp 实现
- map-cpp 载入栅格地图 cpp 实现
- vel-node-cpp 用速度消息包发布消息控制小车运动 cpp 实现
- vel-node-python 用速度消息包发布消息控制小车运动 python 实现
