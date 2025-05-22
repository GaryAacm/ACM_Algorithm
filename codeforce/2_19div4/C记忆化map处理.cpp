#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define int long long
const int maxn=2e5+10;

int t,n;
int arr[maxn];

void init()
{
    for(int i=1;i<=maxn;i++)
    {
        int tmp=i;
        int sum=0;
        while(tmp)
        {
            sum+=tmp%10;
            tmp/=10;
        }
        arr[i]=sum;
    }
    for(int i=1;i<=maxn;i++)
    {
        arr[i]+=arr[i-1];
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    init();//预处理在循环之外
    while(t--)
    {
        cin>>n;
        cout<<arr[n]<<endl;
    }
}
