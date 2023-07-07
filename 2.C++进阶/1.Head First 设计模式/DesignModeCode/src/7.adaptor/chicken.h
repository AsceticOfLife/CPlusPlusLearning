/*
 * @Author: Guomw
 * @Date: 2023-05-23 11:17:29
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-23 11:25:55
 * @Description: 火鸡类接口(作为被适配者)与实现
 */
#ifndef CHICKEN_H_
#define CHICKEN_H_
#include <iostream>

// 抽象火鸡类
class Chicken {
public:
    // 使用默认构造函数
    virtual ~Chicken() {}

    // interface
    virtual void quack() = 0;
    virtual void fly() = 0;
};

// 火鸡实现
class RealChinken : public Chicken {
public:
    // default constructor and destructor


    // interface implementation
    virtual void quack() {
        std::cout << "jijijiji...\n";
    }

    virtual void fly() {
        std::cout << "fly a short distance!\n";
    }

};

#endif
