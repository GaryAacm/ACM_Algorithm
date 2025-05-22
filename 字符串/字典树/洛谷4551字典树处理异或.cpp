#include<bits/stdc++.h>
using namespace std;
struct node{
    int to;
    int w;
    int nxt;
}edge[2000001];

int head[2000001];
int cnt=-1;

void addedge(int u,int v,int w)
{
    edge[++cnt].nxt=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt;
}
int sum[2000001];

void dfs(int x,int fa)//�ҵ���Ӧ�ĵ㵽���ڵ�����ֵ
{
    for(int i=head[x];~i;i=edge[i].nxt)
    {
        int to=edge[i].to;
        int wei=edge[i].w;
        if(to!=fa)
        {
            sum[to]=sum[x]^wei;
            dfs(to,x);
        }
    }
}

//�����ƽ����ֵ���
struct trie{
    int ch[2];
}t[2000001];
int tot;
void build(int val,int x){
    for(int i=(1<<30);i;i>>=1){//��30λ�����Ʊ���
        bool c=val&i;//ȡ����������������ĵ�ǰλ�ã���0����1
        if(!t[x].ch[c]){//��ǰ�����û�д���
            t[x].ch[c]=++tot;//�����µĴ洢λ��
        }
        x=t[x].ch[c];//ָ����һ���洢λ��
    }
}

//�������ֵ�����ѯ
int query(int val,int x){
    int ans=0;
    for(int i=(1<<30);i;i>>=1){
        bool c=val&i;
        if(t[x].ch[!c]){//�����һλ���Խ�������������һ��������
            ans+=i;
            x=t[x].ch[!c];
        }
        else x=t[x].ch[c];//�����������һ��·������
    }
    return ans;
}


int main(){
    memset(head,-1,sizeof(head));
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    dfs(1,-1);//Ԥ�����ÿһ���ڵ㵽��������
    for(int i=1;i<=n;++i)build(sum[i],0);//����trie��
    int ans=0;
    for(int i=1;i<=n;++i){
        ans=max(ans,query(sum[i],0));//��ѯ��ȡ���ֵ
    }
    printf("%d\n",ans);

    return 0;
}
