#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
int n,m,l,r;
deque<int> q;
int a[maxn];
int vis[maxn];
int sz=1e9;
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int tot=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[a[i]])
        {
            tot++;
        }
        vis[a[i]]++;
        q.push_back(i);
        while(!q.empty()&&vis[a[q.front()]]>1)
        {
            vis[a[q.front()]]--;
            q.pop_front();
        }

        if(tot==m)
        {
            if(q.size()<sz)//Ҫ������С���ȣ������ǵ�һ�ε�����m�ͽ���
            {
                sz=q.size();
                l=q.front();
				r=q.back();
            }
        }
    }
    cout<<l<<' '<<r<<endl;
}
