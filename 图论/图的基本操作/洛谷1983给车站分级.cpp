#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1005;
int n,m,s;
int tuopu[maxn][maxn];//������¼j��i�����
int out[maxn];//����
int st[maxn];//վ��
bool vis[maxn],is[maxn];
int temp[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        cin>>s;
        memset(is,0,sizeof(is));
        for(int j=1;j<=s;j++)
        {
            cin>>st[j];
            is[st[j]]=1;//��ǳ���
        }
        for(int k=st[1];k<=st[s];k++)//�ҵ�·��û�г��ֵļ���͵�
        {
            if(!is[k])//k�����
            {
                for(int x=1;x<=s;x++)
                    {
                        if(!tuopu[k][st[x]])
                        {
                            tuopu[k][st[x]]=1;
                            out[st[x]]++;//���ȼ�һ
                        }
                    }
            }
        }

    }
    //�ҳ�����Ϊ0��
    int ans=0;
    int flag=0;
    do
    {
        flag=0;
        for(int i=1;i<=n;i++)
        {
            if(out[i]==0&&!vis[i])
            {
                vis[i]=true;
                temp[++flag]=i;
            }
        }

        for(int i=1;i<=flag;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(tuopu[temp[i]][j])//�г���
                {
                    out[j]--;
                    tuopu[temp[i]][j]=0;//�Ѿ�ɾ��
                }
            }
        }
        ans++;
    }while(flag);
    cout<<ans-1<<endl;
}
