/*
 * @Author: Guomw
 * @Date: 2023-06-14 15:51:32
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-06-14 16:12:30
 * @Description: 为组合模式实现外部迭代器
 */
#include <typeinfo>
#include "component.h"
#include "iterator1.h"

// 组合迭代器
Component * CompositeIterator::next() {
    if (hasNext()) {
        Iterator *it  = st.top();
        Component *node = it->next();
        if (node != nullptr && typeid(Menu) == typeid(Node)) {
            // 只会把组合迭代器放进栈中
            // 叶子迭代器不会入栈
            st.push(node->createIterator());
        }
        return node;
    } else return nullptr;
}


