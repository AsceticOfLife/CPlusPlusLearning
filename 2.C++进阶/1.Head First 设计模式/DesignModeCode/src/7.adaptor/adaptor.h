/*
 * @Author: Guomw
 * @Date: 2023-05-23 11:18:29
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-23 11:31:00
 * @Description: 适配器实现
 */
#ifndef ADAPTOR_H_
#define ADAPTOR_H_
#include "duck.h"
#include "chicken.h"

// 实现伪装鸭子类
class Adaptor : public Duck {
private:
    Chicken &ch;
public:
    Adaptor(Chicken &c) : ch(c) {}
    virtual ~Adaptor() {}

    // interface implementation
    virtual void quack() {
        // 调用火鸡的方法
        ch.quack();
    }

    virtual void fly() {
        ch.fly();
    }
};

#endif
