#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m;
ll p;
int main()
{
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>p;
        if(m<p)
        {
            cout<<"Alice"<<endl;
        }
        else if(m>=p&&n<p)
        {
            cout<<"Bob"<<endl;
        }
        else
        {
            int a=0;
            while(n&&m)
            {
                if(!a)//¶ÔBob²Ù×÷
                {
                    m=m-m%p;
                    a=1;
                }
                else if(a)
                {
                    n=n-n%p;
                    a=0;
                }
                if(n%p==0&&m%p==0)
                {
                    cout<<"Lasting Battle"<<endl;
                    break;
                }
            }
            if(n==0) cout<<"Bob"<<endl;
            else if(m==0) cout<<"Alice"<<endl;
        }
    }
}
