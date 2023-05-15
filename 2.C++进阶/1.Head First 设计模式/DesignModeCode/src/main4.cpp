/*
 * @Author: Guomw
 * @Date: 2023-05-13 17:13:54
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-15 11:28:26
 * @Description: 测试工厂模式
 */

// #include <iostream>
// // #include "4.pizzastore/pizza_store.h" // 1.测试简单工厂模式
// // #include "4.pizzastore/pizza_store1.h"  // 2.测试工厂方法模式
// #include "4.pizzastore/pizza_store2.h"


// int main() {
//     using std::cout;
// // 1.测试简单工厂模式    
//     // // 实例化一个pizza商店
//     // PizzaStore store;
//     // // 向商店订购一个pizza
//     // Pizza *p = store.orederPizza("cheese");

//     // delete p;


// // 2.测试工厂方法模式
//     // // 实例化一个纽约店和一个芝加哥店
//     // PizzaStore *store1 = new NYPizzaStore();
//     // PizzaStore *store2 = new ChicagoPizzaStore();

//     // // 向两个商店订购一个pizza
//     // Pizza *p1 = store1->orderPizza("cheese");
//     // Pizza *p2 = store2->orderPizza("greek");

    
//     // delete p1;
//     // delete p2;
//     // delete store1;
//     // delete store2;

// // 3.测试抽象工厂模式
//     // 创建一个纽约店和一个芝加哥店
//     PizzaStore * store1 = new NYPizzaStore();
//     PizzaStore * store2 = new ChicagoPizzaStore();

//     // 订购披萨
//     Pizza *p1 = store1->orderPizza("cheese");
//     Pizza *p2 = store2->orderPizza("greek");

//     // 删除对象
//     delete p1;
//     delete p2;
//     delete store1;
//     delete store2;    


//     return 0;
// }