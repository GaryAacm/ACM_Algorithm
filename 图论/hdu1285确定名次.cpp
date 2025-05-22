#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int in[maxn],out[maxn],n,m;
vector<int> v[maxn];

int x,y;

void solve()
{
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int> > Q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
            Q.push(i);
    }

    while(!Q.empty())
    {
        int u=Q.top();
        Q.pop();
        ans.push_back(u);
        for(int i=0;i<v[u].size();i++)
        {
            int k=v[u][i];
            in[k]--;
            if(in[k]==0)
                Q.push(k);
        }
    }
    for(int i = 0;i < n; ++i)
		cout<<ans[i]<<" \n";
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m)
    {
        for(int i=0;i<=n;i++)
        {
            v[i].clear();
            in[i]=0;
        }

        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
            in[y]++;
            out[x]++;
            v[x].push_back(y);

        }
        solve();
    }
    return 0;
}
