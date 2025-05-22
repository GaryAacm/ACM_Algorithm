#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int cnt[15],cntlei[15];
struct node
{
    int id,num,lei;
};
node a[maxn],b[maxn],c[maxn],d[maxn];

bool cmp(node x,node y)
{
    return x.num>y.num;
}

int main()
{

    freopen("D:\\算法进阶\\codeforce\\div3_12_19\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].num);
            a[i].id=i;
            a[i].lei=1;

        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i].num);
            b[i].id=i;
            b[i].lei=2;

        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&c[i].num);
            c[i].id=i;
            c[i].lei=3;

        }
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n,cmp);
        sort(c+1,c+1+n,cmp);

        ll ans=0;
        int ord=0;
        for(int i=1;i<=3;i++)
        {
            d[++ord].num=a[i].num;
            d[ord].id=a[i].id;
            d[ord].lei=a[i].lei;
            d[++ord].num=b[i].num;
            d[ord].id=b[i].id;
            d[ord].lei=b[i].lei;
            d[++ord].num=c[i].num;
            d[ord].id=c[i].id;
            d[ord].lei=c[i].lei;

        }
        sort(d+1,d+1+ord,cmp);
        for(int i=1;i<=ord;i++)
        {
            cout<<d[i].num<<endl;
            cout<<d[i].id<<endl;
            cout<<"类别："<<d[i].lei<<endl;
        }
        memset(cnt,0,sizeof(cnt));
        memset(cntlei,0,sizeof(cntlei));
        int i=1;
        for(int j=0;j<3;j++)
        {

            cout<<"out:"<<i<<endl;
            while(1)
            {
                cout<<"id是："<<d[i].id<<' '<<"类别是："<<d[i].lei<<endl;
                if(!cnt[d[i].id]&&!cntlei[d[i].lei])
            {
                ans+=d[i].num;
                cout<<"增加了"<<endl;
                cnt[d[i].id]=1;
                cntlei[d[i].lei]=1;
                //cout<<"oooo "<<d[i].lei<<' '<<i<<endl;
                i++;
                //cout<<"ooo "<<i<<endl;
                break;
            }

            else i++;
            if(i>10) break;
            }
        }
        cout<<ans<<endl;



    }
}
