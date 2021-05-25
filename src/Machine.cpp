#include "Machine.h"

//pro():返回目前正在加工的零件编号
int Machine::pro()
{
    return this->_pro;
}
//lastTime():返回目前正在加工的零件的剩余加工时间
int Machine::leftTime()
{
    return this->_left_time;
}
//nextTime():目前机器进入下一个时间状态，可能直接进入下一个加工状态，机器可能空闲
void Machine::nextTime()
{
    if (this->_left_time > 0)
    {
        this->_left_time--;
    }
}
//nextWorkpiece():目前机器进入当前加工方案中的下一个零件
void Machine::nextWorkpiece(int time)
{
    this->_left_time = time;
    this->_pro++;
}
//reset():重置目前机器状态
void Machine::reset()
{
    this->_left_time = 0;
    this->_pro = -1;
}