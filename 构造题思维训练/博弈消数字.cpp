#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n,m;
int a[maxn];//���ڼ�¼��ǰ��ĩβ0�ĸ���
//̰��˼·����¼ĩβ0�ĸ������򣬰���˳��ɾ��

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        m++;//�������ֳ��������бȽ�
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            sum+=s.length();
            int k=0;
            while(s.back()=='0') k++,s.pop_back();
            a[i]=k;
        }
        sort(a+1,a+1+n);
        int f=0;//��ʾ˭�ȶ�
        for(int i=n;i>=1;i--)//�����ȶ����Ӵ�С
        {
            if(!f)
            {
                sum-=a[i];
                f=1;
            }
            else//��ɾ��
            {
                f=0;
            }
        }
        if(sum>=m) puts("Sasha");
        else puts("Anna");
    }
}
