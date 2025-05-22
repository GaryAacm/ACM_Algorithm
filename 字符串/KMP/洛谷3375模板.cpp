#include<bits/stdc++.h>
using namespace std;

const int maxn=1000010;
char str[maxn],pattern[maxn];
int Next[maxn],cnt;

void getFail(char *p,int plen)//得到next数组
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


void kmp(char *s,char *p)
{
    int last=-1;
    int slen=strlen(s),plen=strlen(p);
    getFail(p,plen);
    int j=0;

    for(int i=0;i<slen;i++)//开始匹配
    {
        while(j&&p[j]!=s[i]) j=Next[j];//失配
        if(s[i]==p[j]) j++;//往后匹配
        if(j==plen)//匹配成功
        {
            printf("%d\n",i+2-plen);
        }
    }
    for(int i=1;i<=strlen(p);i++)
    {
        printf("%d ",Next[i]);
    }
}

int main()
{
    //freopen("D:\\算法进阶\\字符串\\KMP\\in.txt","r",stdin);
    scanf("%s",str);
    scanf("%s",pattern);
    kmp(str,pattern);

    return 0;
}

