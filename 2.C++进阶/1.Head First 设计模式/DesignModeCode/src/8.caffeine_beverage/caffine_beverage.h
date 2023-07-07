/*
 * @Author: Guomw
 * @Date: 2023-05-27 10:39:57
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-27 10:40:00
 * @Description: 咖啡因系饮料冲泡方法
 */
#ifndef CAFFINE_BEVERHABLE_H_
#define CAFFINE_BEVERHABLE_H_
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
        addCondiment();
    }

    void boilWater() {
        std::cout << "water is boilind...\n";
    }

    void pourInCup() {
        std::cout << "beverage is pour in cup...\n";
    }

    virtual void brew() = 0;
    virtual void addCondiment() = 0;
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
};

// tea
class Tea : public CaffineBeverage {
public:
    
    virtual void brew() {
        std::cout << "brew tea using water..." << std::endl;
    }

    virtual void addCondiment() {
        std::cout << "add lemon..." << std::endl;
    }
};


#endif
