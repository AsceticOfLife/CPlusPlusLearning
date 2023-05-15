/*
 * @Author: Guomw
 * @Date: 2023-05-08 19:31:13
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-08 20:38:38
 * @Description: 鸭子接口和实现
 */
#ifndef DUCK_H_
#define DUCK_H_
#include "behaviour.h"
#include <iostream>

class Duck {
private:
    double tall;
    double weight;
    FlyBehaviour *f;
public:
    // 不同的实现初始化设置的飞行方式不同
    Duck(double t, double w, FlyBehaviour *b) : tall(t), weight(w), f(b) {}
    virtual ~Duck() = 0; // 只是为了标识这是一个抽象基类

    // 动态修改鸭子的飞行行为
    void changeFly(FlyBehaviour *fly);

    // 鸭子共有的行为
    void display();

    // 其它鸭子共有的行为
    // ...
};

// 两种具体的鸭子实现
class LittleDuck : public Duck {
public:
    LittleDuck(double t, double w) : Duck(t, w, new Fly1) {}
    virtual ~LittleDuck() {}
};

class PlasticDuck : public Duck {
public:
    PlasticDuck(double t, double w) : Duck(t, w, new Fly2) {}
    virtual ~PlasticDuck() {}
};

#endif
