/*
 * @Author: Guomw
 * @Date: 2023-05-18 11:11:14
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-18 11:29:05
 * @Description: 命令对象
 */
#ifndef COMMAND_H_
#define COMMAND_H_ 
#include "receiver.h"

// 命令对象接口
class Command {
public:
    Command() {}
    virtual ~Command() {}

    // interface
    virtual void execute() = 0;
};

// 打开电灯的命令
class LightOn_Command : public Command {
private:
    Light &light;
public:
    LightOn_Command(Light &l) : light(l) {}
    ~LightOn_Command() {}

    // interface implement
    virtual void execute() { light.on(); }
};


#endif
