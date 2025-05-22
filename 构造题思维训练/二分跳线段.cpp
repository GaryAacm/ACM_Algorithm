#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;

int t,n;
int l[maxn],r[maxn];

bool check(int x)
{
    int left=0,right=0;
    for(int i=1;i<=n;i++)
    {
        left-=x;
        right+=x;
        //�������ķ�Χ
        if(left>r[i]||right<l[i])
        {
            return false;
        }
        else
        {
            left=max(left,l[i]);
            right=min(right,r[i]);//�ҵ���Ч��������
        }

    }
    return true;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>l[i]>>r[i];
        }
        int st=0,ed=2e9;
        int ans;
        //ϸ���ûر�׼�Ķ��ִ���
        while(st<=ed)
        {
            int mid=(st+ed)>>1;
            if(check(mid))
            {
                ed=mid-1;
                ans=mid;
            }
            else
            {
                st=mid+1;
                //cout<<0<<endl;
            }
        }
        cout<<ans<<'\n';
    }
}
