#include<bits/stdc++.h>
using namespace std;
#define mod 233
#define base 150
const int maxn=2e5+10;
vector<string> linker[mod+2];

char a[maxn];
int n,ans;
int main()
{
    //freopen("D:\\算法进阶\\At coder\\2023_11.18\\in.txt","r",stdin);
    //cin>>n;
    scanf("%d",&n);
    /*for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }*/
    scanf("%s",a);
    ans=1;
    int hashs=1;
    hashs=(hashs*base*111+a[0])%mod;//计算哈希值
    string ss="";
    ss+=a[0];
    linker[hashs].push_back(ss);
    for(int i=1;i<n;i++)
    {
        if(a[i]==ss[0])//合并,新的子串
        {
            ss=ss+a[i];

            hashs=(hashs*base*111+a[i])%mod;//计算哈希值
            int flag=1;
            for(int i=0;i<(int)(linker[hashs].size());i++)
           {

              if(linker[hashs][i]==ss)
               {
                   flag=0;
                   break;//有重复的出现
               }

           }
           if(flag)
           {
               linker[hashs].push_back(ss);
               ans++;//新的子串
           }

        }
        else
        {
            ss="";//置空
            ss+=a[i];
            hashs=1;
            hashs=(hashs*base*111+a[i])%mod;//计算哈希值
            int flag=1;
            for(int i=0;i<(int)(linker[hashs].size());i++)
           {

              if(linker[hashs][i]==ss)
               {
                   flag=0;
                   break;//有重复的出现
               }

           }
           if(flag)
           {
               linker[hashs].push_back(ss);
               ans++;//新的子串
           }
        }


    }
    printf("%d",ans);

    return 0;

}
