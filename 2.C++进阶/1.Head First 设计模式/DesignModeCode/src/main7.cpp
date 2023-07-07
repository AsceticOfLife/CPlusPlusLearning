/*
 * @Author: Guomw
 * @Date: 2023-05-23 11:31:12
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-27 10:54:48
 * @Description: 测试适配器模式
 */

// #include <iostream>
// #include "7.adaptor/duck.h"
// #include "7.adaptor/adaptor.h"


// int main() {
//     using std::cout;
// // 1.测试火鸡伪装鸭子例子
//     Duck *duck = new RealDuck(); // 一支真正的鸭子
//     Chicken *chicken = new RealChinken(); // 一只真正的火鸡
//     // 使用适配器适配火鸡
//     // 使用鸭子的接口
//     Duck *ad = new Adaptor(*chicken);

//     // 测试真正鸭子
//     cout << "Real Duck:\n";
//     duck->quack();
//     duck->fly();
//     // 测试虚假的鸭子
//     cout << "Adapted Duck, actually a chicken:\n";
//     // 调用鸭子的方法
//     // 结果确实在使用chicken的方法
//     // 完成了从一个接口到另一个接口的转换
//     ad->quack();
//     ad->fly(); 

//     delete duck;
//     delete chicken;
//     delete ad;
    
//     return 0;
// }