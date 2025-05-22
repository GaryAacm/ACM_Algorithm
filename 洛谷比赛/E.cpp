#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll n,m,a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
   // freopen("D:\\算法进阶\\洛谷比赛\\in.txt","r",stdin);
    cin>>n>>m;
    while(n--)
    {
        ll maxnn=0;
        ll idx=1,cnt=0,ans=0;
        for(int i=1;i<=m;i++)
        {
            cin>>a[i];
            if(a[i]) cnt++;
            if(maxnn<a[i])
            {
                idx=i;
                maxnn=a[i];
                ans=cnt;
            }


        }
        cout<<idx<<' '<<ans-1<<endl;
    }

    return 0;
}
