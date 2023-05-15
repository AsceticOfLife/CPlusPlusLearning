/*
 * @Author: Guomw
 * @Date: 2023-05-13 16:49:21
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-14 15:33:12
 * @Description: pizza商店类
 */

#ifndef PIZZA_STORE_H_
#define PIZZA_STORE_H_
#include <string>
#include <cstdlib>
#include "pizza.h"
#include "sample_factory.h"


class PizzaStore {
public:
    // 使用默认的构造和析构函数

    // method
    Pizza * orderPizza(const std::string &type) {
        Pizza *pizza;

        // // 根据类型创建不同的pizza
        // if (type == "cheese") {
        //     pizza = new CheesePizza();
        // } else if (type == "greek") {
        //     pizza = new GreekPizza();
        // } else {
        //     std::cerr << "Unknown type " << type << std::endl;
        //     exit(EXIT_FAILURE);
        // }

        // 使用工厂创建pizza
        pizza = SampleFactory::createPizza(type);

        // 开始做pizza
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

};


#endif
