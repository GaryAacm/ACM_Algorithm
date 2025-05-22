#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int n,k,t;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                cout<<char(j+96);
            }
        }
        cout<<endl;
    }

}
