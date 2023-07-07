/*
 * @Author: Guomw
 * @Date: 2023-05-31 16:16:57
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-31 17:03:48
 * @Description: 菜单接口定义和实现
 */
#ifndef MENU_H_
#define MENU_H_
#include "menu_item.h"
#include "iterator.h"

// 菜单接口
class Menu {
public:
    virtual ~Menu() {}

    // interface
    virtual Iterator * CreateIterator() = 0;    
};

// 使用数组作为容器的菜单
class DinnerMenu : public Menu {
private:
    enum {MenuSize = 10 };
    MenuItem menu[MenuSize];
    int cur_size;
public:
    DinnerMenu(int size = 3) : cur_size(size) {
        menu[0] = MenuItem("K&B's Pancake Breakfast",
            "Pancakes with scrambled eggs, and toast", 2.99);
        menu[1] = MenuItem("Regular Pnacake Breakfast",
            "Pancakes with fried eggd, sausage", 2.99);
        menu[2] = MenuItem("Blueberry Pnacakes",
            "Pancakes made with fresh blueberry", 3.29);
    }

    int getSize() const { return cur_size; }

    virtual Iterator * CreateIterator() {
        return new DinnerIterator(menu, getSize());
    }
};

#endif
