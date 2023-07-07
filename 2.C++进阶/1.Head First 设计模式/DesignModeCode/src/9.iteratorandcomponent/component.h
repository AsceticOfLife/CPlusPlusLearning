/*
 * @Author: Guomw
 * @Date: 2023-06-12 09:36:23
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-06-14 15:50:46
 * @Description: 组合模式定义，分为组合接口，叶子节点和分支结点
 */
#ifndef COMPONENT_H_
#define COMPONENT_H_
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class Iterator;

// 定一个异常类
class UnsupportedOperationException : public std::logic_error {
public:
    UnsupportedOperationException(const std::string &msg = "Unsupport Operation")
        : std::logic_error(msg) {}
};


// 抽象接口
class Component {
public:
    // 省略默认构造函数
    virtual ~Component() {}

    // 定义默认方法，子类必须覆盖实现这些方法
    // 分支结点（菜单）需要覆盖的方法
    virtual void add(Component *menu_item) {
        throw UnsupportedOperationException();
    }

    virtual void remove(Component *menu_item) {
        throw UnsupportedOperationException();
    }

    virtual Component * get(int i) {
        throw UnsupportedOperationException();
    }

    // 叶子结点（菜单项）需要覆盖的方法
    virtual std::string getName() {
        throw UnsupportedOperationException();
    }

    virtual std::string getDescription() {
        throw UnsupportedOperationException();
    }

    virtual double getPrice() {
        throw UnsupportedOperationException();
    }

    virtual bool isVategetarian() {
        throw UnsupportedOperationException();
    }

    // 两种子类都需要实现的方法
    virtual void print() {
        throw UnsupportedOperationException();
    }

    virtual Iterator * createIterator();

}; // end class Component


// 叶子结点（菜单项）实现
class MenuItem : public Component {
private:
    std::string name;
    std::string description;
    double price;
    bool vagetarian;
public:
    MenuItem() {}
    MenuItem(const std::string &name, const std::string &description, double price, bool vagetarian)
        : name(name), description(description), price(price), vagetarian(vagetarian) {}
    virtual ~MenuItem() {}

    // 覆盖基类方法
    std::string getName() {
        return name;
    }

    std::string getDescription() {
        return description;
    }

    double getPrice() {
        return price;
    }

    bool isVategetarian() {
        return vagetarian;
    }

    // 两种子类都需要实现的方法
    void print() {
        using std::cout;
        cout << "  " << name;
        if (vagetarian) cout << "(V)";
        cout << ", " << price << '\n'
             << "      -- " << description << '\n';     
    }
}; // end of class MenuItem


// 分支节点（菜单）
class Menu : public Component {
private:
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<Component>> MenuItems;
public:
    Menu() {}
    Menu(const std::string &name, const std::string &description)
        : name(name), description(description) {}
    
    virtual ~Menu() {}

    // 覆盖实现基类方法
    void add(Component *menu_item) {
        // 将指针放进智能指针对象中
        std::shared_ptr<Component> temp(menu_item);
        MenuItems.push_back(temp);
    }

    void remove(Component *menu_item) {
        for (int i = 0; i < MenuItems.size(); ++i) {
            if (MenuItems[i].get() == menu_item)
                MenuItems.erase(MenuItems.begin() + i);
        }
    }

    Component * get(int i) {
        if (i < 0 || i > MenuItems.size() - 1) {
            std::cerr << ("Invalid Index: %d", i);
            return nullptr;
        }

        return MenuItems[i].get();
    }    

    // 打印菜单
    void print() {
        using std::cout;
        // 先打印菜单信息
        cout << "-----" << name << ", " << description << "-----\n";
        cout << "-------------------------------------------\n";

        // 打印每个菜单项
        auto it = MenuItems.begin();
        for (; it != MenuItems.end(); ++it) {
            (*it)->print();
        }
    }

    // 返回一个外部迭代器
    Iterator * createIterator();
}; // end of class Menu

#endif
