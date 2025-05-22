#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=1003;
int n,w,h;
char a[maxn][maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>h>>w>>n;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            a[i][j]='.';
        }
    }
    int u=0,v=0;//初始方位
    int dis=1;//1是上，2是下，3是左，4是右
    for(int i=1;i<=n;i++)
    {
        if(a[u][v]=='.')
        {
            a[u][v]='#';
            //cout<<u<<' '<<v<<endl;
            if(dis==1) dis=4;
            else if(dis==2) dis=3;
            else if(dis==3) dis=1;
            else dis=2;

            if(dis==1) u=(u-1+h)%h;
            else if(dis==2) u=(u+1+h)%h;
            else if(dis==3) v=(v-1+w)%w;
            else v=(v+1+w)%w;;
            //cout<<u<<' '<<v<<endl;
            //cout<<1<<endl;
        }
        else
        {
            a[u][v]='.';
            //cout<<u<<' '<<v<<endl;
            if(dis==1) dis=3;
            else if(dis==2) dis=4;
            else if(dis==3) dis=2;
            else dis=1;

            if(dis==1) u=(u-1+h)%h;
            else if(dis==2) u=(u+1+h)%h;
            else if(dis==3) v=(v-1+w)%w;
            else v=(v+w+1)%w;
            //cout<<u<<' '<<v<<endl;
        }
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
