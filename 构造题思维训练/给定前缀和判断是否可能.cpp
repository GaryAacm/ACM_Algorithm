#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;

ll t,n,k;
ll s[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=k;i++)
        {
            cin>>s[i];
        }
        bool f=true;
        if(k==1) cout<<"Yes"<<endl;
        else
        {
            for(int i=2;i<k;i++)
            {
                if(s[i+1]-s[i]<s[i]-s[i-1])
                {
                    f=false;
                    break;
                }
            }
            if(!f)
                cout<<"No"<<endl;
            else
            {
                ll x=s[2]-s[1];
                if(x*(n-k+1)<s[1])//������Ϊ��֤���ǵ����ģ�x��n+k-2�ǰ��ĺͲ�����x*(n-k+1),ע�����½�Ҫ��
                    cout<<"No"<<endl;
                else cout<<"Yes"<<endl;

            }
        }
    }
}
