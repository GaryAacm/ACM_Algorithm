#include<bits/stdc++.h>
using namespace std;

int t,n,k;
int a[105];

int main()
{
    //freopen("D:\\�㷨����\\codeforce\\R912������\\in.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int flag=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];

        }
        for(int i=2;i<=n;i++)
        {
            if(a[i]<a[i-1])
            {
                flag=0;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;//�Ѿ��Ƿǽ���
        else
        {
            if(k==1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }

    return 0;
}
