#include<bits/stdc++.h>
//����ֻҪ��n���ַ�������β��ĸ�����ǵ㣬����ַ������ű�������Ϳ��������ж��ܷ�����һ������ж�ŷ����·
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
        //for(int i=0;i<=n;i++) fa[i]=i;//����Ҫȥ��n��ô�󣡣�����������30����
        for(int i=1;i<=n;i++)
        {
            scanf("%s",str);
            int u=str[0]-'a';
            int v=str[strlen(str)-1]-'a';
            in[u]++;//����ͼ����
            out[v]++;
            vis[u]=vis[v]=1;//������Щ��ĸ
            join(u,v);//ͬһ����ĸ����Ⱥͳ�����һ��
        }
        int a=0,b=0,c=0,d=0;
        for(int i=0;i<26;i++)
        {
            if(fa[i]==i&&vis[i]) c++;//�ж��Ƿ���ͨ
            if(vis[i])//ŷ����·�ж�
            {
                if(in[i]==out[i]) continue;//����
                else if(out[i]+1==in[i]) a++;//�ж�ͷ��
                else if(in[i]+1==out[i]) b++;//�ж�β��

                else d++;
            }
        }
        /*if(c>1 || d>0) { printf("The door cannot be opened.\n"); }
        else if((a==0&&b==0) || (a==1&&b==1)) { printf("Ordering is possible.\n"); }
        else { printf("The door cannot be opened.\n"); }*/
        if(c>1 || d>0) { puts("The door cannot be opened."); }//����ͨ
        else if((a==0&&b==0) || (a==1&&b==1)) { puts("Ordering is possible."); }//���ǻ�·����Ϊ��״���߻�·��״
        else { puts("The door cannot be opened."); }
    }

    return 0;
}
