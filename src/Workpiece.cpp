#include "Workpiece.h"

//pro():返回目前正在加工该零件的机器编号
int Workpiece::beingPro()
{
    return this->_being_pro;
}
//lastTime():返回目前正在加工的零件在该机器上的剩余加工时间
int Workpiece::leftTime()
{
    return this->_left_time;
}
//nextTime():目前零件进入下一个时间状态，可能直接进入下一个加工状态，零件可能空闲
void Workpiece::nextTime()
{
    if (this->_left_time > 0)
    {
        this->_left_time--;
    }
}
//nextWorkpiece():目前零件进入下一台机器
void Workpiece::nextMachine(int time)
{
    this->_left_time = time;
    this->_being_pro++;
}
//reset():重置目前零件状态
void Workpiece::reset()
{
    this->_left_time = 0;
    this->_being_pro = -1;
}