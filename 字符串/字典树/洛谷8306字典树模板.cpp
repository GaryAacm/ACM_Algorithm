#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
int tree[maxn][65];
int num[maxn]={0};//��ĳһ�ַ���Ϊǰ׺�ĵ�������
int pos=1;//ֻ�ܴ�1��ʼ��������ں�������һ��
int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
}
int t,n,q;
char str[maxn];

void Insert(char str[])//�ֵ����в���
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int n=getnum(str[i]);//��ʾ�����ĸ��ͷ�ĵ���
        if(tree[p][n]==0)//��û��ֵ��Ӧ�����ĸ
        {
            tree[p][n]=pos++;//ָ��ͬ�洢λ�ã������µĴ洢λ��

        }
        p=tree[p][n];//ָ����һ���洢λ�ã�����ǰ׺

        num[p]++;//�Դ˽�β������˵�Դ�Ϊǰ׺
    }
}

int Find(char str[])//�����Դ�Ϊǰ׺�ĵ�������
{
    int p=0;//����
    for(int i=0;str[i];i++)//һ��һ������
    {
        int n=getnum(str[i]);
        if(tree[p][n]==0)//���ֲ����ʵ�
            return 0;
        p=tree[p][n];
    }

    return num[p];
}


int main()
{
    //freopen("D:\\�㷨����\\�ַ���\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<=pos;i++)
            for(int j=0;j<=122;j++)
                tree[i][j]=0;
        for(int i=0;i<=pos;i++)
            num[i]=0;
        scanf("%d%d",&n,&q);
        pos=1;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            Insert(str);
        }
        for(int i=0;i<q;i++)
        {
            scanf("%s",str);
            printf("%d\n",Find(str));
        }
    }

    return 0;
}
