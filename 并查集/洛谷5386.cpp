/*��Ϊ��Ŀֻ��2����ɫ����ô���ǰ�ͬһ����ɫ����һ��ķ���ͬһ����ͨ�����棬
Ҳ���ǰ�������ϲ�����ѯ��ʱ�����������û�й������ȣ�
��ô��һ��������2����ɫ���������ͬ�Ĺ������ȣ�
��ô����ֻҪ�ж����Ľڵ����ɫ�ǲ��ǲ�ѯ����ɫ
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int fa[maxn],n,m;
char s[maxn];
int col[maxn],ans[maxn];
int Find(int x)
{
    if(x==fa[x]) return x;
    else{
        return fa[x]=Find(fa[x]);
    }
}
void join(int x,int y)
{
    int c1=Find(x),c2=Find(y);
    if(c1!=c2) fa[c1]=c2;
}

int main()
{
    //freopen("D:\\�㷨����\\���鼯\\in.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;++i) fa[i]=i;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        if(s[u]==s[v]) join(u,v);
    }
    int cnt=0;
    while(m--)
    {
        int u,v;
        char ss;

        cin>>u>>v>>ss;
        if(Find(u)==Find(v)&&s[u]!=ss) ans[++cnt]=0;
        else ans[++cnt]=1;
    }

    for(int i=1;i<=cnt;++i) cout<<ans[i];

    return 0;
}
