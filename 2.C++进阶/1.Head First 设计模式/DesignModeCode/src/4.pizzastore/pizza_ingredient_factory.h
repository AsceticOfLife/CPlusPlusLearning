/*
 * @Author: Guomw
 * @Date: 2023-05-14 15:26:29
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-14 16:06:34
 * @Description: pizza原料工厂
 */
#ifndef PIZZA_INREDIENT_FACTORY_H_
#define PIZZA_INREDIENT_FACTORY_H_
#include "pizza_ingredient.h"

// 原料工厂抽象接口
class PizzaIngredientFactory {
public:
    virtual ~PizzaIngredientFactory() {}

    // 创造原料接口
    virtual Dough * createDough() = 0;
    virtual Sauce * createSauce() = 0;
};

// 纽约原料制造厂
class NYPizzaIngredientFactory : public PizzaIngredientFactory {
public:
    virtual Dough * createDough() {
        // 使用厚面团
        return new ThickDough;
    }

    virtual Sauce * createSauce() {
        // 使用番茄酱
        return new TomatoSauce;
    }
};

// 芝加哥原料制造厂
class ChicagoIngredientFactory : public PizzaIngredientFactory {
public:
    virtual Dough * createDough() {
        return new ThinDough;
    }

    virtual Sauce * createSauce() {
        return new BruschettaSauce;
    }
};

#endif
