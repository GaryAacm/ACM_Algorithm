#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
const int INF = 1e9;
int n,m,u,v,w,q,x,y,t;
int a[20005];
int grap[maxn][maxn];

void update(int k){//�����������𲽸�����ת�ĵ�
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            if(grap[i][j]>grap[i][k]+grap[k][j])
                grap[i][j]=grap[i][k]+grap[k][j];
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    //freopen("D:\\�㷨����\\ͼ��\\���·\\in.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            grap[i][j]=INF;
        }
    }
    for(int i=0;i<n;i++)
    {

        grap[i][i]=0;
    }
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        grap[u][v]=grap[v][u]=w;
    }
    int now=0;//��¼��ǰ������
    cin>>q;
    while(q--)
    {
        cin>>x>>y>>t;
        while(a[now]<=t&&now<n){
            update(now);
            now++;
        }
        //��֤���ʲ���δ���õĴ���
        if(a[x]>t||a[y]>t) cout<<-1<<endl;
        else if(grap[x][y]==INF) cout<<-1<<endl;

        else cout<<grap[x][y]<<endl;
    }

    return 0;
}
