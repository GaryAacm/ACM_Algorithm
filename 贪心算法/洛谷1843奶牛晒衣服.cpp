#include<bits/stdc++.h>
using namespace std;
int x;
priority_queue<int> Q;
int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        Q.push(x);//入队
    }
    int ans=0;
    while(1)
    {
        ans++;
        int mx=Q.top();
        Q.pop();
        mx-=b;//用上烘干机
        Q.push(mx);
        if(Q.top()<=ans*a)
            break;
    }
    cout<<ans<<endl;
    return 0;
}
