#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
const int mod=1e9+7;
typedef long long ll;
ll n,ans,nxt[maxn],t;
char s[maxn];
ll num[maxn];//表示既是前缀又是后缀的子串个数(前后缀可以重叠)，后面靠j定位位置

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("D:\\算法进阶\\字符串\\KMP\\in.txt","r",stdin);
	cin>>t;
	while(t--)
    {
        cin>>(s+1);
        n=strlen(s+1);

        memset(nxt,0,sizeof(nxt));
        int j=0;
        num[1]=1;//一个字符也算前后缀，字符串本身也是前后缀
        for(int i=2;i<=n;++i)
        {
            while(j&&s[i]!=s[j+1]) j=nxt[j];
            if(s[i]==s[j+1])  ++j;
            //计算匹配上前缀和后缀个数


            num[i]=num[j]+1;//算上自己整个字符串的最大公共前缀和后缀的长度
        }//计算next数组

        /*for(int i=1;i<=n;i++)
            cout<<num[i]<<" "<<nxt[i]<<endl;*/

        ans=1;

        for(int i=2,j=0;i<=n;i++)
        {
            while(j&&s[i]!=s[j+1]) j=nxt[j];
            if(s[i]==s[j+1]) ++j;
            //计算匹配上前缀和后缀个数，同时继承上次的j不会超时
            //nxt[i]=j;//会T，后面循环

            while((j<<1)>i) j=nxt[j];

            ans=(ans*(long long)(num[j]+1))%mod;

            //不能像下面那样直接做
            //j=i;

            /*while(nxt[j]*2>i)
            {

                //cout<<"此时的i："<<i<<endl;
                //cout<<"此时的nxt[j]："<<nxt[j]<<endl;
                j=nxt[j];
                //cout<<"变化后的j："<<j<<endl;
                //cout<<"变化后的nxt[j]："<<nxt[j]<<endl;

            }
            //cout<<"最后的nxt[j]："<<nxt[j]<<endl;
            num[order++]=nxt[j];
            //cout<<num[j]<<endl;
            //ans=(ans*(j+1))%mod;
            //nxt[i]=j;*/
        }

        cout<<ans<<endl;

    }

    return 0;
}
