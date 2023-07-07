/*
 * @Author: Guomw
 * @Date: 2023-05-18 11:22:24
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-05-18 11:26:22
 * @Description: 遥控器类（命令调用者）
 */
#ifndef REMOTE_H_
#define REMOTE_H_
#include "command.h"

class Remote {
private:
    Command *slot; // 命令对象
public:
    Remote() {}
    ~Remote() {}

    // method
    void setSlot(Command *cmd) { slot = cmd; }
    // 调用命令
    void pressButton() { slot->execute(); }
};


#endif
