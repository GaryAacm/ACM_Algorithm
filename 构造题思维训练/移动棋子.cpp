#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
#define int long long
//˼·����ͨ���Աȷ��ֲ��ܵ�������������Ҫ��ǰ��ÿһ�ο�ʼ���е����ж�
//Ȼ����ǻص���һ��ԭ����������һ��ż��Ϊ<���ڶ�������λ<

int t,n;
string s1,s2;

void solve()
{
    cin>>n;
    cin>>s1>>s2;
    s1=" "+s1;
    s2=" "+s2;
    bool f=true;
    for(int i=2;i<=n;i+=2)
    {
        if(s1[i]=='<'&&((i+1<=n&&s2[i+1]=='<')||(s2[i-1]=='<')))
        {
            f=false;
            break;
        }
    }
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
