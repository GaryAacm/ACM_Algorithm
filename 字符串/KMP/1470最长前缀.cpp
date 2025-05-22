#include<bits/stdc++.h>
using namespace std;

const int maxn=1000010;

int Next[maxn],cnt;
string s[205] ,ss="";
//char ss[maxn];
int dp[maxn];
void getFail(string p,int plen)//得到next数组
{
    Next[0]=0;
    Next[1]=0;
    int j=0;
    for(int i=1;i<plen;i++)
    {
        j=Next[i];//继承前面的
        while(j&&p[i]!=p[j]) j=Next[j];
        Next[i+1]=(p[i]==p[j])?j+1:0;//能够连续相等就加一
    }
}


bool kmp(string s,string p)
{
    int last=-1;
    int slen=s.length(),plen=p.length();
    getFail(p,plen);
    int j=0;

    for(int i=0;i<slen;i++)//开始匹配
    {
        while(j&&p[j]!=s[i]) j=Next[j];//失配
        if(s[i]==p[j]) j++;//往后匹配
        if(j==plen)//匹配成功
        {
            //printf("%d\n",i+2-plen);
            return true;
        }
    }
    /*for(int i=1;i<=strlen(p);i++)
    {
        printf("%d ",Next[i]);
    }*/
    return false;
}
string temp;
int main()
{
    //freopen("D:\\算法进阶\\字符串\\KMP\\in.txt","r",stdin);
    int order=0;
    for(string sa;cin>>sa,sa!=".";s[order++]=sa);
    for(string sa;cin>>sa;ss+=sa);

    int ans=0;
    //cout<<order<<endl;
    for(int i=0;ss[i];i++)
    {
        temp+=ss[i];
        //cout<<temp<<endl;
        for(int i=0;i<order;i++)
        {
            if(kmp(temp,s[i]))
            {

                ans+=temp.length();
                //cout<<ans<<endl;
                temp="";
                break;
                //cout<<ans<<endl;

            }
        }
    }
    printf("%d",ans);

    return 0;
}
