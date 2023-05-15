/*
 * @Author: Guomw
 * @Date: 2023-05-08 19:11:27
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-08 20:35:15
 * @Description: 算法族定义
 */
#ifndef BEHEAVIOUR_H_
#define BEHEAVIOUR_H_
#include <iostream>

// 抽象基类作为接口
class FlyBehaviour {
public:
    FlyBehaviour() {}
    virtual ~FlyBehaviour() {}

    FlyBehaviour(const FlyBehaviour &) = delete;
    FlyBehaviour(const FlyBehaviour &&) = delete;
    FlyBehaviour & operator=(const FlyBehaviour &) = delete;
    FlyBehaviour & operator=(const FlyBehaviour &&) = delete;

    // interface
    virtual void fly() = 0;
};


// 飞行方式1
class Fly1 : public FlyBehaviour {
public:
    virtual void fly();
};

// 飞行方式2
class Fly2 : public FlyBehaviour {
public:
    virtual void fly();
};

// 尝试添加一个新的飞行方式
class FlyRocket : public FlyBehaviour {
public:
    virtual void fly();
};

// class SpeakBehaviour {
// public:
//     SpeakBehaviour() {}
//     virtual ~SpeakBehaviour() {}

//     SpeakBehaviour(const SpeakBehaviour &) = delete;
//     SpeakBehaviour(const SpeakBehaviour &&) = delete;
//     SpeakBehaviour & operator=(const SpeakBehaviour &) = delete;
//     SpeakBehaviour & operator=(const SpeakBehaviour &&) = delete;

//     // interface
//     void Speak(std::ostream &os);
// };

#endif
