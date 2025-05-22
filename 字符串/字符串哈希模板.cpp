#include<bits/stdc++.h>
using namespace std;

const int maxn=10005;
vector<string> List[maxn];

unsigned int BKDHash(char *str)//�ؼ�����һ�������ʵĴ����ϣֵ
{
    unsigned int seed=31,key=0;
    while(*str)
        key=key*seed+(*str++);//�����ַ�����ϣֵ
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
