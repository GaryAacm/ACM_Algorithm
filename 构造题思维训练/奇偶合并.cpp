#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
//����ֻ���������������ż�����ֲ��ܺϲ��������������ѭ������ÿ�ε���ż�ϲ�ȡ���ֵ
int t,n,a[maxn];

signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int odd=-1e9,even=-1e9,maxn=-1e9;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxn=max(a[i],maxn);
            if(a[i]<=0)
            {
                continue;
            }
            if(i&1)
            {
                a[i]=max(odd+a[i],a[i]);
                odd=max(a[i],odd);
            }
            else
            {
                a[i]=max(even+a[i],a[i]);
                even=max(even,a[i]);
            }
            maxn=max(maxn,a[i]);

        }
        cout<<maxn<<endl;

    }
    return 0;
}
