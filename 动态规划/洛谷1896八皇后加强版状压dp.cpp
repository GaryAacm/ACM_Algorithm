#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
using namespace std;
int sit[2000],gs[2000];
int cnt=0;
int n,yong;
long long f[10][2000][100]={0};
void dfs(int he,int sum,int node)//Ԥ�����ÿһ��״̬
{
    if(node>=n)//����Ѿ�������ϣ�ע���Ǵ��ڵ��ڣ�
    {
        sit[++cnt]=he;
        gs[cnt]=sum;
        return;//�½�һ��״̬
    }
    dfs(he,sum,node+1);//���õ�node��
    dfs(he+(1<<node),sum+1,node+2);//�õ�node������ʱnodeҪ��2����������һ������
}
int main()
{
    scanf("%d%d",&n,&yong);
    dfs(0,0,0);
    for(int i=1;i<=cnt;i++)f[1][i][gs[i]]=1;//��һ�������״̬������1�������
    for(int i=2;i<=n;i++)
        for(int j=1;j<=cnt;j++)
            for(int k=1;k<=cnt;k++)//ö��i��j��k
            {
                if(sit[j]&sit[k])continue;
                if((sit[j]<<1)&sit[k])continue;
                if(sit[j]&(sit[k]<<1))continue;//�ų����Ϸ��������
                for(int s=yong;s>=gs[j];s--)f[i][j][s]+=f[i-1][k][s-gs[j]];//ö��s������f[i][j][s]
            }
    long long ans=0;
    for(int i=1;i<=cnt;i++)ans+=f[n][i][yong];//ͳ�����մ𰸣��ǵ���long long
    printf("%lld",ans);
    return 0;
}

