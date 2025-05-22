#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
int t,n,k;
int a[55],pos[55];
int main()
{
    //freopen("D:\\Ëã·¨½ø½×\\codeforce\\div3_12_19\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==0)
        {
            for(int i=n;i>=1;i--)
            {
                cout<<i<<' ';
            }
            cout<<endl;
        }
        else if(k==n-1)
        {
            for(int i=1;i<=n;i++)
            {
                cout<<i<<' ';
            }
            cout<<endl;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                a[i]=n-i+1;
                pos[i]=a[i];
            }
            int i=n-k;
            int num=0;
            for(;i<=n;i++)
            {

                //cout<<num<<' '<<pos[num]<<endl;
                //cout<<a[i]<<endl;
                a[i]=pos[n-num];
                //cout<<a[i]<<endl;
                num++;
            }
            for(int i=1;i<=n;i++)
            {
                cout<<a[i]<<' ';
            }
            cout<<endl;
        }
    }
}
