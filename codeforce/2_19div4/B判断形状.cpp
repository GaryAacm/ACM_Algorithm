#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
char a[15][15];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int pos1=0,pos2=0;
        bool f=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='1'&&!f)
                {
                    f=true;
                    pos1=i;
                    pos2=j;
                }
            }
        }
        int tot1=1;
        for(int i=pos2+1;i<=n;i++)
        {
            if(a[pos1][i]=='1') tot1++;
        }
        int tot2=0;
        for(int i=1;i<=n;i++)
        {
            if(a[pos1+1][i]=='1') tot2++;

        }
        if(tot1==tot2) cout<<"SQUARE"<<'\n';
        else cout<<"TRIANGLE"<<'\n';

    }
}
