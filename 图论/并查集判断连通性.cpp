#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int fa[maxn],n,m,a,b;
int find(int x)
{
    if(x==fa[x]) return x;
    else
        return fa[x]=find(fa[x]);
}
void join(int x,int y)
{
    int c1=find(x),c2=find(y);
    if(c1!=c2) fa[c1]=c2;
}
//������ǲ��鼯����
int main()
{
    while(true)
    {
        int ans=0;//��֤ansÿ��Ϊ0
        cin>>n;
        if(n==0)
        {

            return 0;
        }
        cin>>m;
        for(int i=1;i<=n;++i)
        {
            fa[i]=i;//��ʼ��
        }
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            join(a,b);
        }
        for(int i=1;i<=n;++i)
        {
            if(find(i)==i)//����ע�����Ҹ��׽ڵ㣬���׽ڵ����Լ��Ľڵ��˵��û��·
                ans++;
        }
        cout<<ans-1<<'\n';
    }
    return 0;
}
