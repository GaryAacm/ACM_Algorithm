#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,m;//任务数量和机器数量
struct node
{
    int time;
    int id;
}task[maxn];
int ans[maxn];
bool cmp(node x,node y)
{
    return x.time>y.time;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>task[i].time;
        task[i].id=i;
    }
    sort(task+1,task+1+n,cmp);
    //排序
    for(int i=1;i<=n;)//分配任务
    {
        for(int j=1;j<=m;j++)
        {
            if(i<=n)
            {
                ans[j]+=task[i++].time;
            }//分配机器
        }
        sort(ans+1,ans+1+m);//排序，找出时间最小的，之后就先加上时间长的任务
    }
    sort(ans+1,ans+1+m);
    cout<<ans[m]<<endl;//时间最长的输出
    return 0;
}
