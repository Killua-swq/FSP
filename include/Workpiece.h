#pragma once

class Workpiece
{
private:
    int _being_pro; //_being_pro:表示目前正在加工的零件在第几个机器上加工
    int _left_time; //_left_time:表示当前零件的剩余加工时间

public:
    Workpiece() //Workpiece():初始化定义
    {
        this->_being_pro = -1;
        this->_left_time = 0;
    }
    int beingPro();             //beingPro():返回目前正在加工该零件的机器编号
    int leftTime();             //leftTime():返回目前正在加工的零件在该机器上的剩余加工时间
    void nextMachine(int time); //nextMachine():目前零件进入下一个机器
    void nextTime();            //nextTime():目前零件进入下一个时间状态，
                                //可能直接进入下一个加工状态，零件也可能空闲
    void reset();               //reset():重置目前零件状态
};