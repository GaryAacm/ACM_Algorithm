#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n;
int tmp=2147483647;
int a[maxn],b[maxn];
//首先发现最多两个一组而且数位不一样，所以用1<<30-1来异或找到另外的数
//接下来是技巧问题，用map记录每个数出现次数，再找回对应出现的那个数的次数
//两个数异或之后得到int的最大值，记录每个值，找到可以匹配的值，一一对应的
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //cout<<(1<<31)-1<<endl;
    cin>>t;
    while(t--)
    {
        cin>>n;
        map<int,int> mapp;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mapp[a[i]]++;//记录这个值出现的次数
        }
        int all=n;
        int ans=0;
        for(auto &[x,y]:mapp)
        {
            int w=tmp^x;//找到对应的值
            int y1=y,y2=mapp[w];//y2是这个对应的值出现的次数,y1是这个值本身出现的次数
            int y3=min(y1,y2);
            all-=2*y3;//同时减少
            ans+=y3;
            mapp[w]-=y3;
            mapp[x]-=y3;
        }
        ans+=all;//剩下的自己一个一组
        cout<<ans<<endl;
    }
}
