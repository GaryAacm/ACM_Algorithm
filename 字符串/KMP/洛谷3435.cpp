#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;
ll n,ans,nxt[maxn];
char s[maxn];

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>(s+1);
	int j=0;
	for(int i=2;i<=n;++i)
    {
        while(j&&s[i]!=s[j+1]) j=nxt[j];
        if(s[i]==s[j+1])  ++j;
        nxt[i]=j;
    }//计算next数组
    for(int i=2;i<=n;i++)
    {
        j=i;
        while(nxt[j]) j=nxt[j];//找到最小匹配长度
        if(nxt[i]) nxt[i]=j;//用于记忆化，减少递归次数
        ans+=i-j;
    }
    cout<<ans<<endl;

    return 0;
}
