#include<bits/stdc++.h>
using namespace std;
const int maxn=150;

struct node
{
    string name,pos,newpos;
    int val,rate,id;
}a[maxn];
int n;

bool cmp1(node x,node y)//先按照帮贡排序
{
    if(x.val!=y.val)
        return x.val>y.val;
    else return x.id<y.id;
}

int change(string a)
{
	if (a=="BangZhu") return 0;
	if (a=="FuBangZhu") return 1;
	if (a=="HuFa") return 2;
	if (a=="ZhangLao") return 3;
	if (a=="TangZhu") return 4;
	if (a=="JingYing") return 5;
	if (a=="BangZhong") return 6;
}

//转化字符串为数字来进行排序
bool cmp2(node x,node y)
{
    if(change(x.newpos)==change(y.newpos))
    {
        if(x.rate!=y.rate) return x.rate>y.rate;
        return x.id<y.id;
    }

    return change(x.newpos)<change(y.newpos);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].name>>a[i].pos>>a[i].val>>a[i].rate;
        a[i].id=i;
    }
    sort(a+4,a+1+n,cmp1);
    //授予职位

    for(int i=1;i<=n;i++)
    {
        if(i==1) a[i].newpos="BangZhu";
        else if (i==2||i==3) a[i].newpos="FuBangZhu";
		else if (i==4||i==5) a[i].newpos="HuFa";
		else if (i>=6&&i<=9) a[i].newpos="ZhangLao";
		else if (i>=10&&i<=16) a[i].newpos="TangZhu";
		else if (i>=17&&i<=41) a[i].newpos="JingYing";
		else a[i].newpos="BangZhong";
    }
    sort(a+2,a+1+n,cmp2);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i].name<<' '<<a[i].newpos<<' '<<a[i].rate<<endl;
    }
    return 0;
}

