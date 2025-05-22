#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n,a[1003][1003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cin>>a[0][0];
             cout<<"YES"<<'\n'<<0<<'\n';
            continue;
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=(1<<30)-1;//按位与初始化1111111111...111
            for(int j=0;j<n;j++)
                if(i!=j) ans[i]&=a[i][j];//求得最多的1,在限制条件下
        }
        bool flag=1;

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i!=j)
                flag&=(ans[i]|ans[j])==a[i][j];//判断是否合理
        }
        if(flag){
            cout<<"YES"<<'\n';
            for(int i=0;i<n;i++)cout<<ans[i]<<' ';
            cout<<'\n';
        }
        else cout<<"NO"<<'\n';
    }
}
