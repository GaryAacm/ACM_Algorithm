#include<bits/stdc++.h>//同洛谷凌乱的那道题
using namespace std;
int ans;
struct node
{
    int start,ended;
}a[1000001];
bool cmp(node x,node b)
{
    return x.ended<b.ended;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].start>>a[i].ended;
    sort(a+1,a+1+n,cmp);
    int finish=-1;//初始化小的
    for(int i=1;i<=n;i++)
    {
        if(finish<=a[i].ended)
        {
            ans++;
            finish=a[i].ended;
        }
    }
    cout<<ans;
    return 0;
}
