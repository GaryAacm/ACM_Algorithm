#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1e5+10;

int t,n;
int a[maxn];
pair<int,int> ans[maxn];
int tot=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2==0)
        {
            cout<<"No"<<'\n';
        }
        else
        {
            cout<<"Yes"<<'\n';
            int pos1,pos2;
            tot=0;
            for(int i=1,j=2*n;j>n;i++,j-=2)
            {
                ans[++tot]={i,j};
                pos1=i;

            }
            for(int i=pos1+1,j=2*n-1;i<=n;i++,j-=2)
            {
                ans[++tot]={i,j};
            }
            for(int i=1;i<=tot;i++)
            {
                cout<<ans[i].first<<' '<<ans[i].second<<'\n';
            }
        }
    }
}
