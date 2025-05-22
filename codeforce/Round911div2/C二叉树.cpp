#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=3e5+10;

int n,lc[maxn],rc[maxn],t;
char s[maxn];

int dfs(int x)
{

    if(lc[x]==0&&rc[x]==0) return 0;//叶子节点
    int res=INF;
    if(lc[x]) res=min(res,dfs(lc[x])+(s[x]!='L'));//当前节点
    //cout<<"out"<<endl;
    if(rc[x]) res=min(res,dfs(rc[x])+(s[x]!='R'));
    //cout<<"out"<<endl;
    return res;

}

int main()
{
    //freopen("D:\\算法进阶\\codeforce\\Round911div2\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&n,s+1);
        //scanf("%s",s+1);
        //cout<<s[1]<<endl;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&lc[i],&rc[i]);
        printf("%d\n",dfs(1));
    }

    return 0;
}

