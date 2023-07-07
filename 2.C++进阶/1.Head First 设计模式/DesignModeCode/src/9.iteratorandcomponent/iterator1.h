/*
 * @Author: Guomw
 * @Date: 2023-06-14 15:26:43
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-06-14 16:12:20
 * @Description: 为组合模式定义外部迭代器
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_
#include <stack>

// 类原型声明
class Component;

// 迭代器接口
class Iterator {
public:
    virtual ~Iterator() {}

    // 接口
    virtual bool hasNext() = 0;
    virtual Component * next() = 0;
};

// 组合迭代器接口
class CompositeIterator : public Iterator {
private:
    std::stack<Iterator *> st;  // 保存组合迭代器
public:
    CompositeIterator(Iterator * iterator) {
        st.push(iterator);
    }

    // 接口声明
    Component * next();

    bool hasNext() {
        if (st.empty()) return false;
        else {
            Iterator *it = st.top();
            // 如果顶部迭代器没有元素，就弹出元素，递归调用hasNext查看栈的下一个迭代器
            if (!it->hasNext()) {
                st.pop();
                return hasNext();
            } else return true;
        }
    }
};

// 叶子迭代器定义
class NullIterator : public Iterator {
public:
    Component * next() { return nullptr; }
    bool hasNext() { return false; }
};


#endif
