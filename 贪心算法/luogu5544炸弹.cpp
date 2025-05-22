#include<bits/stdc++.h>
using namespace std;
#define eps 1e-10
#define xita 0.9972//同上
const int N = 15, M = 1005;
double n, m, R, sumx, sumy, a[M], b[M], ans, ax, ay;
struct node{
    double x, y, r;
}s[N];

//求距离
double dis(double x, double y, double xx, double yy){
    return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

double query(double x,double y)//计算答案
{
    double res=0,d=R;
    for(int i=1;i<=n;i++)
    {
        d=min(d,dis(x,y,s[i].x,s[i].y)-s[i].r);//求爆炸可以设置的最大半径
    }
    for(int i=1;i<=m;i++)
    {
        if(dis(x,y,a[i],b[i])<=d) res++;//可以炸到
    }
    return res;
}

void SA()
{
    //模拟退火
    double ansx=ax,ansy=ay;
    double temp=2655;
    while(temp>eps)
    {
        double xx=ansx+((rand()<<1)-RAND_MAX)*temp;
        double yy = ansy + ((rand() << 1) - RAND_MAX) * temp;
        double nowans = query(xx, yy);//当前的答案
        double del = nowans - ans;//求差值
        if(del > 0){//如果更优，就更新答案
            ax = xx; ay = yy;
            ansx = xx; ansy = yy;
            ans = nowans;
        }else{
            if(exp(- del / temp) * RAND_MAX < rand()){//否则就以一个概率接受这个答案，（这个概率特别小）
                ansx = xx;
                ansy = yy;
            }
        }
        temp *= xita;//降温
    }
}

void CZ()
{
    ax=sumx/m;ay=sumy/m;
    for(int i=1;i<=9;i++)
    {
        SA();
    }
}

int main()
{
    srand(1e9+7);//随机数
    scanf("%lf %lf %lf", &n ,&m, &R);
    for(int i = 1; i <= n; i ++){
        scanf("%lf %lf %lf", &s[i].x, &s[i].y, &s[i].r);
    }
    for(int i = 1; i <= m; i ++){
        scanf("%lf %lf", &a[i], &b[i]);
        sumx += a[i]; sumy += b[i];//求总和
    }
    CZ();
    printf("%.0lf\n", ans);//输出，答案要求为整数，我定义的double，所以直接保留0位小数就好了
    return 0;
}

