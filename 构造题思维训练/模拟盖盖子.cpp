#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
//��Ҫ��˼�룬����̰�Ĵ����˾ֲ������ʱ��Ҫ��dp��ת��״̬��dp������Ǵ���̰��
int dp[maxn][2];//�漰��̰�Ĳ��еģ���dp

int t,n,a[maxn];
string s;

bool cmp(int x,int y)
{
    return x>y;
}

void solve()
{
    cin>>n;
    cin>>s;
    s=" "+s;
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i][1]=0;
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1')//�и���
        {
            dp[i][0]=dp[i-1][0]+a[i-1];
            dp[i][1]=max(dp[i-1][0],dp[i-1][1])+a[i];
        }
        else dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
    }

    cout<<max(dp[n][0],dp[n][1])<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
