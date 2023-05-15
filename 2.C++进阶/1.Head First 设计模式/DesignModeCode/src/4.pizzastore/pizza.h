/*
 * @Author: Guomw
 * @Date: 2023-05-13 16:48:03
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-14 15:36:35
 * @Description: pizza产品类
 */

#ifndef PIZZA_H_
#define PIZZA_H_
#include <iostream>
#include <string>
// Pizza接口
class Pizza {
public:
    // 使用默认的构造函数
    virtual ~Pizza() {}

    // interface
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

// cheese pizza
class CheesePizza : public Pizza {
private:
    std::string id;
public:
    CheesePizza() : id("CheesePizza") {}
    virtual ~CheesePizza() {}



    // 接口实现
    virtual void prepare() { std::cout << id << " is preparing...\n"; }
    virtual void bake() { std::cout << id << " is baking...\n"; }
    virtual void cut() { std::cout << id << " is cuttiny...\n"; }
    virtual void box() { std::cout << id << " is boxing...\n"; }
};

// greek pizza
class GreekPizza : public Pizza {
private:
    std::string id;
public:
    GreekPizza() : id("GreekPizza") {}
    virtual ~GreekPizza() {}

    // 接口实现
    virtual void prepare() { std::cout << id << " is preparing...\n"; }
    virtual void bake() { std::cout << id << " is baking...\n"; }
    virtual void cut() { std::cout << id << " is cuttiny...\n"; }
    virtual void box() { std::cout << id << " is boxing...\n"; }
};

#endif
