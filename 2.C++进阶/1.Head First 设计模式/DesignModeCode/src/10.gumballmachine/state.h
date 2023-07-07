/*
 * @Author: Guomw
 * @Date: 2023-06-19 11:24:48
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-06-26 16:01:32
 * @Description: 状态类定义
 */
#ifndef STATE_H_
#define STATE_H_

class GumballMachine;

class State {
private:
    GumballMachine &machine;    // 保存糖果机的引用
protected:
    GumballMachine & getMachine() { return machine; }
public:
    State(GumballMachine &m) : machine(m) {}
    virtual ~State() {}

    // interface
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
};


// 没有25分钱状态
class NoQuarter : public State {
public:
    NoQuarter(GumballMachine &m) : State(m) {}

    virtual void insertQuarter();
    virtual void ejectQuarter();
    virtual void turnCrank();
    virtual void dispense();
};

// 投入25分钱状态
class HasQuarter : public State {
public:
    HasQuarter(GumballMachine &m) : State(m) {}

    virtual void insertQuarter();
    virtual void ejectQuarter();
    virtual void turnCrank();
    virtual void dispense();
};

// 出售状态
class Sold: public State {
public:
    Sold(GumballMachine &m) : State(m) {}

    virtual void insertQuarter();
    virtual void ejectQuarter();
    virtual void turnCrank();
    virtual void dispense();
};

// 售罄状态
class SoldOut : public State {
public:
    SoldOut(GumballMachine &m) : State(m) {}

    virtual void insertQuarter();
    virtual void ejectQuarter();
    virtual void turnCrank();
    virtual void dispense();
};

#endif
