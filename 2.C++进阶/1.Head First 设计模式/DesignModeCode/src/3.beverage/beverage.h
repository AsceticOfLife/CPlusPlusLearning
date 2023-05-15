/*
 * @Author: Guomw
 * @Date: 2023-05-11 11:34:11
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-11 14:52:49
 * @Description: 基础接口
 */

#ifndef BEVERAGE_H_
#define BEVERAGE_H_
#include <string>

class Beverage {
private:
    std::string info;
public:
    Beverage(const std::string &s) : info(s) {}
    virtual ~Beverage() {}

    // 接口
    virtual std::string getDescription() const { return info; }
    virtual double cost() const = 0;
};



#endif
