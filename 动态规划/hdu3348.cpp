#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;

int t,n,dp1[MAXN],a[6],dp2[MAXN];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<5;i++)
        {
            cin>>a[i];

        }
        for(int i=1;i<=n;i++)
        {
            dp1[i]=MAXN;
            if(i>=100)
            {
                if(a[4]>0)
                {
                    dp1[i]=min(dp1[i],dp1[i-100]+1);
                    a[4]--;
                    continue;
                }
            }
            if(i>=50)
            {
                if(a[3]>0)
                {
                    dp1[i]=min(dp1[i],dp1[i-50]+1);
                    a[3]--;
                    continue;
                }
            }
            if(i>=10)
            {
                if(a[2]>0)
                {
                    dp1[i]=min(dp1[i],dp1[i-10]+1);
                    a[2]--;
                    continue;
                }
            }
            if(i>=5)
            {
                if(a[1]>0)
                {
                    dp1[i]=min(dp1[i],dp1[i-5]+1);
                    a[1]--;
                    continue;
                }
            }
            if(i>=1)
            {
                if(a[0]>0)
                {
                    dp1[i]=min(dp1[i],dp1[i-1]+1);
                    a[0]--;
                    continue;
                }
            }
        }
        cout<<dp1[n]<<endl;
    }
}
