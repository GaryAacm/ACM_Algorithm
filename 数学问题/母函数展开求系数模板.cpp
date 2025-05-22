#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int c1[maxn+1],c2[maxn+1];//c1存储计算结果，c2存储临时结果
int n;
void part()
{
    int i,j,k;
    for(i=0;i<=maxn;i++)
        c1[i]=1,c2[i]=0;//初始化c1就是(1+x+x2+...)，就是第一项1用几次
    for(k=2;k<=maxn;k++) //从第二项开始，第二项数2用几次
    {
        for(i=0;i<=maxn;i++)
        {
            for(j=0;j+i<=maxn;j+=k)
            {
                c2[i+j]+=c1[i];//求项数,模拟展开求得的系数
            }
        }
        for(i=0;i<=maxn;i++)
            c1[i]=c2[i],c2[i]=0;//赋值
    }
}

