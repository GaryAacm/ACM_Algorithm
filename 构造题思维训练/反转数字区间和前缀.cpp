#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e3+10;


int t,n;
int a[maxn];

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
            cin>>a[1];
            cout<<1<<'\n';
            continue;
        }

        int posmax=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==n&&i!=1) posmax=i;
            if(a[1]==n&&a[i]==n-1) posmax=i;
        }
        int k=posmax;
        int l;
        if(k!=n) k--;
        l=k;
        for(int i=k-1;i>=1;i--)
        {
            if(a[i]>a[1]) l--;//把大的数往前面放
            else break;
        }
        for(int i=k+1;i<=n;i++) cout<<a[i]<<' ';
        for(int i=k;i>=l;i--) cout<<a[i]<<' ';
        for(int i=1;i<l;i++) cout<<a[i]<<' ';
        cout<<'\n';
    }
}
