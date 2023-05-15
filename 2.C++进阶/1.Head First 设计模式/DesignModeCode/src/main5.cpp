/*
 * @Author: Guomw
 * @Date: 2023-05-15 11:27:58
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-15 14:52:39
 * @Description: 测试单件模式
 */

#include <iostream>
// #include "5.chocolate/chocolate.h"
#include "5.chocolate/chocolate1.h"

// // 初始化唯一对象
// Chocolate * Chocolate::uniqueInstance = nullptr;

// 初始化唯一对象
std::unique_ptr<Chocolate> Chocolate::uniqueInstance = std::unique_ptr<Chocolate>(nullptr);

int main() {
    using std::cout;
// 1.需要释放单例占用的空间 
    // Chocolate * p = Chocolate::getInstance();
    // p->info();
    // delete p->getInstance();
// 2.不需要手动释放单例占用的空间
    Chocolate * p = Chocolate::getInstance();
    p->info();

    return 0;
}