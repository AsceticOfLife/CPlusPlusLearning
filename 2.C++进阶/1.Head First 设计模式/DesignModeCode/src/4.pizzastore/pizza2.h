/*
 * @Author: Guomw
 * @Date: 2023-05-14 15:33:32
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-14 16:30:10
 * @Description: pizza（需要原料）类
 */

#ifndef PIZZA2_H_
#define PIZZA2_H_
#include <iostream>
#include "pizza_ingredient_factory.h"

// 抽象类接口
class Pizza {
public:
    virtual ~Pizza() {};

    // 接口：需要子类实现
    virtual void prepare(PizzaIngredientFactory * factory) = 0; // 需要一个工厂提供原料
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

// 纽约cheese pizza
class NYCheesePizza : public Pizza {
public:
    virtual void prepare(PizzaIngredientFactory * factory) {
        using std::cout;
        // 准备原料
        Dough *d = factory->createDough();
        Sauce *s = factory->createSauce();

        // 展示说明使用了两种原料
        cout << d->show() << " is using by NY...\n";
        cout << s->show() << " is using by NY...\n";

        // 使用完原料对象进行删除
        delete d;
        delete s;
    }

    virtual void bake() { std::cout << "NYCheesePizza" << " is baking...\n"; }
    virtual void cut() { std::cout << "NYCheesePizza" << " is cuttiny...\n"; }
    virtual void box() { std::cout << "NYCheesePizza" << " is boxing...\n"; }    
};

// 纽约greek pizza
class NYGreekPizza : public Pizza {
public:
    virtual void prepare(PizzaIngredientFactory * factory) {
        using std::cout;
        // 准备原料
        Dough *d = factory->createDough();
        Sauce *s = factory->createSauce();

        // 展示说明使用了两种原料
        cout << d->show() << " is using by NY...\n";
        cout << s->show() << " is using by NY...\n";
        // 使用完原料对象进行删除
        delete d;
        delete s;
    }

    virtual void bake() { std::cout << "NYGreekPizza" << " is baking...\n"; }
    virtual void cut() { std::cout << "NYGreekPizza" << " is cuttiny...\n"; }
    virtual void box() { std::cout << "NYGreekPizza" << " is boxing...\n"; }  
};

// 芝加哥cheese pizza
class ChicagoCheesePizza : public Pizza {
public:
    virtual void prepare(PizzaIngredientFactory * factory) {
        using std::cout;
        // 准备原料
        Dough *d = factory->createDough();
        Sauce *s = factory->createSauce();

        // 展示说明使用了两种原料
        cout << d->show() << " is using by Chicago...\n";
        cout << s->show() << " is using by Chicago...\n";
        // 使用完原料对象进行删除
        delete d;
        delete s;
    }

    virtual void bake() { std::cout << "ChicagoCheesePizza" << " is baking...\n"; }
    virtual void cut() { std::cout << "ChicagoCheesePizza" << " is cuttiny...\n"; }
    virtual void box() { std::cout << "ChicagoCheesePizza" << " is boxing...\n"; }   
};

class ChicagoGreekPizza : public Pizza {
public:
    virtual void prepare(PizzaIngredientFactory * factory) {
        using std::cout;
        // 准备原料
        Dough *d = factory->createDough();
        Sauce *s = factory->createSauce();

        // 展示说明使用了两种原料
        cout << d->show() << " is using by Chicago...\n";
        cout << s->show() << " is using by Chicago...\n";
        // 使用完原料对象进行删除
        delete d;
        delete s;
    }

    virtual void bake() { std::cout << "ChicagoGreekPizza" << " is baking...\n"; }
    virtual void cut() { std::cout << "ChicagoGreekPizza" << " is cuttiny...\n"; }
    virtual void box() { std::cout << "ChicagoGreekPizza" << " is boxing...\n"; } 
};
#endif
