/*
 * @Author: Guomw
 * @Date: 2023-05-08 20:51:45
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-11 14:54:14
 * @Description: 测试装饰器模式
 */
// #include <iostream>
// #include "3.beverage/concrete_beverage.h"
// #include "3.beverage/condiment_decorator.h"

// int main() {
//     using std::cout;

//     // 创建一杯coffee
//     Beverage *b = new Coffe;

//     // 使用牛奶装饰
//     Beverage *b1 = new Milk(*b);

//     // cout << b->getDescription();
//     // cout << b->cost();
//     // 输出信息和价格
//     cout << b1->getDescription() << '\n';
//     cout << "Price: " << b1->cost() << '\n';

//     // 再加上抹茶修饰
//     Beverage *b2 = new Mocha(*b1);
//     cout << b2->getDescription() << '\n';
//     cout << "Price: " << b2->cost() << '\n';


//     delete b;
//     delete b1;
//     delete b2;

//     return 0;
// }