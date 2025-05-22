/*  https://codeforces.com/contest/1914/problem/D */
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1e5+10;
int t,n,k;
int main()
{
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<int> b(n);
        for(int i=0;i<n;i++)
            cin>>b[i];
        int ans=a[0]+b[0]*(k-1);
        int sum=a[0];//����������i���ĵõ�����
        int maxx=b[0];//���ǿ�ʼö��ͣ����i����ʱ��ֻ��i����ǰ������ֵ����
        for(int i=1;i<n;i++)
        {
            if(k<=i) break;//������
            maxx=max(maxx,b[i]);//ֻ��ǰ������
            sum+=a[i];
            ans=max(ans,sum+maxx*(k-i-1));
        }
        cout<<ans<<endl;
    }
    return 0;
}
