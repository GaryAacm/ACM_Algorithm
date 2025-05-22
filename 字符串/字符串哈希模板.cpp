#include<bits/stdc++.h>
using namespace std;

const int maxn=10005;
vector<string> List[maxn];

unsigned int BKDHash(char *str)//关键在这一步，优质的处理哈希值
{
    unsigned int seed=31,key=0;
    while(*str)
        key=key*seed+(*str++);//计算字符串哈希值
    return key& 0x7fffffff;
}

int main()
{
    int n,m,key;
    char s[maxn];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            List[i].clear();
        for(int i=0;i<n;i++)
        {
            cin>>s;
            key=BKDHash(s)%maxn;
            List[key].push_back(s);
        }
    }
}
