/*
 * @Author: Guomw
 * @Date: 2023-05-15 11:30:29
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-15 11:45:03
 * @Description: 巧克力类
 */

#ifndef CHOCOLATE_H_
#define CHOCOLATE_H_
#include <iostream>

class Chocolate {
private:
    static Chocolate *uniqueInstance;

    // 私有构造函数
    Chocolate() {};
    
public:
    // 静态方法
    static Chocolate * getInstance() {
        if (uniqueInstance == nullptr) uniqueInstance = new Chocolate;

        return uniqueInstance;
    }

    // method
    void info() { std::cout << "I'm a chocolate\n"; }
};


#endif
