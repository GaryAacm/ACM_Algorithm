#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int siz[52],a[52][52],all[52]; //��¼�Ƿ����
bool flag[52];

void init()
{
    for(int i=1;i<=50;i++)
    {
        all[i]=0;
        flag[i]=false;
        for(int j=1;j<=50;j++)
            a[i][j]=0;
    }
}

void solve()
{
    cin>>n;
    init();
    for(int i=1;i<=n;i++)
    {
        cin>>siz[i];
        for(int j=1;j<=siz[i];j++)
        {
            int k;
            cin>>k;
            a[i][k]=1; //����������������Ƿ�������1Ԫ��
            all[k]=1;//ȫ���������
        }

    }

    //ö��ȫ��������ֵ�Ԫ��
    int cnt=0,ans=0;
    for(int i=0;i<=50;i++)
    {
        if(!all[i]) continue;
        cnt=0;
        for(int j = 0; j <= 50; j++)
        {

            flag[j] = false;  //��ֹ�ظ�
        }
        for(int j=1;j<=n;j++) //ö��ȫ������
        {
            if(!a[j][i])//ȫ�������У���������û��
            {
                for(int k=0;k<=50;k++)//����������ϵ�Ԫ��
                {
                    if(!flag[k]&&a[j][k])
                    {
                        cnt++;
                        flag[k]=true;
                    }
                }
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}
