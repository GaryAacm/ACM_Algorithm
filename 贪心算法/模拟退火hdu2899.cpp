//ģ���˻�һ�����ڷ�Χ������ֵ������

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
    double T=100,detla=0.98;//��ʼ�¶Ⱥͽ���ϵ��
    double x=50.0;
    double now=func(x);//���س�ʼ����ֵ
    double ans=now;
    while(T>eps)
    {
        int f[2]={1,-1};
        double newx=x+f[rand()%2]*T;
        //���ո��ʸı�
        if(newx>=0&&newx<=100)
        {
            double next=func(newx);
            ans=min(ans,next);
            if(now-next>eps) { x=newx;now=next;}//����x,�൱�ڽ���,����ֻ��һ���
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
