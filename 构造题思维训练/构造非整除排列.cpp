#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;

int t,n,a[maxn];
//��֤�������ʣ�һ��һС�������
signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int flag=0,l=1,now=0,r=n;
        for(int i=1;i<=n;i++)
        {
            if(!flag) a[++now]=l++;
            else a[++now]=r--;
            flag^=1;
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<' ';
        cout<<'\n';
    }
    return 0;
}

