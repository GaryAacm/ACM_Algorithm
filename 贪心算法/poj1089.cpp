#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

struct node
{
    int l,r;
}a[50005];
node ans[50005];//�洢��
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
    int now=a[0].r;//��¼��һ��ĩβ����
    //ans[0].l=a[0].l;//��ʼλ��
    int num=0;
    for(int i=0;i<n;i++)//ö������
    {
        int j=i;
        ans[num].l=a[i].l;
        while(j<n&&a[j].l<=now)//���Ժϲ�,�ҵ�ĩβ�ڵ�
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
