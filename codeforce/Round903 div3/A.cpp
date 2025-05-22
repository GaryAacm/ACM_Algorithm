#include<bits/stdc++.h>
using namespace std;

int t,n,ans=0,m;
string s,x;
int main()
{
    //freopen("D:\\Ëã·¨½ø½×\\codeforce\\Round903 div3\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        cin>>n>>m>>x>>s;
        //scanf("%d%d%s%s",&n,&m,x,s);
        ans=0;
        while(1)
        {
            if((int)x.find(s)!=-1)
            {
                printf("%d\n",ans);
                break ;
            }
            x+=x;
            ++ans;
            if((int)x.size()>100)
            {
                printf("-1\n");
                break;
            }
        }

    }

    return 0;
}
