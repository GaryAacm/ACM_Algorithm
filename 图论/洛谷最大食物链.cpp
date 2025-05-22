#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
#define mod 80112002
int n,m,ans,f[maxn],ind[maxn],outd[maxn];
vector<int> p[maxn];
queue<int> Q;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        outd[x]++;
        ind[y]++;//��¼���Ⱥ����
        p[x].push_back(y);//��������
    }
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)//�ҳ����Ϊ0�����
        {
            f[i]=1;//��ʼ��
            Q.push(i);
        }
    }
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for(int i=0;i<p[x].size();i++)
        {
            int y=p[x][i];//�ҵ����ӵı�
            f[y]=(f[x]+f[y])%mod;//��ȡģ������̫��
            ind[y]--;
            if(ind[y]==0)
                Q.push(y);//��Ϊ������
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(outd[i]==0)
        {
            //���ʳ����һ��������Ϊ0
            ans=(ans+f[i])%mod;
        }
    }
    cout<<ans;
    return 0;
}

