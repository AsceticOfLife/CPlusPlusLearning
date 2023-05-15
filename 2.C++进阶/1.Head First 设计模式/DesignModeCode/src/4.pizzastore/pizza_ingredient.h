/*
 * @Author: Guomw
 * @Date: 2023-05-14 15:27:46
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-14 15:48:57
 * @Description: pizza原料类
 * 假设在准备pizza时需要两种原料面团dough和酱料sauce
 */

#ifndef PIZZA_INGRENT_H_
#define PIZZA_INGRENT_H_
#include <string>

// 第一种原料接口
class Dough {
public:
    virtual ~Dough() {}

    virtual std::string show() = 0;
};

// 薄面团
class ThinDough : public Dough {
public:
    virtual std::string show() { return std::string("thindough"); }
};

// 厚面团
class ThickDough : public Dough {
public:
    virtual std::string show() { return std::string("thickdough"); }
};

// 第二种原料接口
class Sauce {
public:
    virtual ~Sauce() {}

    virtual std::string show() = 0;
};

class TomatoSauce : public Sauce {
public:
    virtual std::string show() { return std::string("TomatoSauce"); }
};

class BruschettaSauce : public Sauce {
public:
    virtual std::string show() { return std::string("BruschettaSauce"); }
};



#endif
