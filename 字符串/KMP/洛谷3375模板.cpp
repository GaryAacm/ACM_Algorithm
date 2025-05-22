#include<bits/stdc++.h>
using namespace std;

const int maxn=1000010;
char str[maxn],pattern[maxn];
int Next[maxn],cnt;

void getFail(char *p,int plen)//�õ�next����
{
    Next[0]=0;
    Next[1]=0;
    int j=0;
    for(int i=1;i<plen;i++)
    {
        j=Next[i];//�̳�ǰ���
        while(j&&p[i]!=p[j]) j=Next[j];
        Next[i+1]=(p[i]==p[j])?j+1:0;//�ܹ�������Ⱦͼ�һ
    }
}


void kmp(char *s,char *p)
{
    int last=-1;
    int slen=strlen(s),plen=strlen(p);
    getFail(p,plen);
    int j=0;

    for(int i=0;i<slen;i++)//��ʼƥ��
    {
        while(j&&p[j]!=s[i]) j=Next[j];//ʧ��
        if(s[i]==p[j]) j++;//����ƥ��
        if(j==plen)//ƥ��ɹ�
        {
            printf("%d\n",i+2-plen);
        }
    }
    for(int i=1;i<=strlen(p);i++)
    {
        printf("%d ",Next[i]);
    }
}

int main()
{
    //freopen("D:\\�㷨����\\�ַ���\\KMP\\in.txt","r",stdin);
    scanf("%s",str);
    scanf("%s",pattern);
    kmp(str,pattern);

    return 0;
}

