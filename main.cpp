#include "Simulate.h"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const double T0 = 1200;
const double theta = 0.99;

void SA(int n, int m, int *p)
{
    Simulate sa(n, m, p);
    sa.randomReset();
    int t = sa.evaluate();
    int new_t;
    int ans = 0x3f3f3f;
    int manage[WORKPIECEMAXNUM];
    double T = T0;
    while (T > 2)
    {
        // cout << "manage: ";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << manage[i] << " ";
        // }
        // printf("\tT:%-4.2f ans:%6d t:%6d\n", T, ans, t);
        for (int ring = 0; ring < 500; ring++)
        {
            printf("\tT:%-4.2f ans:%6d t:%6d\n", T, ans, t);
            if (t < ans)
            {
                ans = t;
                memcpy(manage, sa._manage[m - 1], sizeof(manage));
            }
            sa.randomChange();
            sa.resetNew();
            new_t = sa.evaluate();
            if (new_t < t)
            {
                t = new_t;
            }
            else
            {
                double p = exp((t - new_t) / T);
                double x = rand() % 10000 / 10000.0;
                if (x <= p)
                {
                    t = new_t;
                }
                else
                {
                    sa.rollBack();
                }
            }
        }
        T *= theta;
    }
    cout << "manage: ";
    for (int i = 0; i < n; i++)
    {
        cout << manage[i] << " ";
    }
    cout << "ans: " << ans << endl;
    sa.resetNew();
    sa.evaluate();
    sa.printAns();
}

int main(int argc, char const *argv[])
{
    int n, m;
    int other;
    int p[MACHINEMAXNUM * WORKPIECEMAXNUM];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> other >> p[i * m + j];
        }
    }
    SA(n, m, p);
    return 0;
}
