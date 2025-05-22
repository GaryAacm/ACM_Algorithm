#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
int tree[maxn][65];

map<string,int> pan;
bool istrue[maxn];
int num[maxn]={0};//��ĳһ�ַ���Ϊǰ׺�ĵ�������
int pos=1;//ֻ�ܴ�1��ʼ��������ں�������һ��
int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a';
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

       // num[p]++;//�Դ˽�β������˵�Դ�Ϊǰ׺
    }
    istrue[p]=true;//��¼�Դ˽�β
}

bool Find(char str[])//�Ƿ��ҵ��������
{
    int p=0;//����
    int i;

    for(i=0;str[i];i++)//һ��һ������
    {
        int n=getnum(str[i]);
        if(tree[p][n]==0)//���ֲ����ʵ�
            return false;
        p=tree[p][n];
    }
    //if(i==strlen(str)) return true;
    return istrue[p];


}


int main()
{
    //freopen("D:\\�㷨����\\�ַ���\\in.txt","r",stdin);
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%s",str);
        Insert(str);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        scanf("%s",str);

        if(!Find(str)) printf("WRONG\n");
        else
        {
            if(!pan[str])
            {
                printf("OK\n");
                pan[str]=1;
            }
            else
            {
                printf("REPEAT\n");
            }
        }
    }

    return 0;
}

