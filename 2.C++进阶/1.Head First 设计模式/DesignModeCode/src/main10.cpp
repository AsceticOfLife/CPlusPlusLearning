/*
 * @Author: Guomw
 * @Date: 2023-06-19 11:23:16
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-06-26 10:50:11
 * @Description: 10.测试状态模式
 */

#include <iostream>
#include "10.gumballmachine/gumballmachine.h"

int main() {
    using std::cout;

    // 创建糖果机
    GumballMachine m(1);

    // 投进25分钱
    m.insertQuarter();

    // 转动曲柄
    m.turnCrank();

    // 查看还剩多少糖果
    cout << "There is " << m.getNum() << " candy left.\n";

    return 0;
}