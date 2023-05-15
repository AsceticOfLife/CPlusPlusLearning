/*
 * @Author: Guomw
 * @Date: 2023-05-08 19:19:13
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-08 20:36:03
 * @Description: 算法族实现
 */

#include "behaviour.h"

// 飞行行为实现
void Fly1::fly() {
    std::cout << "Fly with Wings!";
}


void Fly2::fly() {
    std::cout << "Fly with fliding!";
}

// 增加一种新的飞行方式
void FlyRocket::fly() {
    std::cout << "Fly By Rocket!";
}
