#include<bits/stdc++.h>
using namespace std;

struct node
{
    int sta,endd;
}a[1001];
int vis[1001];

int t,n;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].sta>>a[i].endd;
            if(a[i].sta>a[i].endd)//��֤ǰ���С
            {
                int temp=a[i].sta;
                a[i].sta=a[i].endd;
                a[i].endd=temp;
            }
            //�����Ӧ�����ȱ��
            //�����൱��3��4��Ӧ2�����ȣ���ͬռ����2������

            int from=(a[i].sta+1)/2;
            int to=(a[i].endd+1)/2;
            for(int i=from;i<=to;i++)
            {
                 vis[i]++;
                 ans=max(ans,vis[i]);//���ǿ��������߹�����������һ������
            }

        }
        cout<<ans*10<<endl;
    }
}
