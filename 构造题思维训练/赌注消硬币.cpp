#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define int long long
const int maxn=2e5+10;

int t,k,x,a;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>k>>x>>a;
        int sum=a;
        int pay=1;
        for(int i=1;i<=x;i++)
        {
            sum-=pay;
            if(sum<0) break;
            pay=(a-sum)/(k-1)+1;//计算出每次下注要回本用的金币，a-sum是已经用了的下注数
        }
        if(sum>=pay)//这里是保证了最后一次1下注绘本
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
    }
}
