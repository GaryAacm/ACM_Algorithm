/*�۲췢��n�ڵ�һλ��Ȼ����n-1��2���棬��֤����Ϊ1����ǰ׺�;�Ϊ������*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int a[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1) cout<<1<<endl;
        else
        {
            if(n&1) cout<<-1<<endl;
            else
            {
                cout<<n<<' ';
                for(int i=n-1,j=2;j<=n-2;j+=2,i-=2)
                    cout<<i<<' '<<j<<' ';
                cout<<1<<endl;
            }
        }
    }
}
