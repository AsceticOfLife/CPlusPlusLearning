/*
 * @Author: Guomw
 * @Date: 2023-05-31 17:04:00
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-06-13 14:33:50
 * @Description: 9.测试迭代器模式
 */

// #include <iostream>
// // 1.测试迭代器模式
// // #include "9.iteratorandcomponent/menu.h"

// // 2.测试组合模式
// #include "9.iteratorandcomponent/component.h"

// int main() {
//     using std::cout;
// // 1.测试迭代器模式
//     // // 创建默认菜单
//     // Menu *menu = new DinnerMenu;
//     // // 获取这个菜单的迭代器
//     // Iterator *p = menu->CreateIterator();

//     // // 利用迭代器遍历元素
//     // while (p->hasNext()) {
//     //     MenuItem item = p->next();
//     //     cout << item.getName() << '\n' 
//     //          << item.getDescription() << '\n'
//     //          << item.getPrice() << '\n';
//     // }


//     // delete menu;
//     // delete p;

// // 2.测试组合模式
//     // 生成所有菜单对象
//     Component *pancake_menu = new Menu("Pancake Menu", "Breakfast");
//     Component *diner_menu = new Menu("Diner Menu", "Launch");
//     Component *cafe_menu = new Menu("Cafe Menu", "Dinner");
//     Component *dessert_menu = new Menu("Dessert Menu", "Dessert of course!");

//     // 创建一个顶层菜单，包含所有菜单
//     Component *all_menu = new Menu("All Menus", "All menu combined");
//     all_menu->add(pancake_menu);
//     all_menu->add(diner_menu);
//     all_menu->add(cafe_menu);

//     // 为菜单添加菜单项
//     // 因为菜单项比较多，如果都需要手动管理释放的话比较麻烦
//     // 所以在菜单内部使用智能指针管理
//     // 只需创建，不用管理释放
//     // pancake
//     pancake_menu->add(new MenuItem("K&B's Pancake Breakfast",
//                                    "Pancakes with scrambled eggs, and totast",
//                                     2.99, true));
//     pancake_menu->add(new MenuItem("Regular Pancake Breakfast",
//                                    "Pancakes with fried eggs, sausage",
//                                    2.99, false));
//     pancake_menu->add(new MenuItem("BlueBerry Pancake",
//                                    "Pancakes made with fresh blueberry, and blueberry syrup",
//                                    3.49, true));
//     pancake_menu->add(new MenuItem("Waffles", "Waffles with your choice of blueberry or strawberry",
//                                    3.59, true));
    
//     // diner
//     diner_menu->add(new MenuItem("Vegetarian BLT",
//                                  "(Fakin')Bacon with lettuce & tomato on whole wheat",
//                                  2.99, true));
//     diner_menu->add(new MenuItem("BLT", "Bacon with lettuce & tomato on whole wheat",
//                                  2.99, false));
//     diner_menu->add(new MenuItem("Soup of the day",
//                                  "A bowl of the soup of the day, with a side of potato salad",
//                                  3.29, false));
//     diner_menu->add(new MenuItem("Hotdog",
//                                  "A hot dog, with saurkraut, relish, onions, topped with cheese",
//                                  3.05, false));
//     diner_menu->add(new MenuItem("Steamed Veggies and Brown Rice",
//                                  "Steamed Vegeables over brown rice",
//                                  3.99, true));
//     diner_menu->add(new MenuItem("Pasta",
//                                  "Spaghetti with Marinara Sauce, and a slice of sourdough bread",
//                                  3.89, true));
//     // dessert
//     dessert_menu->add(new MenuItem("Apple pie", 
//                                    "Apple pie with a flakey crust, topped with vanilla ice cream",
//                                    1.59, true));
//     dessert_menu->add(new MenuItem("Cheesecake",
//                                    "Creamy New York cheesecake, with a chocolate graham crust",
//                                    1.99, true));
//     dessert_menu->add(new MenuItem("Sorbet",
//                                    "A scoop of raspberry and a scoop of lime",
//                                    1.89, true));
//     // cafe
//     cafe_menu->add(new MenuItem("Veggie Burger and Air Fries",
//                                 "Veggie burger on a whole wheat bun, lettuce, tomato, and fries",
//                                 3.99, true));
//     cafe_menu->add(new MenuItem("Soup of the day",
//                                 "A cup of the soup of the day, with a side salad",
//                                 3.69, false));
//     cafe_menu->add(new MenuItem("Burrito",
//                                 "A large burrito, with whole pinto beans, salsa, guacamole",
//                                 4.29, true));
    
//     // 将dessert菜单加入diner菜单
//     // 这样就不同自动管理dessert菜单对象
//     diner_menu->add(dessert_menu);


//     // 调用总菜单的print方法
//     all_menu->print();

    
//     // 需要手动释放的菜单
//     delete all_menu;
//     delete pancake_menu;
//     delete diner_menu;
//     delete cafe_menu;


//     return 0;
// }