#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;

int t,n,m;
//����Ҫ1רע���Ȿ�ʣ���Ϊ��Ҫ������Ƿ�����
int solve(int n,int m)
{
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x==m) return 1;
        else if(x<m) continue;
        else if(x%3==0)
        {
            q.push(x/3);
            q.push(x*2/3);
        }
    }
    return 0;
}

signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>m;
        if(solve(n,m)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
