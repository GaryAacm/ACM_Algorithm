#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+10;
//�����п��Լ��ٵĶ����٣���������ܺͷ�������������
//���еļ���Ϊ1��1���ܼ��ٷ����1��1�ĸ���������ڿɷ���ģ��Ͳ���
//һ��ʼ���뷨�������¼���ִ����������������ܴ��޷�����
//˼��Ӧ����һ����������߼�����ԭ����ͬ��ͨ������ͼ���������
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
            b[i]+=b[i-1];//��Ϊ1���Է���ĺ�
            c[i]=tmp;//��¼����1�ĸ�����ֻ������
        }
        while(q--)
        {
            cin>>l>>r;
            if(l==r)
            {
                cout<<"NO"<<'\n';
                continue;
            }
            int k=c[r]-c[l-1];//1�ĸ���
            int sum=b[r]-b[l-1];//����ĺ���
            if(sum>=k) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}
