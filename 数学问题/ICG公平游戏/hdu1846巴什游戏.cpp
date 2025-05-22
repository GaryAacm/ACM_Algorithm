#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int n,m,t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
    if(n%(m+1)==0) cout<<"second"<<endl;
    else cout<<"first"<<endl;
    }


    return 0;
}
