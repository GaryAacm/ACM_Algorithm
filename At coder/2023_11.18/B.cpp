#include<bits/stdc++.h>
using namespace std;
int n;
int a[1050];
int maxx=-1;
int main()
{
    //freopen("D:\\Ëã·¨½ø½×\\At coder\\2023_11.18\\in.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxx=max(a[i],maxx);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==maxx)
            continue;
        ans=max(ans,a[i]);
    }
    cout<<ans;

    return 0;
}
