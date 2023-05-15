/*
 * @Author: Guomw
 * @Date: 2023-05-15 14:40:00
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-15 14:46:35
 * @Description: 使用智能指针管理单例模式
 */
#ifndef CHOCOLATE_H_
#define CHOCOLATE_H_
#include <iostream>
#include <memory>

class Chocolate {
private:
    static std::unique_ptr<Chocolate> uniqueInstance;

    Chocolate() {}
public:
    static Chocolate * getInstance() {
        if (!uniqueInstance.get()) 
            uniqueInstance = std::unique_ptr<Chocolate>(new Chocolate());

        return uniqueInstance.get();
    }
    
    // method
    void info() { std::cout << "I'm a chocolate\n"; }
};

#endif // !CHOCOLATE_H_

