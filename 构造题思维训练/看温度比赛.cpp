/*类似于dp的思想，从前面一个数的状态推后面的*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
string s;
int a[maxn],b[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int cnt=2,sum=1;
        cout<<1<<' ';
        for(int i=1;i<s.length();i++)
        {
            cnt++;//参加的总人数
            if(s[i]==s[i-1]) cout<<sum<<' ';//多一个数，淘汰多一个最值，不变
            else
            {
                sum=cnt-1;//出现01之类，在前面的基础上再淘汰多一位
                cout<<sum<<' ';
            }
        }
        cout<<endl;
    }
}
