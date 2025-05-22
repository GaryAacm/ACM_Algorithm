#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
typedef long long ll;
long long s[N][N];
ll n,k;
int main()
{
    ll t,sum=0;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n>>k;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>s[i][j];
            }
        }

        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i][j]!=s[n-i+1][n-j+1])
                {
                    sum++;//记录不对称相等的位置
                }
            }
        }
        sum/=2;
        if(sum>k)
        {
            cout<<"No"<<endl;
        }
        else
        {
            if(n&1)
            {
                //剩下次数只改变中间位置的
                cout<<"Yes"<<endl;
            }
            else
            {
                if((k-sum)%2==0)//可以重复变回去
                    cout<<"Yes"<<endl;
                else//不能变回去
                    cout<<"No"<<endl;
            }
        }
    }
}
