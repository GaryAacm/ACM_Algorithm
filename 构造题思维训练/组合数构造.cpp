/*˼ά���⣬����ֻö�ٵȱ��Լ�����������*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
#define int long long
int a[maxn],b[maxn],c[maxn];//c��ǰ׺��
int n,t,sum=0;


signed main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[a[i]]++;//��¼���ֵĴ���
        }
        c[0]=b[0];
        for(int i=0;i<=n;i++)//��0��ʼ��0�η���1
        {
            if(i>0) c[i]=c[i-1]+b[i];//��¼ǰ����ֱȽ�С�����ݵ�һ�εĴ���
            if(b[i]>1&&i>0)
            {
                sum+=b[i]*(b[i]-1)/2*c[i-1];

            }
            if(b[i]>2)
                sum+=b[i]*(b[i]-1)*(b[i]-2)/6;
        }
        cout<<sum<<endl;
    }

}

