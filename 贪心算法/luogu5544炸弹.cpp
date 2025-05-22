#include<bits/stdc++.h>
using namespace std;
#define eps 1e-10
#define xita 0.9972//ͬ��
const int N = 15, M = 1005;
double n, m, R, sumx, sumy, a[M], b[M], ans, ax, ay;
struct node{
    double x, y, r;
}s[N];

//�����
double dis(double x, double y, double xx, double yy){
    return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

double query(double x,double y)//�����
{
    double res=0,d=R;
    for(int i=1;i<=n;i++)
    {
        d=min(d,dis(x,y,s[i].x,s[i].y)-s[i].r);//��ը�������õ����뾶
    }
    for(int i=1;i<=m;i++)
    {
        if(dis(x,y,a[i],b[i])<=d) res++;//����ը��
    }
    return res;
}

void SA()
{
    //ģ���˻�
    double ansx=ax,ansy=ay;
    double temp=2655;
    while(temp>eps)
    {
        double xx=ansx+((rand()<<1)-RAND_MAX)*temp;
        double yy = ansy + ((rand() << 1) - RAND_MAX) * temp;
        double nowans = query(xx, yy);//��ǰ�Ĵ�
        double del = nowans - ans;//���ֵ
        if(del > 0){//������ţ��͸��´�
            ax = xx; ay = yy;
            ansx = xx; ansy = yy;
            ans = nowans;
        }else{
            if(exp(- del / temp) * RAND_MAX < rand()){//�������һ�����ʽ�������𰸣�����������ر�С��
                ansx = xx;
                ansy = yy;
            }
        }
        temp *= xita;//����
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
    srand(1e9+7);//�����
    scanf("%lf %lf %lf", &n ,&m, &R);
    for(int i = 1; i <= n; i ++){
        scanf("%lf %lf %lf", &s[i].x, &s[i].y, &s[i].r);
    }
    for(int i = 1; i <= m; i ++){
        scanf("%lf %lf", &a[i], &b[i]);
        sumx += a[i]; sumy += b[i];//���ܺ�
    }
    CZ();
    printf("%.0lf\n", ans);//�������Ҫ��Ϊ�������Ҷ����double������ֱ�ӱ���0λС���ͺ���
    return 0;
}

