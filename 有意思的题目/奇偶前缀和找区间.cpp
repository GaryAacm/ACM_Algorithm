#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
ll t,n;
//�Բ�ֵ����ǰ׺�ʹ���
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<ll> arr(n);
        map<ll,ll> mapp;//��map����Ӧǰ׺�ͣ��ж���Ӧ��ǰ׺���Ƿ����
        ll ans=0;
        bool temp=false;
        mapp[0]++;
        for(int i=0;i<=n-1;i++)
        {
            cin>>arr[i];
            if(i&1){
                ans+=arr[i];
            }
            else
                ans-=arr[i];
            if(mapp[ans])//�ڶ��γ�����ͬǰ׺�ͣ�˵���м��ǲ���Ϊ0
            {
                temp=true;
            }
            mapp[ans]++;
        }
        if(temp) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
}
