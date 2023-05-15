/*
 * @Author: Guomw
 * @Date: 2023-05-08 19:06:25
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-08 20:52:21
 * @Description: 测试策略模式
 */

// #include <iostream>
// #include "1.duck/duck.h"

// int main() {
//     using std::cout;

//     cout << "Initialize a littleduck who can fly with wings: \n";
//     LittleDuck d1(12, 20);
//     d1.display();
    
//     cout << "Change the Fly Behaviour to NO.2 fly: \n";
//     d1.changeFly(new Fly2);
//     d1.display();

//     // 增加一种新的飞行方式不需要对Duck类进行修改
//     d1.changeFly(new FlyRocket);
//     d1.display();


//     return 0;
// }