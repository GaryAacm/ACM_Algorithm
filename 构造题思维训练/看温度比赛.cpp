/*������dp��˼�룬��ǰ��һ������״̬�ƺ����*/
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
            cnt++;//�μӵ�������
            if(s[i]==s[i-1]) cout<<sum<<' ';//��һ��������̭��һ����ֵ������
            else
            {
                sum=cnt-1;//����01֮�࣬��ǰ��Ļ���������̭��һλ
                cout<<sum<<' ';
            }
        }
        cout<<endl;
    }
}
