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
            pay=(a-sum)/(k-1)+1;//�����ÿ����עҪ�ر��õĽ�ң�a-sum���Ѿ����˵���ע��
        }
        if(sum>=pay)//�����Ǳ�֤�����һ��1��ע�汾
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
    }
}
