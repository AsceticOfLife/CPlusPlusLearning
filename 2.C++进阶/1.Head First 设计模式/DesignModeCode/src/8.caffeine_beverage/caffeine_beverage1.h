/*
 * @Author: Guomw
 * @Date: 2023-05-27 15:03:36
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-27 15:09:49
 * @Description: 模板方法带有钩子
 */
#ifndef CAFFEINE_BEVERAGE_H_
#define CAFFEINE_BEVERAGE_H_

// 抽象基类
#include <iostream>

// 抽象基类
class CaffineBeverage {
public:
    virtual ~CaffineBeverage() {}

    // 模板算法
    void prepare() {
        boilWater();
        brew();
        pourInCup();

        // 默认添加配料
        if (addOrNot()) {
            addCondiment();
        }
    }

    void boilWater() {
        std::cout << "water is boilind...\n";
    }

    void pourInCup() {
        std::cout << "beverage is pour in cup...\n";
    }

    virtual void brew() = 0;
    virtual void addCondiment() = 0;

    // hook default complement
    virtual bool addOrNot() {
        return true;
    }
};

// coffee
class Coffee : public CaffineBeverage {
public:

    virtual void brew() {
        std::cout << "brew coffee using water..." << std::endl;
    }

    virtual void addCondiment() {
        std::cout << "add milk and sugar..." << std::endl;
    }

    // override hook
    virtual bool addOrNot() override {
        std::cout << "Do you want to add milk and sugar? (y or n)\n";
        char c;
        std::cin >> c;
        if (c == 'y') return true;
        return false;
    }
};



#endif
