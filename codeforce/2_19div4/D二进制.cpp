#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int tmp=2147483647;
int a[maxn],b[maxn];
//���ȷ����������һ�������λ��һ����������1<<30-1������ҵ��������
//�������Ǽ������⣬��map��¼ÿ�������ִ��������һض�Ӧ���ֵ��Ǹ����Ĵ���
//���������֮��õ�int�����ֵ����¼ÿ��ֵ���ҵ�����ƥ���ֵ��һһ��Ӧ��
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //cout<<(1<<31)-1<<endl;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<int,int> mapp;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mapp[a[i]]++;//��¼���ֵ���ֵĴ���
        }
        int all=n;
        int ans=0;
        for(auto &[x,y]:mapp)
        {
            int w=tmp^x;//�ҵ���Ӧ��ֵ
            int y1=y,y2=mapp[w];//y2�������Ӧ��ֵ���ֵĴ���,y1�����ֵ������ֵĴ���
            int y3=min(y1,y2);
            all-=2*y3;//ͬʱ����
            ans+=y3;
            mapp[w]-=y3;
            mapp[x]-=y3;
        }
        ans+=all;//ʣ�µ��Լ�һ��һ��
        cout<<ans<<endl;
    }
}
