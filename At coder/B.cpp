#include<bits/stdc++.h>
using namespace std;

int n,sum=0;
int pan[3];
int a;

bool isneed(int x,int y)
{
    int num=0;
    while(x)
    {
        pan[num++]=x%10;
        x/=10;
    }
    if(pan[0]!=pan[1]) return false;
    else
    {
        if(pan[0]==y)
            return true;
    }

    return false;
}

int main()
{
    //freopen("D:\\算法进阶\\At coder\\in.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)//月份数
    {
        cin>>a;//天数
        if(i>10)//排除两位数
        {
            int flag=1;
            int ssa=i;
            int ssb=i%10;
            while(ssa)
            {
                int ssk=ssa%10;
                ssa=ssa/10;
                if(ssk!=ssb)
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0) continue;

        }
        int tot=a;
        int k=i%10;//首数字

        for(int j=1;j<=tot;j++)
        {
            if(j<10)
            {
                if(j==k)
                {
                    sum++;
                    //cout<<j<<endl;
                }
            }
            else if(j==10) continue;
            else if(j<100)
            {
                if(isneed(j,k))
                {
                    sum++;
                    //cout<<j<<endl;
                }
            }
            else
                continue;
        }

    }

    cout<<sum<<endl;

    return 0;

}
