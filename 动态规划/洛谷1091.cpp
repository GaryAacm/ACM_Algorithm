#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,a[maxn];
int d1[maxn],d2[maxn];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        d1[i]=1;
        d2[i]=1;
    }

    //������ΪҪ��¼·�������Բ���lower�ķ���

    //�������������
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(a[i]>a[j]&&d1[i]<=d1[j]+1)
            {
                d1[i]=d1[j]+1;
            }
        }
    }

    //����½�������,����������
    for(int i=n-1;i>=1;i--)
    {
        for(int j=n;j>=i;j--)
        {
            if(a[i]>a[j]&&d2[i]<d2[j]+1)
                d2[i]=d2[j]+1;
        }
    }

    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        maxx=max(maxx,d1[i]+d2[i]-1);//��ȥ�Լ�
    }
    cout<<n-maxx<<endl;
    return 0;
}
