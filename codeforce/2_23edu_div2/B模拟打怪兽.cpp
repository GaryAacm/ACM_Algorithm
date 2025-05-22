#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+10;


int t,n,k,tmp;
struct node
{
    int pos,cost;
}a[maxn];

bool cmp(node x,node y)
{
    if(x.pos!=y.pos) return x.pos<y.pos;
    return x.cost<y.cost;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].cost;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>tmp;
            a[i].pos=abs(tmp);
        }
        sort(a+1,a+1+n,cmp);
        int cnt=0;//计算靠近的步数
        bool f=true;
        for(int i=1;i<=n;)
        {
            tmp=k;
            if(i==n)
            {

            }
            while(tmp>a[i].cost)
            {
                tmp-=a[i].cost;
                i++;
                if(i==n+1) break;
            }
            //cout<<tmp<<' '<<i<<endl;
            //cout<<i<<endl;

            if(a[i].cost>=tmp) a[i].cost-=tmp;
            if(a[i].cost==0&&i+1<=n) i++;
            cnt++;
            if(a[i].pos-cnt<=0&&a[i].cost>0)
            {
                f=false;
                cout<<"NO"<<'\n';
                break;
            }

        }
        if(f) cout<<"YES"<<'\n';
    }
}
