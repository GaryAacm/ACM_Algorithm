#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;

int t,n,a[maxn];
//�������в���ܹ��ﵽ��õ�Ч�������Խ����жϾ���
void solve()
{
    cin>>n;
    int last=-1e9,flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int u=a[i]/10,v=a[i]%10;
        if(u<=v&&u>=last&&v>=last)
        {
            last=v;//��
        }
        else if(a[i]>=last)
        {
            last=a[i];
        }
        else flag=1;
    }
    if(flag) cout<<"NO"<<'\n';
    else cout<<"YES"<<'\n';

    return ;

}

signed main()
{
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
