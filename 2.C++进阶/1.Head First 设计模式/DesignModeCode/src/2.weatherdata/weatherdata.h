/*
 * @Author: Guomw
 * @Date: 2023-05-08 21:08:59
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-10 16:07:37
 * @Description: 天气数据（主题）接口和实现
 */
#ifndef WETHWEADATA_H_
#define WETHWEADATA_H_
#include <vector>
#include "display.h"


// 主题接口定义
class Subject {
private:
    double temprature;
    double humidity;
    double pressure;
    std::vector<Observer *> observers;
public:
    // 使用默认的构造函数
    Subject() {}
    virtual ~Subject() = 0; // 为了表明这是一个接口

    // 删除不需要的函数
    // Subject(const Subject &); // 使用默认的复制构造函数
    Subject(const Subject &&) = delete;
    Subject & operator=(const Subject &) = delete;
    Subject & operator=(const Subject &&) = delete;

    // 接口
    void registerObserver(Observer *o);
    void removeObserver(Observer *o);
    void notifyObservers();
    void changeData() { notifyObservers(); }
    void setData(double t, double h, double p);
};

class WeatherData : public Subject {
public:
    // 使用默认的构造和析构函数

};







#endif
