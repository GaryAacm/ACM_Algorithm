#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;

int t,n;
int a[maxn];
//�۲췢����С����һֱ��Ϊ�������֣���������ǰ������ͬ����
//��С���������ǹؼ�����Ϊȡ����������ai%a2һ��С��a2�������a1С����ȡ����Ҳ���С
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    sort(a+1,a+1+n);
    bool f = false;
    if(a[1]!=a[2]) f=true;
    else
    {
        for(int i=2;i<=n;i++)
        {
            if(a[i]%a[1]) f=true;
        }
    }

    puts(f ? "YES" : "NO");
}


signed main()
{
    cin>>t;
    while(t--)
    {
        solve();
    }
}
