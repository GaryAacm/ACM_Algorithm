#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node
{
    int ddl,score;
}a[1001];
bool cmp(node x,node y)
{
    return x.ddl<y.ddl;
}//找到早结束的作业
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        priority_queue<int,vector<int>,greater<int> > Q;
        int ans=0;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].ddl;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].score;
            sum+=a[i].score;//表示要扣的分数
        }
        sort(a+1,a+1+n,cmp);
        //可反悔贪心
        for(int i=1;i<=n;i++)
        {
            if(a[i].ddl<=Q.size())
            {
                if(a[i].score>Q.top())
                {
                    ans-=Q.top();
                    Q.pop();
                    Q.push(a[i].score);
                    ans+=a[i].score;
                }
            }
            else
            {
                Q.push(a[i].score);
                ans+=a[i].score;
            }
        }
        cout<<sum-ans<<endl;
    }
    return 0;
}
