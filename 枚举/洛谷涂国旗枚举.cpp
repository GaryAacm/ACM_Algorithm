#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=105;
int n,m;
char a[maxn][maxn];
int ans=1e9;
void solve(int x,int y)
{
    int sum=0;
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]!='W')
            {
                sum++;
            }
        }
    }

    for(int i=x+1;i<=x+y;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]!='B')
                sum++;
        }
    }
    for(int i=x+1+y;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]!='R')
                sum++;
        }
    }
    ans=min(ans,sum);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    //ö�ٶ����а�ɫ����������ɫ
    for(int i=1;i<n-1;i++)//��ɫ
    {
        for(int j=1;i+j<=n-1;j++)//��ɫ
        {
            solve(i,j);
        }
    }
    cout<<ans<<endl;
}
