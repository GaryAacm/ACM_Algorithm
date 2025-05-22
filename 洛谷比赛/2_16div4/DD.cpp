#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
int k;
bool check(int x)
{
    int a=x/100;
    int s=x/10,ss=x-a*100;
    if(s%k!=0) return false;
    if(x%k!=0) return false;
    if(ss%k!=0) return false;
    return true;
}

int main()
{

    cin>>k;
    bool f=false;
    for(int i=100;i<=999;i++)
    {
        if(check(i))
        {
            cout<<i<<endl;
            f=true;
        }
    }
    if(!f) cout<<"None!"<<endl;
}
