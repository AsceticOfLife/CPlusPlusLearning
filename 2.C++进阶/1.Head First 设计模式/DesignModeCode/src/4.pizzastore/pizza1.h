/*
 * @Author: Guomw
 * @Date: 2023-05-14 11:40:06
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-14 15:09:49
 * @Description: 不同商店的pizza实现
 */

#ifndef PIZZA1_H_
#define PIZZA1_H_
#include "pizza.h"

// 纽约店cheese pizza
class NYCheesePizza : public CheesePizza {
public:
    // 使用默认的构造和析构函数

    // 接口实现
    virtual void prepare() { std::cout << "NYCheesePizza" << " is preparing...\n"; }
    virtual void bake() { std::cout << "NYCheesePizza" << " is baking...\n"; }
    virtual void cut() { std::cout << "NYCheesePizza" << " is cuttiny...\n"; }
    virtual void box() { std::cout << "NYCheesePizza" << " is boxing...\n"; }    
};

// 纽约店greek pizza
class NYGreekPizza : public GreekPizza {
public:
    virtual void prepare() { std::cout << "NYGreekPizza" << " is preparing...\n"; }
    virtual void bake() { std::cout << "NYGreekPizza" << " is baking...\n"; }
    virtual void cut() { std::cout << "NYGreekPizza" << " is cuttiny...\n"; }
    virtual void box() { std::cout << "NYGreekPizza" << " is boxing...\n"; }
};


// 芝加哥cheese pizza
class ChicagoCheesePizza : public CheesePizza {
public:
    // 使用默认的构造和析构函数

    // 接口实现
    virtual void prepare() { std::cout << "ChicagoCheesePizza" << " is preparing...\n"; }
    virtual void bake() { std::cout << "ChicagoCheesePizza" << " is baking...\n"; }
    virtual void cut() { std::cout << "ChicagoCheesePizza" << " is cuttiny...\n"; }
    virtual void box() { std::cout << "ChicagoCheesePizza" << " is boxing...\n"; }    
};

// 芝加哥greek pizza
class ChicagoGreekPizza : public GreekPizza {
public:
    virtual void prepare() { std::cout << "ChicagoGreekPizza" << " is preparing...\n"; }
    virtual void bake() { std::cout << "ChicagoGreekPizza" << " is baking...\n"; }
    virtual void cut() { std::cout << "ChicagoGreekPizza" << " is cuttiny...\n"; }
    virtual void box() { std::cout << "ChicagoGreekPizza" << " is boxing...\n"; }
};


#endif
