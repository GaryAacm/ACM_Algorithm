#include<bits/stdc++.h>
using namespace std;
struct node
{
    int start,ended;
}a[1000001];
int l,r,n;
bool cmp(node x,node b)
{
    return x.start<b.start;
}

int main()
{
    cin>>l>>r;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].start>>a[i].ended;

    }
    sort(a+1,a+n+1,cmp);
    //�ҵ�����˵���С���Ǹ�
    int ans=0;
    bool k=false;
    for(int i=1;i<=n;i++)//ö��ÿ������
    {
        //�ҵ�������˵���С��
        //���Ǳ�lС
        int j=i,finall=-2e5;
        while(j<=n&&a[j].start<=l)
        {
            //���´�ʱ���Ҷ˽ڵ㣬�����ǲ��ϸ��£���������˵�������������ҵ��Ҷ�����
            finall=max(finall,a[j].ended);
            j++;
        }
        //û�н���while
        if(finall<l)
        {
            ans=-1;
            break;
        }
        ans++;
        //�ҵ�һ������
        //�����ô�����Ľ�β��Ϊ��ͷ��
        if(finall>=r)
        {
            k=true;
            break;
        }
        l=finall;
        i=j-1;//����i,�������õ�����
    }
    if(!k) cout<<-1<<endl;
    else
    {
        cout<<ans<<endl;
    }
    return 0;
}
