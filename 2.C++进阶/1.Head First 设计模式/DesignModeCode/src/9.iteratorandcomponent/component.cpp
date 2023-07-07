/*
 * @Author: Guomw
 * @Date: 2023-06-14 15:46:46
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-06-14 16:12:35
 * @Description: 组合模式实现，分为组合接口，叶子节点和分支结点
 */
#include "component.h"
#include "iterator1.h"

// 基类
Iterator * Component::createIterator() {
    throw UnsupportedOperationException();
}

// 分支结点
Iterator * Menu::createIterator() {
    return new ComponentIterator()
}
