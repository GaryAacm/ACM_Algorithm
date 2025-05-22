#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;

int t,n,m;
int a[maxn];//用于记录当前的末尾0的个数
//贪心思路，记录末尾0的个数排序，按照顺序删除

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        m++;//根据数字长度来进行比较
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            sum+=s.length();
            int k=0;
            while(s.back()=='0') k++,s.pop_back();
            a[i]=k;
        }
        sort(a+1,a+1+n);
        int f=0;//表示谁先动
        for(int i=n;i>=1;i--)//安娜先动，从大到小
        {
            if(!f)
            {
                sum-=a[i];
                f=1;
            }
            else//不删除
            {
                f=0;
            }
        }
        if(sum>=m) puts("Sasha");
        else puts("Anna");
    }
}
