/*�۲����⣬����ÿ�ζ��Ǻ�׺��ͬ��Ȼ��ö��ǰ׺���У��۲����֪�����ǰ׺�Ĳ�ͬ��ĸ
�Ĺ��׾���*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
int t,n,dif,ans;
string s;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        memset(a,0,sizeof(a));
        dif=0;
        ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(a[s[i]-'a']==0)
            {
                dif++;
                a[s[i]-'a']=1;
            }
            ans+=dif;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
