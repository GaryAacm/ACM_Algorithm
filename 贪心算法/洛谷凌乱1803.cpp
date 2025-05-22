#include<bits/stdc++.h>
using namespace std;
struct p
{
    int l,r;
}a[1000001];
int finish=0;
int  n,ans=0;
bool cmp(p a,p b)
{
    return a.r<b.r;//返回比赛早结束的
}
int main()
{

    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].l>>a[i].r;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;++i)
    {
        if(finish<=a[i].l)
        {
            ans++;
            finish=a[i].r;//设定截止时间为比较对象
        }
    }
    cout<<ans;
    return 0;
}
