/*观察问题，就是每次都是后缀相同，然后枚举前缀就行，观察规律知道求得前缀的不同字母
的贡献就行*/
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
