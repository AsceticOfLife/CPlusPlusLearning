/*
 * @Author: Guomw
 * @Date: 2023-05-18 11:15:15
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-18 11:39:18
 * @Description: 命令接收者类
 */
#ifndef RECEIVER_H_
#define RECEIVER_H_
#include <iostream>
// 电灯类
class Light {
private:
    int state; // state of light
public:
    Light(int s = 0) : state(s) {}
    ~Light() {}

    // 禁用复制构造函数避免作为函数参数时按值传递
    Light(const Light &other) = delete;


    // method
    void on() { state = 1; }
    void off() { state = 0; }
    void show() {
        if (state == 0) std::cout << "light is off\n";
        else std::cout << "light is on\n";
    }
};

#endif
