#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;
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
            if(i-last>=plen)//判断新的匹配能不能与之前的分开
                {
                    cnt++;
                    last=i;//找到可以分开的子串
                }
        }
    }
}

int main()
{
    while(~scanf("%s",str))
    {
        if(str[0]=='#') break;
        scanf("%s",pattern);
        cnt=0;
        kmp(str,pattern);
        printf("%d\n",cnt);
    }

    return 0;

}
