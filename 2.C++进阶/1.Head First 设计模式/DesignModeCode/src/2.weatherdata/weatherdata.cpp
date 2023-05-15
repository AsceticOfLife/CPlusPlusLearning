/*
 * @Author: Guomw
 * @Date: 2023-05-09 20:59:31
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-10 16:23:00
 * @Description: 主题定义
 */

#include "weatherdata.h"


// 接口实现
Subject::~Subject() {
    
}

void Subject::registerObserver(Observer *o) {
    observers.push_back(o);
}

void Subject::removeObserver(Observer *o) {
    auto it = observers.begin();
    while ((*it) != o) it++;

    observers.erase(it);
}

void Subject::notifyObservers() {
    auto it = observers.begin();
    while (it != observers.end()) {
        (*it)->update(temprature, humidity, pressure);
        it++;
    }
}

void Subject::setData(double t, double h, double p) {
    temprature = t;
    humidity = h;
    pressure = p;
    // 改变数据调用change函数
    changeData();
}