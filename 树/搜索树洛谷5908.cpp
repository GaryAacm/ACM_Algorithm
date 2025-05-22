#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
vector<int> v[maxn];
int n,d;
int ans=0;
bool vis[maxn];//ËÑË÷×¢Òâ±ÜÃâÖØ¸´

void dfs(int x,int dis)
{
    vis[x]=1;
    if(dis>=d) return ;
    for(int i=0;i<v[x].size();++i)
    {

        int to=v[x][i];
        if(!vis[to])
        {
            ans++;
            dfs(to,dis+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("D:\\Ëã·¨½ø½×\\Ê÷\\in.txt","r",stdin);
	cin>>n>>d;
	int u,vv;
	for(int i=1;i<n;++i)
    {
        cin>>u>>vv;
        v[u].push_back(vv);
        v[vv].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<endl;

    return 0;
}
