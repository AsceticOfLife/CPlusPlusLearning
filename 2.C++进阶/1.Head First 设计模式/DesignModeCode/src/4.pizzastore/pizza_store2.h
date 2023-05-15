/*
 * @Author: Guomw
 * @Date: 2023-05-14 15:24:02
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-14 16:22:50
 * @Description: 在创建pizza时使用原料工厂
 */
#ifndef PIZZA_STORE2_H_
#define PIZZA_STORE2_H_
#include <string>
#include "pizza2.h"

// 抽象商店类
class PizzaStore {
protected:
    virtual Pizza * createPizza(const std::string &type) = 0;
public:
    virtual ~PizzaStore() {}

    // method
    Pizza * orderPizza(const std::string &type) {
        // 创建披萨对象
        Pizza * pizza = createPizza(type);;

        // 准备工作由创建函数完成
        // 剩下的操作
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;  
    }
};


// 纽约店
class NYPizzaStore : public PizzaStore {
protected:
    virtual Pizza * createPizza(const std::string &type) {
        Pizza *pizza = nullptr;

        if (type == "cheese") {
            pizza = new NYCheesePizza();
        } else if (type == "greek") {
            pizza = new NYGreekPizza();
        } else {
            std::cerr << "Unknown type " << type << std::endl;
            exit(EXIT_FAILURE);
        }

        // 创建纽约配料工厂对象
        PizzaIngredientFactory * factory = new NYPizzaIngredientFactory;
        
        pizza->prepare(factory);

        return pizza;
    }
};


// 芝加哥店
class ChicagoPizzaStore : public PizzaStore {
protected:
    virtual Pizza * createPizza(const std::string &type) {
        Pizza *pizza = nullptr;

        if (type == "cheese") {
            pizza = new ChicagoCheesePizza();
        } else if (type == "greek") {
            pizza = new ChicagoGreekPizza();
        } else {
            std::cerr << "Unknown type " << type << std::endl;
            exit(EXIT_FAILURE);
        }

        // 创建纽约配料工厂对象
        PizzaIngredientFactory * factory = new ChicagoIngredientFactory;
        
        pizza->prepare(factory);

        return pizza;
    }
};


#endif
