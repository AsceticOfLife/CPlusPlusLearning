/*
 * @Author: Guomw
 * @Date: 2023-05-11 11:45:14
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-11 11:56:43
 * @Description: 配料装饰器定义
 */

#ifndef CONDIMENT_DECORATOR_H_
#define CONDIMENT_DECORATOR_H_
#include "beverage.h"

// 牛奶
class Milk : public Beverage {
private:
    Beverage &b;
public:
    Milk(Beverage &beverage) : b(beverage), Beverage("Milk") {}

    // 重新定义getDescription函数
    std::string getDescription() const {
        return b.getDescription() + ", " + Beverage::getDescription();
    }
    // 定义接口
    virtual double cost() const {
        return b.cost() + 0.2;
    }
};

// 抹茶
class Mocha : public Beverage {
private:    
    Beverage &b;
public:
    Mocha(Beverage &b) : b(b), Beverage("Mocha") {}

    // 重新定义getDescrip
    std::string getDescription() const {
        return b.getDescription() + ", " + Beverage::getDescription();
    }
    virtual double cost() const {
        return b.cost() + 0.17;
    }

};


#endif
