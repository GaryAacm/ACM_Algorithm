/*�۲췢�־�������ö���������ҵ���С�Ĳ����������Ǹ�*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int p=1;
        while(!(n%p)) p++;
        for(int i=1;i<=n;i++) cout<<char(i%p+'a');
        cout<<'\n';
    }

    return 0;
}
