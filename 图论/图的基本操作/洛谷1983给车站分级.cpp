#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1005;
int n,m,s;
int tuopu[maxn][maxn];//用来记录j比i级别高
int out[maxn];//出度
int st[maxn];//站点
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
            is[st[j]]=1;//标记出现
        }
        for(int k=st[1];k<=st[s];k++)//找到路上没有出现的级别低的
        {
            if(!is[k])//k级别低
            {
                for(int x=1;x<=s;x++)
                    {
                        if(!tuopu[k][st[x]])
                        {
                            tuopu[k][st[x]]=1;
                            out[st[x]]++;//出度加一
                        }
                    }
            }
        }

    }
    //找出出度为0的
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
                if(tuopu[temp[i]][j])//有出度
                {
                    out[j]--;
                    tuopu[temp[i]][j]=0;//已经删除
                }
            }
        }
        ans++;
    }while(flag);
    cout<<ans-1<<endl;
}
