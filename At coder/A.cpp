#include<bits/stdc++.h>
using namespace std;

int n,s[1005],x;
int sum=0;
int main()
{
    cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
    {
        if(s[i]<=x)
            sum+=s[i];
    }

    cout<<sum<<endl;

    return 0;
}
