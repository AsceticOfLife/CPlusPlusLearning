/*
 * @Author: Guomw
 * @Date: 2023-05-08 20:53:27
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-10 16:14:24
 * @Description: 展板（观察者）接口和实现
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_
#include <iostream>
#include <vector>
#include "display_behaviour.h"

class Subject;
class Observer {
protected:
    Subject *subject;
public:
    // 构造和析构函数
    Observer(Subject *sub) : subject(sub) {}
    virtual ~Observer() {}
    // 删除其它所有编译器自动增加的成员函数
    Observer(const Observer &) = delete;
    Observer(const Observer &&) = delete;
    Observer & operator=(const Observer &) = delete;
    Observer & operator=(const Observer &&) = delete;

    // interface
    virtual void update(double temperature, double humidity, double pressure) = 0;
};


// 第一个展板
class CurrentObserver : public Observer, public DisplayBehaviour {
private:
    double temperature;
    double humidity;
public:
    // 构造和默认析构函数
    CurrentObserver(Subject *sub);
    virtual ~CurrentObserver();
    // 不会使用这个具体类，只会使用接口调用该类的方法，因此不必删除赋值等成员函数

    // 来自观察者的接口，重写接口函数，由于特征标不同，会覆盖基类的同名函数
    virtual void update(double temperature, double humidity, double pressure);

    // 来自展示行为的接口
    virtual void display();
};




#endif
