#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define int long long
const int maxn=2e5+10;

int t,n,a[maxn];


//˼·���ҵ�������������룬һ��һ�����룬�ҵ���ǰ���Դﵽ������
//�ҵ���ǰ�����Դﵽ����һ��һ�εݹ鴦��
void solve(int x)
{
    if(x<0) return ;
    int k=ceil(sqrt(x));
    k=k*k;//�ҵ���ǰ���Դﵽ����ֵ
    solve(k-x-1);//����һ������������
    //for(int i=x;i>=k-x;i--) cout<<i<<' ';
    int tmp=x;
    for(int i=k-x;i<=x;i++)
    {
        a[i]=tmp--;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        solve(n-1);//��0��ʼ
        for(int i=0;i<n;i++)
            cout<<a[i]<<' ';
        cout<<'\n';
    }
}
