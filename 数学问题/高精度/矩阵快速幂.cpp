#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 2000005;

struct matrix//定义结构体
{
    ll mat[6][6];

    init(){
        memset(mat,0,sizeof(mat));

    }
};

matrix mul(matrix a,matrix b)//定义矩阵乘法
{
    matrix c;
    c.init();
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            for(int k=0;k<6;k++)
            {
                c.mat[i][j]+=((a.mat[i][k]%mod)*(b.mat[k][j]%mod))%mod;
                c.mat[i][j]%=mod;
            }
        }
    }
}

matrix fast_pow(matrix a,int n)
{
    matrix b;
    b.init();
    for(int i=0;i<6;i++)
    {
        b.mat[i][i]=1;
    }

    while(n)
    {
        if(n&1)
        {
            b=mul(b,a);
        }

        a=mul(a,a);


        n>>=1;
    }
    return b;
}

