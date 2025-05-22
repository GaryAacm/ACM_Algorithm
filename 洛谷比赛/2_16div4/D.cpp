#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1e5+10;
int t,n,m;
string s;
int b[maxn];
char ss[maxn];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        bool flag=true;
        int num=0;
        int cnt=0;
        int tmpp=0;
        for(int i=1;i<=m;i++)
        {
            cin>>ss[i];
            if(ss[i]=='1')
            {
                if(cnt==0)//��λһ
                {
                    cnt=1;
                    tmpp=0;
                }
                else{
                    cnt=0;//ĩβ1
                    b[++num]=tmpp;
                }
            }
            if(ss[i]=='0')
            {
                tmpp++;
            }

        }
        for(int i=1;i<num;i++)
        {
            if(b[i]!=b[i+1])
            {
                flag=false;
                break;
            }
        }

        if(!flag) cout<<"No";

        else
        {
            int maxx=0,tmp=0;
            bool f=true;


        for(int i=1;i<=m;i++)
        {
            while(ss[i]=='0')
            {
                tmp++;
                i++;
            }
            maxx=max(tmp,maxx);
            tmp=0;
        }
        if(maxx<=n&&maxx<=b[1]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        }
    }
}
