#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
typedef long long ll;
long long s[N][N];
ll n,k;
int main()
{
    ll t,sum=0;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n>>k;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>s[i][j];
            }
        }

        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i][j]!=s[n-i+1][n-j+1])
                {
                    sum++;//��¼���Գ���ȵ�λ��
                }
            }
        }
        sum/=2;
        if(sum>k)
        {
            cout<<"No"<<endl;
        }
        else
        {
            if(n&1)
            {
                //ʣ�´���ֻ�ı��м�λ�õ�
                cout<<"Yes"<<endl;
            }
            else
            {
                if((k-sum)%2==0)//�����ظ����ȥ
                    cout<<"Yes"<<endl;
                else//���ܱ��ȥ
                    cout<<"No"<<endl;
            }
        }
    }
}
