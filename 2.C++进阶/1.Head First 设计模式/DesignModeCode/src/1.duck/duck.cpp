/*
 * @Author: Guomw
 * @Date: 2023-05-08 20:03:51
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-08 20:30:08
 * @Description: 鸭子接口实现
 */

#include "duck.h"

// 接口实现
Duck::~Duck() {
    delete f;
}
// 动态修改鸭子的飞行行为
void Duck::changeFly(FlyBehaviour *fly) { f = fly; }

// 鸭子共有的行为
void Duck::display() {
    std::cout << "Tall: " << tall << "\nWeight: " << weight << "\n";
    f->fly();
    std::cout << '\n';
}

// 不同的实现
// 由于不同的实现是初始化飞行方式的不同
// 只在构造函数中能看出实现的不同

