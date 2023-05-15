/*
 * @Author: Guomw
 * @Date: 2023-05-14 11:23:11
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-14 15:37:26
 * @Description: 使用工厂方法模式
 */
#ifndef PIZZA_STORE_H_
#define PIZZA_STORE_H_
#include <string>
#include "pizza1.h"


// 抽象商店类
class PizzaStore {
public:
    virtual ~PizzaStore() {}

    // method
    Pizza *orderPizza(const std::string &type) {
        Pizza *pizza = nullptr;

        // 创建pizza
        pizza = createPizza(type);

        // 开始做pizza
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;        
    };
protected:
    // 不允许外部调用，只在继承体系中
    // interface
    // 由子类不同的工厂实现
    virtual Pizza *createPizza(const std::string &type) = 0;
};


// 纽约披萨商店
class NYPizzaStore : public PizzaStore {
protected:
    virtual Pizza *createPizza(const std::string &type) {
        Pizza *pizza;

        // 根据类型创建不同的pizza
        if (type == "cheese") {
            pizza = new NYCheesePizza();
        } else if (type == "greek") {
            pizza = new NYGreekPizza();
        } else {
            std::cerr << "Unknown type " << type << std::endl;
            exit(EXIT_FAILURE);
        }

        return pizza;      
    }
};


// 芝加哥披萨商店
class ChicagoPizzaStore : public PizzaStore {
protected:
    virtual Pizza *createPizza(const std::string &type) {
        Pizza *pizza;

        // 根据类型创建不同的pizza
        if (type == "cheese") {
            pizza = new ChicagoCheesePizza();
        } else if (type == "greek") {
            pizza = new ChicagoGreekPizza();
        } else {
            std::cerr << "Unknown type " << type << std::endl;
            exit(EXIT_FAILURE);
        }

        return pizza;      
    }
};

#endif
