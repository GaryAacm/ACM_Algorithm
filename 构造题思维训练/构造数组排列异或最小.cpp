/*1˼�����1^0=1������k������kС������k�ĺ�С�ڵ�����k��������k��0�ָ����ߵ���*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,a[maxn],n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        int k=1;
        while(k<n)
        {
            k<<=1;
        }
        k>>=1;
        for(int i=n-1;i>=k;i--)
            a[++cnt]=i;
        for(int i=0;i<k;i++)
            a[++cnt]=i;
        for(int i=1;i<=cnt;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
    }
}

