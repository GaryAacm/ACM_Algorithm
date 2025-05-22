#include<bits/stdc++.h>
using namespace std;
char a[3][3];
int t;
int cnt[3];
int pos;
int main()
{
    //freopen("C:\\Users\\asus\\Desktop\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;++j){
                //scanf("%c",&a[i][j]);
                cin>>a[i][j];
                if(a[i][j]=='?')
                {
                    pos=i;
                }

            }
        }
        //cout<<pos<<endl;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<3;i++)
        {
            if(a[pos][i]=='?') continue;
            else
            {
                if(a[pos][i]=='A') cnt[0]++;
                else if(a[pos][i]=='B') cnt[1]++;
                else cnt[2]++;
            }
        }
        if(cnt[0]==0) printf("A\n");
        else if(cnt[1]==0) printf("B\n");
        else printf("C\n");

    }
    return 0;
}
