#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
#define int long long
int a[10]={0,4,54,454,5454,45454,545454,4545454,54545454,454545454};
int t,n;
//˼·���Ƕ���β��Ϊ9��������������ȥ���
void solve()
{
    cin>>n;
    int tmp=n/2;
    if(n%2==0||tmp%10<9)
    {
        if(n%2==0)
        {
            cout<<tmp<<' '<<tmp<<endl;
            return ;
        }
        else
        {
            cout<<tmp<<' '<<tmp+1<<endl;
            return ;
        }
    }
    else
    {
        int k=tmp,cnt=0;
        while(k>0&&k%10==9)//�ҵ�λ��
        {
            cnt++;
            k/=10;
        }
        cout<<tmp-a[cnt]<<' '<<tmp+1+a[cnt]<<endl;
        return;
    }
}

signed main()
{
    cin>>t;
    while(t--)
    {
        solve();
    }
}
