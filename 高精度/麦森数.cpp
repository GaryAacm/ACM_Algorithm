#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int base[1001],p,res[1001],tmp[1001];//乘法要开两倍长度，f是底数，res是结果，sav是高精度处理之后的res和底数，是暂时的
void result_1()
{
    memset(tmp,0,sizeof(tmp));
    for(register int i=1;i<=500;i+=1)
        for(register int j=1;j<=500;j+=1)
            tmp[i+j-1]+=res[i]*base[j];//先计算每一位上的值（不进位）

    for(register int i=1;i<=500;i+=1)
    {
        tmp[i+1]+=tmp[i]/10;//单独处理进位问题，不容易出错
        tmp[i]%=10;
    }

    memcpy(res,tmp,sizeof(res));//cstring库里的赋值函数，把sav的值赋给res
}
void result_2()//只是在result_1的基础上进行了细微的修改
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
    printf("%d\n",(int)(log10(2)*p+1));//输出位数
    res[1]=1;
    base[1]=2;//高精度赋初值

    while(p!=0)//快速幂模板
    {
        if(p%2==1) result_1();//高精度乘法，记录最后的500位
        p/=2;
        result_2();//同样高精度处理底数
    }
    res[1]-=1;
    for(register int i=500;i>=1;i-=1)//注意输出格式，50个换一行，第一个不用
        if(i!=500&&i%50==0)printf("\n%d",res[i]);
        else printf("%d",res[i]);
    return 0;
}

