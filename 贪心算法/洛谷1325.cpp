#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

//ת��Ϊ�������⣬��������ѡ��

struct node
{
    double left,right;
}s[1010];

bool cmp(node x,node y)
{
    return x.left<y.left;
}

int n,d,t=0;

int solve()
{
    int ans;
    double now;//��¼��ǰ���Ҷ˵�
    ans=1;
    //ѡȡһ����
    sort(s+1,s+1+n,cmp);
    now=s[1].right;
    for(int i=2;i<=n;i++)
    {
        if(s[i].left>now)
        {
            ans++;//�½��ڵ�
            now=s[i].right;//����
        }
        else
        {
            now=min(now,s[i].right);//����Ҫȡ��С���Ǹ��Ҷ˵㣬��֤���串��
        }
    }
    return ans;
}

int main()
{

        cin>>n>>d;
        bool flag=true;
        if(n==0&&d==0) flag=false;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            if(y>d) flag=false;//�������ı��
            else
            {
                s[i].left=x - sqrt((double)d*d-y*y);//ת��Ϊ��������
                s[i].right=x + sqrt((double)d*d-y*y);//�ѵ��쿴�ɵ㣬��Բ����x��

            }

        }
        if(flag) printf("%d\n",solve());
        else
            printf("-1\n");
    return 0;
}
