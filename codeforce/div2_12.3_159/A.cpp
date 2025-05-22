#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int t,ans=0,n;
char s[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("D:\\Ëã·¨½ø½×\\codeforce\\div2_12.3_159\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        int cnt1=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
                cnt1++;
        }
        if(cnt1==n)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }

    return 0;

}
