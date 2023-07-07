/*
 * @Author: Guomw
 * @Date: 2023-06-19 11:25:29
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-06-26 16:03:24
 * @Description: 状态类实现
 */
#include <iostream>
#include "state.h"
#include "gumballmachine.h"

// 没有25分钱状态
void NoQuarter::insertQuarter() {
    std::cout << "You inserted a quarter...\n";
    // 改变糖果机状态
    GumballMachine &m = getMachine();
    m.setState(m.getHasQuarter());
}

void NoQuarter::ejectQuarter() {
    std::cout << "You haven't inserted a quarter!\n";
}

void NoQuarter::turnCrank() {
    std::cout << "You turned, but there's no quarter!\n";
}

void NoQuarter::dispense() {
    std::cout << "You need to pay first!\n";
}


// 已经投入25分钱状态
void HasQuarter::insertQuarter() {
    std::cout << "You have inserted a quarter!\n";
}

void HasQuarter::ejectQuarter() {
    std::cout << "Ejecting a quarter!\n";
    GumballMachine &m = getMachine();
    m.setState(m.getNoQuarte());
}

void HasQuarter::turnCrank() {
    // 状态变换到卖出状态
    GumballMachine &m = getMachine();
    m.setState(m.getSold());
}

void HasQuarter::dispense() {
    std::cout << "You need to turn crank first!" << std::endl;
}


// 正在卖出状态
void Sold::insertQuarter() {
    std::cout << "Solding a candy, please wait...\n";
}

void Sold::ejectQuarter() {
    std::cout << "You have turned the crank! You can't eject quarter!\n";
}

void Sold::turnCrank() {
    std::cout << "You have turned the crank!, please wait!\n";
}

void Sold::dispense() {
    GumballMachine &m = getMachine();
    int num = m.getNum();
    if (num > 0) {
        std::cout << "One candy is already for you!\n";
        m.releaseOne();
    } else {
        std::cout << "Sorry, there is no candy available!\n";
    }
}

// 售罄状态
void SoldOut::insertQuarter() {
    std::cout << "Candy is sold out!\n";
}

void SoldOut::ejectQuarter() {
    std::cout << "You haven't inserted anything!\n";
}

void SoldOut::turnCrank() {
    std::cout << "Candy is sold out!\n";
}

void SoldOut::dispense() {
    std::cout << "Candy is sold out!\n";
}


