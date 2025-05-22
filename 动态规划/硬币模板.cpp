#include<bits/stdc++.h>
using namespace std;

const int MONEY=251;
const int VALUE=5;//面值和最大金币数
int MIN[MONEY];//记录最小的金币数
int MIN_Path[MONEY];//记录最小的组合
int type[5]={1,5,10,15,25};
int s;
void solve()//解决问题
{

    for(int i=0;i<MONEY;i++)
        MIN[i]=INT_MAX;//初始化为最大
    MIN[0]=0;
    for(int i=0;i<VALUE;i++)
    {
        for(int j=type[i];j<MONEY;j++)
        {
            if(MIN[j]>MIN[j-type[i]]+1)
            {
                MIN_Path[j]=type[i];//记录路径所用的硬币
                MIN[j]=MIN[j-type[i]]+1;
            }
        }
    }
}

void print_ans(int *MIN,int s)
{
    while(s)
    {
        cout<<MIN_Path[s]<<' ';
        s-=MIN_Path[s];//递减处理s
    }
    cout<<endl;
}

int main()
{
    solve();//打表处理
    while(cin>>s)
    {
        cout<<MIN[s]<<endl;
        print_ans(MIN_Path,s);
    }
    return 0;
}
