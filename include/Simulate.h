#pragma once
#include "Machine.h"
#include "Workpiece.h"
#define MACHINEMAXNUM 50
#define WORKPIECEMAXNUM 50

class Simulate
{
public:
    int _cost[WORKPIECEMAXNUM][MACHINEMAXNUM];   //_cost:每个零件在各机器上的加工时间
    int _manage[MACHINEMAXNUM][WORKPIECEMAXNUM]; //_manage:每台机器的加工顺序
    int _time[MACHINEMAXNUM][WORKPIECEMAXNUM];   //_time:每台机器加工对应顺序零件的开始加工时间
    int _wCount, _mCount;                        //_wCounr,_mCount:工件数，机器数
    int x, y, z;                                 //x,y,z:记录交换编码
    Machine _M[MACHINEMAXNUM];                   //_M:机器列表
    Workpiece _W[WORKPIECEMAXNUM];               //_W:工件列表
public:
    Simulate(int n, int m, int *p) //初始化模拟
    {
        this->_wCount = n;
        this->_mCount = m;
        //初始化_cost加工时间花费表
        for (int i = 0; i < this->_wCount; i++)
        {
            for (int j = 0; j < this->_mCount; j++)
            {
                this->_cost[i][j] = p[i * this->_mCount + j];
            }
        }
        //初始化每台机器的加工顺序为"0,1,2……,n"
        for (int i = 0; i < this->_mCount; i++)
        {
            for (int j = 0; j < this->_wCount; j++)
            {
                this->_manage[i][j] = j;
                this->_time[i][j] = 0;
            }
        }
    };
    int evaluate();      //evaluate():时间评估函数
    void randomReset();  //randomReset():随机初始解
    void rollBack();     //rollBack():返回上一个状态(解)
    void randomChange(); //randomChange():随机产生新解
    void printAns();     //printAns():屏幕打印结果
    void resetNew();     //resetNew():重置所有状态
};