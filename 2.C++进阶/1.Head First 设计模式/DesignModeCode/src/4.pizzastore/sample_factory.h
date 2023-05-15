/*
 * @Author: Guomw
 * @Date: 2023-05-14 11:12:40
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-14 11:16:53
 * @Description: 简单工厂方法
 */

#ifndef SAMPLE_FACTORY_H
#define SAMPLE_FACTORY_H
#include <string>
#include "pizza.h"

class SampleFactory {
public:
    static Pizza *createPizza(const std::string &type) {
        Pizza *pizza = nullptr;

        // 根据类型创建不同的pizza
        if (type == "cheese") {
            pizza = new CheesePizza();
        } else if (type == "greek") {
            pizza = new GreekPizza();
        } else {
            std::cerr << "Unknown type " << type << std::endl;
            exit(EXIT_FAILURE);
        }   

        return pizza;     
    }
};

#endif
