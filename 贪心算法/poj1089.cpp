#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

struct node
{
    int l,r;
}a[50005];
node ans[50005];//存储答案
bool cmp(node x,node y)
{
    return x.l<y.l;
}

int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].l>>a[i].r;
    }
    sort(a,a+n,cmp);
    int now=a[0].r;//记录第一个末尾区间
    //ans[0].l=a[0].l;//初始位置
    int num=0;
    for(int i=0;i<n;i++)//枚举区间
    {
        int j=i;
        ans[num].l=a[i].l;
        while(j<n&&a[j].l<=now)//可以合并,找到末尾节点
        {
            now=max(a[j].r,now);
            j++;
        }
        ans[num].r=now;
        num++;
        if(j<n) now=a[j].r;
        i=j-1;
    }
    for(int i=0;i<num;i++)
    {
        cout<<ans[i].l<<' '<<ans[i].r<<endl;
    }
    return 0;
}
