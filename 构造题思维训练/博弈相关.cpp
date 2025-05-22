/*思维问题，就是使得数大的人会选两个奇数和两个偶数，优先两个奇数，
使得答案小的人会选一奇一偶，使得答案减一，所以三个以上奇数会使答案减一，处理余数的时候
余数为1也会是答案减一，因为必定会选上一奇一偶*/
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
