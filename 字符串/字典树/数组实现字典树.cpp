#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int tree[maxn][26];
int num[maxn]={0};//以某一字符串为前缀的单词数量
int pos=1;
//新分配的存储位置

void Insert(char str[])//字典树中插入
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int n=str[i]-'a';//表示这个字母开头的单词
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
        int n=str[i]-'a';
        if(tree[p][n]==0)//出现不合适的
            return 0;
        p=tree[p][n];
    }

    return num[p];
}
