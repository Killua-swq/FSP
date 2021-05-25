#include "Simulate.h"
#include <iostream>
#include <algorithm>
using namespace std;

int Simulate::evaluate()
{
    int _start = 0;
    while (true)
    {
        //模拟机器
        for (int i = 0; i < this->_mCount; i++) //在第i台机器上时
        {

            int pro = this->_M[i].pro();  //pro:目前在第i台机器上加工的零件
            if (pro != this->_wCount - 1) //当目前加工零件不是最后一个零件时
            {
                int x = this->_manage[i][pro + 1]; //x:当前机器的加工顺序中的下一个零件
                if (this->_M[i].leftTime() == 0 &&
                    this->_W[x].leftTime() == 0 &&
                    this->_W[x].beingPro() == i - 1)
                //下一个零件x已被上一台机器加工完且目前处于空闲状态，目前机器已加工完上一个零件且机器处于空闲状态
                {
                    this->_W[x].nextMachine(this->_cost[x][i]);
                    //零件x进入当前机器
                    this->_M[i].nextWorkpiece(this->_cost[x][i]);
                    //当前机器加入零件x
                    this->_time[i][pro + 1] = _start;
                    //当前机器加工零件x的起始时间为_start;
                }
            }
        }
        //所有零件和机器进入下一状态
        for (int i = 0; i < this->_mCount; i++)
        {
            this->_M[i].nextTime();
        }
        for (int i = 0; i < this->_wCount; i++)
        {
            this->_W[i].nextTime();
        }
        //检验所有零件是否加工完成
        bool flag = false;
        for (int i = 0; i < this->_wCount; i++)
        {
            if (this->_W[i].leftTime() == 0 &&
                this->_W[i].beingPro() == this->_mCount - 1)
            //所有零件在机器上的剩余加工时间为零，且所有零件的上一加工机器为最后一台机器
            {
                continue;
            }
            else
            {
                flag = true; //还有零件在加工
                break;
            }
        }
        if (!flag)
        {
            _start++;
            break;
        }
        _start++;
    }
    return _start;
}

void Simulate::randomReset()
{
    //随机设置加工顺序
    srand((unsigned)time(NULL));
    for (int i = 0; i < this->_mCount; i++)
    {
        for (int j = 0; j < this->_wCount; j++)
        {
            int x = rand() % (this->_wCount - j) + j;
            swap(this->_manage[i][j], this->_manage[i][x]);
        }
    }
}

void Simulate::randomChange()
{
    //随机交换机器加工零件顺序
    x = rand() % this->_wCount;
    y = rand() % this->_wCount;
    z = rand() % this->_mCount;
    swap(this->_manage[z][x], this->_manage[z][y]);
}

void Simulate::rollBack()
{
    //回退到交换前的顺序
    swap(this->_manage[z][x], this->_manage[z][y]);
}

void Simulate::printAns(){
    //输出每台机器的加工顺序
    for(int i = 0;i < this->_mCount;i++){
        for (int j = 0; j < this->_wCount; j++)
        {
            cout << this->_manage[i][j] << " ";
        }
        cout << endl;
    }
    //输出每台机器加工零件的时间
    for (int i = 0; i < this->_mCount; i++)
    {
        for (int j = 0; j < this->_wCount; j++)
        {
            cout << this->_time[i][j] << " " << this->_time[i][j] + this->_cost[this->_manage[i][j]][i] << " ";
        }
        cout << endl;
    }
}

void Simulate::resetNew(){
    //所有零件和机器状态重置
        for (int i = 0; i < this->_mCount; i++)
        {
            this->_M[i].reset();
        }
        for (int i = 0; i < this->_wCount; i++)
        {
            this->_W[i].reset();
        }
}