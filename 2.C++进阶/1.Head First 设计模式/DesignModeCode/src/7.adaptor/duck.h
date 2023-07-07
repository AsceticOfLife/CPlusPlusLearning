/*
 * @Author: Guomw
 * @Date: 2023-05-23 11:16:14
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-23 11:31:10
 * @Description: 鸭子(同时也是适配器类)接口与实现
 */

#ifndef DUCK_H_
#define DUCK_H_
#include <iostream>

// 鸭子抽象类
class Duck {
public:
    // 使用默认构造函数
    virtual ~Duck() {}

    // interface
    virtual void quack() = 0;
    virtual void fly() = 0;
};

// 鸭子实现
class RealDuck : public Duck {
public:
    // default constructor and destructor

    // interface implementation
    virtual void quack() {
        std::cout << "gagagaga...\n";
    }

    virtual void fly() {
        std::cout << "I can fly!\n";
    }
};

#endif
