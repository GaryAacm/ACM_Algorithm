#include<bits/stdc++.h>
using namespace std;

int t,a,b,c;
int cnt[101];
int main()
{
    //freopen("C:\\Users\\asus\\Desktop\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&c);
        memset(cnt,0,sizeof(cnt));
        cnt[a]++;
        cnt[b]++;
        cnt[c]++;
        for(int i=0;i<=9;++i)
        {
            if(cnt[i]==1)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
}
