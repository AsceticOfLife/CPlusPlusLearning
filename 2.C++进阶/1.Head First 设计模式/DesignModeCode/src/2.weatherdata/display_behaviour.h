/*
 * @Author: Guomw
 * @Date: 2023-05-08 21:09:26
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-09 20:52:31
 * @Description: 展板的算法（行为）族接口和实现
 */
#ifndef DISPLAY_BEHAVIOUR_H_
#define DISPLAY_BEHAVIOUR_H_

class DisplayBehaviour {
public:
    // 构造和析构函数
    DisplayBehaviour() {}
    virtual ~DisplayBehaviour() {}
    // 删除不需要的成员函数
    DisplayBehaviour(const DisplayBehaviour &) = delete;
    DisplayBehaviour(const DisplayBehaviour &&) = delete;
    DisplayBehaviour & operator=(const DisplayBehaviour &) = delete;
    DisplayBehaviour & operator=(const DisplayBehaviour &&) = delete;

    // interface
    virtual void display() = 0;
};

#endif
