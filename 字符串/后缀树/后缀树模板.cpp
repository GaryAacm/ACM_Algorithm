#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
char s[maxn];
int sa[maxn],rk[maxn],tmp[maxn+1];
int n,k;

bool comp_sa(int i,int j)//�ж��������С
{
    if(rk[i]!=rk[j])
    {
        return rk[i]<rk[j];
    }
    else
    {
        int ri=i+k<=n?rk[i+k]:-1;//��λ��Ⱥ�Ƚ�i+k��j+k
        int rj=j+k<=n?rk[j+k]:-1;
        return ri<rj;
    }
}

void calc_sa()//�����׺����
{
    for(int i=0;i<=n;i++)
    {
        rk[i]=s[i];//�����ֵ
        sa[i]=i;//��׺���鸳ֵ
    }

    for(k=1;k<=n;k=k*2)//�����������У�k����������Ƚϼ�λ
    {
        sort(sa,sa+n,comp_sa);//��sa��¼��������sa��������
        tmp[sa[0]]=0;
        for(int i=0;i<n;i++)//sa�������������������tmp���渳ֵ��rk
            {
                tmp[sa[i+1]]=tmp[sa[i]]+(comp_sa(sa[i],sa[i+1])?1:0);

            }
        for(int i=0;i<n;i++)
        {
            rk[i]=tmp[i];
        }
    }
}

int main()
{
    while(scanf("%s",s)!=EOF)
    {
        n=strlen(s);
        calc_sa();
        for(int i=0;i<n;i++)
            cout<<sa[i]<<endl;
    }

    return 0;
}

