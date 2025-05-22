/*思想问题，，就是让2，3分开，1在中间，保证2，3是质数取到最多*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
            cout<<1<<endl;
        else if(n==2)
        {
            cout<<"2 1"<<endl;
        }
        else if(n==3)
        {
            cout<<"2 1 3"<<endl;
        }
        else
        {
            int a=4;
            cout<<2<<' ';
            for(int i=2;i<=n/2;i++)
            {
                cout<<a<<' ';
                a++;
            }
            cout<<1<<' ';
            for(int i=n/2+2;i<n;i++)
            {
                cout<<a<<' ';
                a++;
            }
            cout<<3<<endl;
        }
    }
}
