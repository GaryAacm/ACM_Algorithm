#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int base[1001],p,res[1001],tmp[1001];//�˷�Ҫ���������ȣ�f�ǵ�����res�ǽ����sav�Ǹ߾��ȴ���֮���res�͵���������ʱ��
void result_1()
{
    memset(tmp,0,sizeof(tmp));
    for(register int i=1;i<=500;i+=1)
        for(register int j=1;j<=500;j+=1)
            tmp[i+j-1]+=res[i]*base[j];//�ȼ���ÿһλ�ϵ�ֵ������λ��

    for(register int i=1;i<=500;i+=1)
    {
        tmp[i+1]+=tmp[i]/10;//���������λ���⣬�����׳���
        tmp[i]%=10;
    }

    memcpy(res,tmp,sizeof(res));//cstring����ĸ�ֵ��������sav��ֵ����res
}
void result_2()//ֻ����result_1�Ļ����Ͻ�����ϸ΢���޸�
{
    memset(tmp,0,sizeof(tmp));
    for(register int i=1;i<=500;i+=1)
        for(register int j=1;j<=500;j+=1)
            tmp[i+j-1]+=base[i]*base[j];
    for(register int i=1;i<=500;i+=1)
    {
        tmp[i+1]+=tmp[i]/10;
        tmp[i]%=10;
    }
    memcpy(base,tmp,sizeof(base));
}
int main()
{
    scanf("%d",&p);
    printf("%d\n",(int)(log10(2)*p+1));//���λ��
    res[1]=1;
    base[1]=2;//�߾��ȸ���ֵ

    while(p!=0)//������ģ��
    {
        if(p%2==1) result_1();//�߾��ȳ˷�����¼����500λ
        p/=2;
        result_2();//ͬ���߾��ȴ������
    }
    res[1]-=1;
    for(register int i=500;i>=1;i-=1)//ע�������ʽ��50����һ�У���һ������
        if(i!=500&&i%50==0)printf("\n%d",res[i]);
        else printf("%d",res[i]);
    return 0;
}

