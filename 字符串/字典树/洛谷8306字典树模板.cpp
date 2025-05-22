#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
int tree[maxn][65];
int num[maxn]={0};//以某一字符串为前缀的单词数量
int pos=1;//只能从1开始，否则就在后面会忽视一个
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

void Insert(char str[])//字典树中插入
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int n=getnum(str[i]);//表示这个字母开头的单词
        if(tree[p][n]==0)//还没有值对应这个字母
        {
            tree[p][n]=pos++;//指向不同存储位置，开辟新的存储位置

        }
        p=tree[p][n];//指向下一个存储位置，查找前缀

        num[p]++;//以此结尾，或者说以此为前缀
    }
}

int Find(char str[])//返回以此为前缀的单词数量
{
    int p=0;//索引
    for(int i=0;str[i];i++)//一个一个遍历
    {
        int n=getnum(str[i]);
        if(tree[p][n]==0)//出现不合适的
            return 0;
        p=tree[p][n];
    }

    return num[p];
}


int main()
{
    //freopen("D:\\算法进阶\\字符串\\in.txt","r",stdin);
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
