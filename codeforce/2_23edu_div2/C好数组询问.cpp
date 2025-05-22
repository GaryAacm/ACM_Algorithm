#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+10;
//把所有可以减少的都减少，多出来的总和分配给必须增大的
//所有的减少为1，1不能减少分配给1，1的个数过多大于可分配的，就不行
//一开始的想法是排序记录出现次数，但是这样数很大无法处理
//思想应该是一个数增大或者减少与原来不同，通过增大和减少来处理
int t,n,q,a[maxn],b[maxn],c[maxn],l,r;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        int tmp=0;
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==1) tmp++;
            else
            {
                b[i]=a[i]-1;
            }
            b[i]+=b[i-1];//变为1可以分配的和
            c[i]=tmp;//记录区间1的个数，只能增加
        }
        while(q--)
        {
            cin>>l>>r;
            if(l==r)
            {
                cout<<"NO"<<'\n';
                continue;
            }
            int k=c[r]-c[l-1];//1的个数
            int sum=b[r]-b[l-1];//分配的和数
            if(sum>=k) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}
