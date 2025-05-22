#include<bits/stdc++.h>
using namespace std;
struct node
{
    int start,ended;
}a[1000001];
int l,r,n;
bool cmp(node x,node b)
{
    return x.start<b.start;
}

int main()
{
    cin>>l>>r;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].start>>a[i].ended;

    }
    sort(a+1,a+n+1,cmp);
    //找到区间端点最小的那个
    int ans=0;
    bool k=false;
    for(int i=1;i<=n;i++)//枚举每个区间
    {
        //找到区间左端点最小的
        //但是比l小
        int j=i,finall=-2e5;
        while(j<=n&&a[j].start<=l)
        {
            //更新此时的右端节点，并且是不断更新，在满足左端点条件的情况下找到右端最大的
            finall=max(finall,a[j].ended);
            j++;
        }
        //没有进入while
        if(finall<l)
        {
            ans=-1;
            break;
        }
        ans++;
        //找到一个区间
        //继续让此区间的结尾作为开头；
        if(finall>=r)
        {
            k=true;
            break;
        }
        l=finall;
        i=j-1;//更新i,减少无用的搜索
    }
    if(!k) cout<<-1<<endl;
    else
    {
        cout<<ans<<endl;
    }
    return 0;
}
