#pragma once

class Machine
{
private:
    int _pro;       //_pro:表示目前正在加工当前方案中的第几个零件
    int _left_time; //_left_time:表示当前零件的剩余加工时间

public:
    Machine() //Machine():初始化定义
    {
        this->_pro = -1;
        this->_left_time = 0;
    }
    int pro();                    //pro():返回目前正在加工的零件编号
    int leftTime();               //leftTime():返回目前正在加工的零件的剩余加工时间
    void nextWorkpiece(int time); //nextWorkpiece():目前机器进入当前加工方案中的下一个零件
    void nextTime();              //nextTime():目前机器进入下一个时间状态，
                                  //可能直接进入下一个加工状态，可能空闲
    void reset();                 //reset():重置目前机器状态
};