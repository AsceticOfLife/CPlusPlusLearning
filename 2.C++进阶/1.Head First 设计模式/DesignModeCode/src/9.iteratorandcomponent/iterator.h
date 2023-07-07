/*
 * @Author: Guomw
 * @Date: 2023-05-31 16:19:32
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-31 17:01:45
 * @Description: 迭代器接口和实现
 */
#ifndef ITERATOR_H_
#define ITERATOR_H_
#include "menu_item.h"

// 接口
class Iterator {
public:
    virtual ~Iterator() {}

    // interface
    virtual bool hasNext() = 0;
    virtual MenuItem next() = 0;
};

// 针对使用数组作为容器的迭代器
class DinnerIterator : public Iterator {
private:
    MenuItem *items;
    int cur_pos;
    int length;    
public:
    DinnerIterator(MenuItem *it, int length)
        : items(it), cur_pos(0), length(length) {}
    
    // interface
    virtual bool hasNext() {
        return cur_pos < length;
    }

    virtual MenuItem next() {
        return items[cur_pos++];
    }
};




#endif
