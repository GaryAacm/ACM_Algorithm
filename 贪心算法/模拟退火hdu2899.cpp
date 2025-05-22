//模拟退火一般用于范围内求最值的问题

#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
double y;
double func(double x)
{
    return 6*pow(x,7.0)+8*pow(x,6.0)+7*pow(x,3.0)+5*pow(x,2.0)-y*x;

}

double solve()
{
    double T=100,detla=0.98;//初始温度和降温系数
    double x=50.0;
    double now=func(x);//返回初始函数值
    double ans=now;
    while(T>eps)
    {
        int f[2]={1,-1};
        double newx=x+f[rand()%2]*T;
        //按照概率改变
        if(newx>=0&&newx<=100)
        {
            double next=func(newx);
            ans=min(ans,next);
            if(now-next>eps) { x=newx;now=next;}//更新x,相当于降温,哪怕只是一点点
        }
        T*=detla;
    }
    return ans;
}


int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%lf",&y);
        printf("%.4f\n",solve());
    }
    return 0;
}
