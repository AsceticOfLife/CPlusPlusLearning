/*
 * @Author: Guomw
 * @Date: 2023-05-11 11:38:37
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-11 11:44:48
 * @Description: 具体的饮料定义
 */
#ifndef CONCRETE_BEVERAGE_H
#define CONCRETE_BEVERAGE_H
#include "beverage.h"

// 咖啡
class Coffe : public Beverage {
public:
    Coffe() : Beverage("Coffe") {}
    
    virtual double cost() const { return 1.99; }
};

// 低卡
class Decof : public Beverage {
public:
    Decof() : Beverage("Decof") {}

    virtual double cost() const { return 1.09; }
};

#endif
