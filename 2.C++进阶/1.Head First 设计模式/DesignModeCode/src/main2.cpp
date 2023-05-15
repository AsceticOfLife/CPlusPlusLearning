/*
 * @Author: Guomw
 * @Date: 2023-05-08 20:51:45
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-11 11:31:19
 * @Description: 测试观察者模式
 */
// #include <iostream>
// #include "2.weatherdata/display.h"
// #include "2.weatherdata/weatherdata.h"

// int main() {
//     using std::cout;

//     // 创建主题对象
//     WeatherData w;

//     // 创建一个展板
//     CurrentObserver d(&w);

//     // 改变天气状态会自动通知观察者
//     w.setData(25, 12, 9);

//     d.display();

//     return 0;
// }