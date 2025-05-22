/*  https://codeforces.com/contest/1913/problem/B */
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
int pos[maxn];
string s;
int t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)//��1�ĸ�����0����ȼȿ���ƥ�䣬����0��1���
    {
        cin>>s;
        int n=s.length();
        int a0=0,a1=0,c0=0,c1=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='0') ++a0;
            else ++a1;
        }

        int ans=n;
        //cout<<a0<<' '<<a1<<endl;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='0') ++c0;
            else ++c1;

            //cout<<c0<<' '<<c1<<endl;

            if(a0>=c1&&a1>=c0)//�ж������ĸ����꣬ƥ����,
                ans=min(ans,n-i-1);//����ÿ���ַ�����������ƥ�䣬���������޷�ƥ���ɾ������ȫ��
        }
        cout<<ans<<endl;

    }

}
