#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int n;
ll temp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    ll sum=0;
    ll minn=-1e9-1;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        //bool flag=false;
        sum+=temp;
        if(sum<0)
        {
            minn=max(minn,-sum);
            flag=true;
        }
    }
    if(flag) cout<<minn+sum<<endl;
    else cout<<sum;
}
