/*˼ά���⣬����ʹ��������˻�ѡ��������������ż������������������
ʹ�ô�С���˻�ѡһ��һż��ʹ�ô𰸼�һ��������������������ʹ�𰸼�һ������������ʱ��
����Ϊ1Ҳ���Ǵ𰸼�һ����Ϊ�ض���ѡ��һ��һż*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
ll t,n,a,sum,num;;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=num=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            sum+=a;
            num+=a%2;
            if(i==1) cout<<sum<<' ';
            else cout<<sum-num/3-(num%3==1)<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
