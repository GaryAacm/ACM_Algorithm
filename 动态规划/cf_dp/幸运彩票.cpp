#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;

//字符串有共同点算贡献，共同点预处理，枚举新分出来的多长
//map枚举彩票前面的长度，以及后面需要的，前后都做一遍
string s[maxn];
map<pair<int,int>,int>mapp;
int n;
signed main()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        int len=s[i].size();
        sum=0;
        for(int j=0;j<len;j++)
        {
            sum+=s[i][j]-'0';
        }
        mapp[{len,sum}]++;//记录对应的长度与和出现的次数
    }

    //枚举前缀和后缀进行求和
    int ans=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        int len=s[i].size();
        int all=0;
        for(int j=0;j<len;j++)
        {
            all+=s[i][j]-'0';
        }

        sum=0,sum2=0;
        int tmp=0;//记录当前的长度
        for(int j=0;j<len;j++)
        {
            tmp++;
            sum+=s[i][j]-'0';
            sum2+=s[i][len-1-j]-'0';
            ans+=mapp[{2*tmp-len,2*sum-all}];
            if(!(j==len-1))//跑到原长的时候，只加一次贡献
                ans+=mapp[{2*tmp-len,2*sum2-all}];
        }
    }
    cout<<ans<<endl;

}

