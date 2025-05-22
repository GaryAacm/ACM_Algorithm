#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int col[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\算法进阶\\codeforce\\12_16div2\\input.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        int ans=0;
        memset(col,0,sizeof(col));
        cin>>n;
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            col[u]++;
            col[v]++;

        }
        for(int i=1;i<=n;++i)
        {
            if(col[i]==1) ans++;
        }
        cout<<(ans+1)/2<<endl;
    }

    return 0;
}
