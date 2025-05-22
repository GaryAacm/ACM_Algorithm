#include<bits/stdc++.h>
using namespace std;

int t,n,x;

int main()
{
    //freopen("D:\\Ëã·¨½ø½×\\codeforce\\11.24div2\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        int ans=0;
        int last=0;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            cin>>temp;
            ans=max(ans,temp-last);
            last=temp;
        }
        ans=max(ans,(x-last)*2);
        cout<<ans<<endl;
    }
    return 0;

}
