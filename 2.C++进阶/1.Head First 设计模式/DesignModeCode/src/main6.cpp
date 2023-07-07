/*
 * @Author: Guomw
 * @Date: 2023-05-18 11:26:50
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-18 11:33:54
 * @Description: 测试命令模式
 */

// #include <iostream>
// #include "6.remote/remote.h"
// #include "6.remote/command.h"
// #include "6.remote/receiver.h"


// int main() {
//     using std::cout;

// // 1.一条命令测试
//     // 创建电灯对象
//     Light light;
//     // 创建命令对象
//     Command * cmd = new LightOn_Command(light);
//     // 创建遥控器
//     Remote * remote = new Remote;
//     // 设置遥控器命令
//     remote->setSlot(cmd);

//     // 命令前电灯状态
//     light.show();
//     // 调用命令
//     remote->pressButton();
//     // 查看命令后电灯状态
//     light.show();

//     // 释放资源
//     delete cmd;
//     delete remote;
    
//     return 0;
// }