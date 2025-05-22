/*就是构造特定的111或者999为回文数，注意高精度减法*/
#include<bits/stdc++.h>
using namespace std;
#define long long int
const int maxn=2e5+10;

int t,n,a[maxn],b[maxn],c[maxn];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        char s;
        cin>>n;
        for(int i=n-1;i>=0;i--)
        {
            cin>>s;
            a[i]=s-'0';
        }
        if(a[n-1]==9)//1111为回文数
        {
            for(int i=0;i<=n;i++)
            {
                b[i]=1;
            }
        }
        else//9999为回文数
        {
            for(int i=0;i<n;i++)
            {
                b[i]=9;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(b[i]<a[i])
            {
                --b[i+1],b[i]+=10;
            }
            c[i]=b[i]-a[i];
        }
        for(int i=n-1;i>=0;--i)
            cout<<c[i];
        cout<<endl;
    }
}
