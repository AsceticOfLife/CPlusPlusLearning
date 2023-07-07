/*
 * @Author: Guomw
 * @Date: 2023-06-19 11:25:52
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-06-26 16:02:20
 * @Description: 糖果机类定义
 */
#ifndef GUMBALL_MACHINE_H_
#define GUMBALL_MACHINE_H_
#include "state.h"

// 糖果机类定义
class GumballMachine {
private:
    State *no_quarter;
    State *has_quarter;
    State *sold;
    State *sold_out;

    State *cur_state;
    int count;

public:
    GumballMachine(int num) : count(num) {
        // 创建状态对象
        no_quarter = new NoQuarter(*this);
        has_quarter = new HasQuarter(*this);
        sold = new Sold(*this);
        sold_out = new SoldOut(*this);

        // 初始化状态
        if (num > 0) cur_state = no_quarter;
        else cur_state = sold_out;
    }

    GumballMachine(const GumballMachine &other) = delete;

    ~GumballMachine() {
        delete has_quarter;
        delete no_quarter;
        delete sold;
        delete sold_out;
    }

    // 状态变换
    void insertQuarter() { cur_state->insertQuarter(); }
    void ejectQuarter() { cur_state-> ejectQuarter(); }
    void turnCrank() { 
        cur_state->turnCrank();
        cur_state->dispense();
    }
    
    // setter
    void setState(State *state) { cur_state = state; }

    // getter
    State *getNoQuarte() { return no_quarter; }
    State *getHasQuarter() { return has_quarter; }
    State *getSold() { return sold; }
    State *getSoldOut() { return sold_out; }
    State *getCurState() { return cur_state; }
    int getNum() { return count; }

    // 糖果减一
    void releaseOne() { count -= 1; }

    // 添加糖果
    void addCandy(int n) { count += n; }
};

#endif
