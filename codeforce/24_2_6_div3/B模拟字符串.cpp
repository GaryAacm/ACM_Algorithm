#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int vis[30];//字母出现的次数
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            int num=0;
            if(a[i]==0)
            {
                //找一个未出现的
                for(int j=1;j<=26;j++)
                {
                    if(!vis[j])
                    {
                        cout<<char(j+96);
                        vis[j]++;
                        break;
                    }
                }
            }
            else
            {
                for(int j=1;j<=26;j++)
                {
                    if(vis[j]==a[i])
                    {
                        cout<<char(j+96);
                        vis[j]++;
                        break;
                    }
                }
            }
        }
        cout<<'\n';
    }
}
