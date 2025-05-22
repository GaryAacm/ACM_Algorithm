#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
int tree[maxn][65];
int num[maxn]={0};//以某一字符串为前缀的单词数量
int pos=1;//只能从1开始，否则就在后面会忽视一个
int bo[maxn];
int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
}
int m,n,q;
char str[maxn];

void Insert(string str)//字典树中插入
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int n=getnum(str[i]);//表示这个字母开头的单词,n是指向特定的字符
        if(tree[p][n]==0)//还没有值对应这个字母
        {
            tree[p][n]=pos++;//指向不同存储位置，开辟新的存储位置

        }
        p=tree[p][n];//指向下一个存储位置，查找前缀

        num[p]++;//以此结尾，或者说以此为前缀
    }
    bo[p]++;//结尾的字符，表示以这个结尾的字符
}



int Find(string str)//返回以此为前缀的单词数量
{
    int p=0;//索引
    int res=0;
    for(int i=0;str[i];i++)//一个一个遍历
    {
        int n=getnum(str[i]);
        if(tree[p][n]==0)//出现不合适的
            return res;//统计前缀相同的个数
        p=tree[p][n];
        res+=bo[p];
    }

    return res+num[p]-bo[p];//处理字符串长度中间的以及匹配完成的 11匹配1 and 110 ，加上前缀和当前匹配上的，只不过当前匹配上的减去bo[p]避免重复算，bo包括在num里面
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("D:\\算法进阶\\字符串\\in.txt","r",stdin);
	cin>>n>>m;

	for(int i=1;i<=n;++i)
    {
        int tot,temp;
        string sa="";
        cin>>tot;
        for(int j=0;j<tot;j++)
        {
            cin>>temp;
            sa+=temp+'0';
        }
        Insert(sa);
    }
    for(int i=0;i<m;++i)
    {
        int tot,temp;
        cin>>tot;
        string sa;
        for(int j=0;j<tot;j++)
        {
            cin>>temp;
            sa+=temp+'0';
        }
        cout<<Find(sa)<<endl;
    }

    return 0;

}
