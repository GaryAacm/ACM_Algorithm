#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=666;

int n,m;
vector<int> s[maxn];
int in[30];
int vis[30],is[30],use[30];
char ans[30];
int num;
queue<int> Q;

int fuck()//拓扑排序
{
   int sum=0;
   int out=1;
   for(int i=1;i<=n;i++)
   {
       if(use[i]==0&&is[i])
        Q.push(i),sum++;

   }
   if(sum>1) out=0;
   sum=0;
   num=1;
   while(!Q.empty())
   {

       int u=Q.front();
       Q.pop();
       sum++;
       ans[num++]=u+'A'-1;
       for(int i=0;i<s[u].size();i++)
       {
           int v=s[u][i];
           use[v]--;

           if(use[v]==0)
            Q.push(v),sum++;
       }
       if(sum>1) out=0;
   }
   //cout<<"此时的sum："<<sum<<endl;
   //if(sum==n) return 1;
   for(int i=1;i<=n;i++)
   {
       if(use[i]>0)//环
       {
           out = -1;
           break;
       }
   }
   return out;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int now=0;
    int pos=0;
    for(int i=1;i<=m;i++)
    {

        char a,b,c;
        cin>>a>>b>>c;
        is[a-'A'+1]=is[c-'A'+1]=1;
        s[c-'A'+1].push_back(a-'A'+1);
        in[a-'A'+1]++;

        if(now==0)
        {
            for(int j=1;j<=n;j++) use[j]=in[j];//要操作的时候重新赋值
            now=fuck();
            pos=i;
        }
    }
    if(now==0)
        cout<<"Sorted sequence cannot be determined."<<endl;
    else if(now==1)
    {
        cout<<"Sorted sequence determined after "<<n<<" relations: ";
        for(int i=num-1;i>=1;i--)
            cout<<ans[i];
        cout<<'.'<<'\n';
    }
    else
        cout<<"Inconsistency found after "<<pos<<" relations."<<endl;
}
