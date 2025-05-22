#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
char s[maxn];
int sa[maxn],rk[maxn],tmp[maxn+1];
int n,k;

bool comp_sa(int i,int j)//判断组合数大小
{
    if(rk[i]!=rk[j])
    {
        return rk[i]<rk[j];
    }
    else
    {
        int ri=i+k<=n?rk[i+k]:-1;//高位相等后比较i+k和j+k
        int rj=j+k<=n?rk[j+k]:-1;
        return ri<rj;
    }
}

void calc_sa()//计算后缀数组
{
    for(int i=0;i<=n;i++)
    {
        rk[i]=s[i];//赋予初值
        sa[i]=i;//后缀数组赋值
    }

    for(k=1;k<=n;k=k*2)//两倍倍增进行，k来决定后面比较几位
    {
        sort(sa,sa+n,comp_sa);//用sa记录排序结果在sa数组里面
        tmp[sa[0]]=0;
        for(int i=0;i<n;i++)//sa倒推组合数排名，存在tmp里面赋值给rk
            {
                tmp[sa[i+1]]=tmp[sa[i]]+(comp_sa(sa[i],sa[i+1])?1:0);

            }
        for(int i=0;i<n;i++)
        {
            rk[i]=tmp[i];
        }
    }
}

int main()
{
    while(scanf("%s",s)!=EOF)
    {
        n=strlen(s);
        calc_sa();
        for(int i=0;i<n;i++)
            cout<<sa[i]<<endl;
    }

    return 0;
}

