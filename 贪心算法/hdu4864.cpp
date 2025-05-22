#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct Task
{
    int time,val;
}task[maxn];

struct Machine
{
    int t,v;
}machine[maxn];

bool cmp1(Task a,Task b)
{
    if(a.time!=b.time)
        return a.time>b.time;
    return a.val>b.val;
}


bool cmp2(Machine x,Machine y)
{
    if(x.t!=y.t)
        return x.t>y.t;
    return x.v>y.v;
}

int n,m,cnt;
long long ans;
int vis[maxn];

//这里关键就是在满足时间要求的情况下优先考虑等级低但是可以完成任务的机器
int main()
{
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)//机器数量
           cin>>machine[i].t>>machine[i].v;
    for(int i=1;i<=m;i++)//任务数量
        cin>>task[i].time>>task[i].val;
    cnt=0;
    ans=0;
    sort(machine+1,machine+1+n,cmp2);
    sort(task+1,task+1+m,cmp1);
    memset(vis,0,sizeof(vis));
    int j=1;
    for(int i=1;i<=m;++i)//分配任务
    {

        while(j<=n&&machine[j].t>=task[i].time)//满足时间要求,而且因为排过序，前面的时间要大，后面的时间小，前面的时间可以满足后面的时间
        {
            vis[machine[j].v]++;
            j++;//统计满足时间数要求的机器的等级数量
        }
        for(int k=task[i].val;k<=100;k++)
        {
            if(vis[k])//有对应的低等级机器
            {
                cnt++;
                vis[k]--;//用掉一台
                ans+=500*task[i].time+2*task[i].val;
                break;
            }
        }
    }
    cout<<cnt<<' '<<ans<<endl;
    }

    return 0;
}
