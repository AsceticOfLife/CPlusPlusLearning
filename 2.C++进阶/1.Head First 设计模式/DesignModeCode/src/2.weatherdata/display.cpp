/*
 * @Author: Guomw
 * @Date: 2023-05-09 20:43:42
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-10 16:14:52
 * @Description: 展板实现定义
 */
#include "display.h"
#include "weatherdata.h"


// 接口定义
CurrentObserver::CurrentObserver(Subject *sub) : Observer(sub) { 
    subject->registerObserver(this);
};

CurrentObserver::~CurrentObserver() { 
    subject->removeObserver(this);
}

// 第一个展板
void CurrentObserver::update(double temperature, double humidity, double pressure) {
    this->temperature = temperature;
    this->humidity = humidity;
}

void CurrentObserver::display() {
    using std::cout;

    cout << "Current temperature: " << temperature << '\n';
    cout << "Current humidity: " << humidity << '\n';
}
