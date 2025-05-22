#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
int tree[maxn][65];

map<string,int> pan;
bool istrue[maxn];
int num[maxn]={0};//以某一字符串为前缀的单词数量
int pos=1;//只能从1开始，否则就在后面会忽视一个
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

       // num[p]++;//以此结尾，或者说以此为前缀
    }
    istrue[p]=true;//记录以此结尾
}

bool Find(char str[])//是否找到这个单词
{
    int p=0;//索引
    int i;

    for(i=0;str[i];i++)//一个一个遍历
    {
        int n=getnum(str[i]);
        if(tree[p][n]==0)//出现不合适的
            return false;
        p=tree[p][n];
    }
    //if(i==strlen(str)) return true;
    return istrue[p];


}


int main()
{
    //freopen("D:\\算法进阶\\字符串\\in.txt","r",stdin);
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

