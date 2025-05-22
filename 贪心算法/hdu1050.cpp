#include<bits/stdc++.h>
using namespace std;

struct node
{
    int sta,endd;
}a[1001];
int vis[1001];

int t,n;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].sta>>a[i].endd;
            if(a[i].sta>a[i].endd)//保证前面的小
            {
                int temp=a[i].sta;
                a[i].sta=a[i].endd;
                a[i].endd=temp;
            }
            //算出对应的走廊编号
            //就是相当于3，4对应2号走廊，共同占用了2号走廊

            int from=(a[i].sta+1)/2;
            int to=(a[i].endd+1)/2;
            for(int i=from;i<=to;i++)
            {
                 vis[i]++;
                 ans=max(ans,vis[i]);//就是看公共的走过的最多的是哪一个部分
            }

        }
        cout<<ans*10<<endl;
    }
}
