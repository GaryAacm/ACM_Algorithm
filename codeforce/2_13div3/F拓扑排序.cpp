#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n,k;
vector<int> s[maxn];
int in[maxn];
int a,b,temp,aa;
int vis[maxn];
queue<int> Q;
bool  tuopu()
{
    while(!Q.empty()) Q.pop();
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            Q.push(i);
        }
    }
    int sum=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        sum++;
        for(int i=0;i<s[u].size();i++)
        {
            int v=s[u][i];
            in[v]--;
            if(!in[v]) Q.push(v);
        }
    }
    return sum==n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<=n;++i) s[i].clear();
        if(n==1)
        {
            cin>>a;
            cout<<"Yes"<<'\n';
            continue;
        }
        if(n==2)
        {
            if(k==1) cin>>a>>aa;
            else
            {
                for(int i=1;i<=2;i++)
                    cin>>a>>aa;
            }
            cout<<"Yes"<<'\n';
            continue;
        }
        memset(in,0,sizeof(in));
        for(int i=1;i<=k;i++)
        {
            cin>>aa;
            cin>>a;
            temp=a;
            for(int j=3;j<=n;j++)
            {
                cin>>b;
                s[temp].push_back(b);
                in[b]++;
                temp=b;
            }

        }
        if(tuopu()) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';

    }
}
