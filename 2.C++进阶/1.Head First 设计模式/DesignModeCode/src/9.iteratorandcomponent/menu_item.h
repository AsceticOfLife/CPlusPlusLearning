/*
 * @Author: Guomw
 * @Date: 2023-05-31 16:22:00
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-31 16:27:32
 * @Description: 菜单项类定义和实现
 */
#ifndef MENU_ITEM_H
#define MENU_ITEM_H
#include <string>

class MenuItem {
private:
    std::string name;
    std::string description;
    double price;
public:
    MenuItem(const std::string &n = "None", const std::string &d = "None", double p = 0.0)
        : name(n), description(d), price(p) {}
    
    // method
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    double getPrice() const { return price; }
};

#endif
