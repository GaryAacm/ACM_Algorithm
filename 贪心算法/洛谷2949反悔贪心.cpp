#include<bits/stdc++.h>
using namespace std;

struct node
{
    int time,val;
}a[100001];
bool cmp(node x,node y)
{
    return x.time<y.time;//先找到截止时间短的先做
}
int n;
long long ans;
priority_queue<int,vector<int>,greater<int> > Q;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].time>>a[i].val;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(a[i].time<=Q.size())//天数小于当前完成的任务数量，因为一天只做一个，便于反悔找其他的
        {
            if(a[i].val>Q.top())//找到价值更大的，反悔
            {
                ans-=Q.top();//不做这个任务
                Q.pop();
                ans+=a[i].val;
                Q.push(a[i].val);
            }
        }
        else//否则找到一个先做着
        {
            Q.push(a[i].val);
            ans+=a[i].val;
        }
    }
    cout<<ans<<endl;
    return 0;
}

