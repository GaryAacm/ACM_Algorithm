#include<bits/stdc++.h>
using namespace std;

const int maxn=1000010;

bool dp[maxn]={1};//表示前i个可以作为最大前缀
int n=0,ans=0;
string s[201],ss=" ";//初始化第一个为空格用于占位

bool Check(int p)
{
    for(int i=0;i<n;i++)//遍历全部数组元素
    {
        int t=s[i].size();
        if(p>=t&&dp[p-t]&&s[i] ==ss.substr(p-t+1,t))//比对上并且前面p-t也匹配上，可以连接起来
        {
            ans=p;
            return true;
        }
    }

    return false;
}

int main()
{
    //freopen("D:\\算法进阶\\字符串\\KMP\\in.txt","r",stdin);
    for(string sa;cin>>sa,sa!=".";s[n++]=sa);
    for(string sa;cin>>sa;ss+=sa);
    for(int i=1;i<=ss.size();i++)
        dp[i]=Check(i);
    printf("%d\n",ans);
    //cout<<n<<endl;

    return 0;
}
