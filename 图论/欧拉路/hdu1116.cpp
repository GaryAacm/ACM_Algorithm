#include<bits/stdc++.h>
//我们只要把n个字符串的首尾字母看作是点，这个字符串看着边来处理就可以啦，判断能否连在一起就是判断欧拉回路
using namespace std;
const int maxn=1005;

int t,fa[30],in[30],out[30],vis[30],n;
char str[maxn];

int finded(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=finded(fa[x]);
}

void join(int a,int b)
{
    int c1=finded(a),c2=finded(b);
    if(c1!=c2)
        fa[c1]=c2;
}
void init()
{
    for(int i=0; i<30; i++)
    {
        fa[i] = i;
        in[i] = out[i] = 0;
        vis[i] = 0;
    }
}


int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        /*memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(vis,0,sizeof(vis));*/
        init();
        //for(int i=0;i<=n;i++) fa[i]=i;//不需要去到n那么大！！！！！！！30够了
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            int u=str[0]-'a';
            int v=str[strlen(str)-1]-'a';
            in[u]++;//有向图处理
            out[v]++;
            vis[u]=vis[v]=1;//出现这些字母
            join(u,v);//同一个字母的入度和出度在一起
        }
        int a=0,b=0,c=0,d=0;
        for(int i=0;i<26;i++)
        {
            if(fa[i]==i&&vis[i]) c++;//判断是否连通
            if(vis[i])//欧拉回路判断
            {
                if(in[i]==out[i]) continue;//跳过
                else if(out[i]+1==in[i]) a++;//判断头部
                else if(in[i]+1==out[i]) b++;//判断尾部

                else d++;
            }
        }
        /*if(c>1 || d>0) { printf("The door cannot be opened.\n"); }
        else if((a==0&&b==0) || (a==1&&b==1)) { printf("Ordering is possible.\n"); }
        else { printf("The door cannot be opened.\n"); }*/
        if(c>1 || d>0) { puts("The door cannot be opened."); }//不连通
        else if((a==0&&b==0) || (a==1&&b==1)) { puts("Ordering is possible."); }//不是回路，即为链状或者回路环状
        else { puts("The door cannot be opened."); }
    }

    return 0;
}
