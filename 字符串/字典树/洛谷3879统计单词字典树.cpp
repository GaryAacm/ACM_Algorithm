#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
char s[10010];
int nex[500010][26],n,cnt=0;
bool b[500010][110];
inline int read()
{
    int k=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
    while(ch>='0'&&ch<='9')
	{
		k=k*10+ch-'0';
		ch=getchar();
	}
    return k*f;
}


inline void insert(int x)
{
    scanf("%s",s+1);
	int l=strlen(s+1);
    int now=0;
    for(int i=1;i<=l;i++)
	{
        int p=s[i]-'a';
        if(!nex[now][p])         //如果$Trie$树中没有这个单词的前缀就进行编号
			nex[now][p]=++cnt;   //上文中说到的编号
        now=nex[now][p];         //接着深入一层，更新现在的位置
    }
    b[now][x]=1;                 //这个单词在第x行出现了,这里的做法可以记录位置！！！
}
inline void check()
{
    scanf("%s",s+1);
	int l=strlen(s+1);
    int now=0,flag=1;
    for(int i=1;i<=l;i++)
	{
        int p=s[i]-'a';
        if(!nex[now][p])         //如果在Trie树中没有当前的字符，就可以直接break掉了
		{
			flag=0;
			break;
		}
        now=nex[now][p];         //否则就更新位置
    }
    if(flag)
		for(int i=1;i<=n;i++)    //题面上说按字典序输出
			if(b[now][i])
				printf("%d ",i); //输出在哪些句子中出现过
    puts("");
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
	{
        int x=read();
        for(int j=1;j<=x;j++)    //一个单词一个单词的插入Trie树里
			insert(i);
    }
    int m=read();
    for(int i=1;i<=m;i++)
		check();
    return 0;
}



/*#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

int tree[maxn][65];
int num[maxn]={0};//以某一字符串为前缀的单词数量
int pos=1;//只能从1开始，否则就在后面会忽视一个

vector<string> s[maxn];
string ss[maxn];
vector<int> ans[maxn];


int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
}
int t,n,l,m;
//char str[maxn];

void Insert(string str)//字典树中插入
{
    int p=0;
    //pos=1;
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

bool Find(string str,int len)//返回以此为前缀的单词数量
{
    int p=0;//索引
    int cntt=0;
    //cout<<cntt<<endl;
    for(int i=0;str[i];i++)//一个一个遍历
    {
        int n=getnum(str[i]);
        if(tree[p][n]==0)//出现不合适的
        {
            //cout<<"can not find"<<endl;
            return false;
        }
        p=tree[p][n];
        cntt++;
        //cout<<cntt<<endl;
    }

    return (num[p]&&cntt==len);
}

int main()
{
    ios::sync_with_stdio(0);

	cin.tie(0);
	//freopen("D:\\算法进阶\\字符串\\in.txt","r",stdin);
	cin>>n;

	int cnt=0;
	while(n--)
    {
        cin>>l;
        pos=1;
        for(int i=0;i<l;i++)
        {
            string sa;
            //cout<<1<<endl;
            cin>>sa;
            //cout<<sa<<endl;
            s[cnt].push_back(sa);
            //cout<<1<<endl;
        }
        cnt++;
    }
    //cout<<"cnt:"<<cnt<<endl;
    //cout<<s[1][1]<<endl;
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>ss[i];
    for(int i=0;i<cnt;i++)//每一颗树建树算前缀
    {
        memset(tree,0,sizeof(tree));
        memset(num,0,sizeof(num));
        //cout<<s[i].size()<<endl;
        for(int j=0;j<s[i].size();++j)
        {
            //cout<<"string:"<<s[i][j]<<endl;
            Insert(s[i][j]);
        }
        for(int xx=0;xx<m;++xx)//查找是否存在
        {
            int len=ss[xx].length();
            //cout<<len<<endl;
            if(Find(ss[xx],len))
            {
                //cout<<"in "<<endl;
                ans[xx].push_back(i);
            }

        }
    }
    for(int i=0;i<m;i++)
    {
        //cout<<ans[i].size()<<endl;
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]+1<<' ';
        cout<<endl;
    }

    return 0;
}*/

