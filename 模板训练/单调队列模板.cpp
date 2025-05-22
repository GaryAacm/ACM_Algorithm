#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
int n,k;
int a[maxn];
deque<int> q,q2;
signed main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(!q.empty()&&q.front()<=i-k) q.pop_front();//推移
        while(!q.empty()&&a[q.back()]>=a[i]) q.pop_back();//保持单调递增
        q.push_back(i);
        if(i>=k) cout<<a[q.front()]<<' ';
    }
    cout<<endl;
    q.clear();
    for(int i=1;i<=n;i++)
    {
        if(!q.empty()&&q.front()<=i-k) q.pop_front();//注意队列为空的情况
        while(!q.empty()&&a[q.back()]<=a[i]) q.pop_back();//保持单调递减
        q.push_back(i);
        if(i>=k) cout<<a[q.front()]<<' ';
    }
    return 0;
}
