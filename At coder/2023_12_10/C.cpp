#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

char s[1005];
int pos0[1005],num1[1005],num2[1005];
int n,m;

int main()
{
    cin>>n>>m;
    int num=1;
    int cnt1=0,cnt2=0;
    int i=0;
    for(i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]=='1') cnt1++;
        if(s[i]=='2') cnt2++;
        if(s[i]=='0')
        {
            pos0[num]=i;
            num1[num]=cnt1;
            num2[num]=cnt2;
            num++;
            cnt1=0;
            cnt2=0;
        }
    }
    if(s[n]!='0')
    {
         pos0[num]=i;
         num1[num]=cnt1;
         num2[num]=cnt2;
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=num;++i)
    {
        ans2=max(ans2,num2[i]);


    }
    for(int i=1;i<=num;i++)
    {
        int rest=ans2-num2[i];//Ê£ÏÂµÄ
        if(num1[i]>m)
        {
            int temp1=num1[i]-m;
            if(temp1>rest)
                ans1=max(ans1,temp1-rest);

        }
    }
    cout<<ans1+ans2<<endl;

    return 0;

}
