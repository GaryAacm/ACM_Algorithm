#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("D:\\算法进阶\\字符串\\in.txt","r",stdin);
    char str[11];
    map<string,int> m;
    while(gets(str))
    {
        int len=strlen(str);
        if(!len) break;//空行
        for(int i=len;i>0;i--)
        {
            str[i]='\0';//先清空后面的
            m[str]++;//统计前缀出现的次数
        }
    }

    while(gets(str)) cout<<m[str]<<endl;

    return 0;
}
