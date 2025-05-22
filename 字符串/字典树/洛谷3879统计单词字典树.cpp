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
        if(!nex[now][p])         //���$Trie$����û��������ʵ�ǰ׺�ͽ��б��
			nex[now][p]=++cnt;   //������˵���ı��
        now=nex[now][p];         //��������һ�㣬�������ڵ�λ��
    }
    b[now][x]=1;                 //��������ڵ�x�г�����,������������Լ�¼λ�ã�����
}
inline void check()
{
    scanf("%s",s+1);
	int l=strlen(s+1);
    int now=0,flag=1;
    for(int i=1;i<=l;i++)
	{
        int p=s[i]-'a';
        if(!nex[now][p])         //�����Trie����û�е�ǰ���ַ����Ϳ���ֱ��break����
		{
			flag=0;
			break;
		}
        now=nex[now][p];         //����͸���λ��
    }
    if(flag)
		for(int i=1;i<=n;i++)    //������˵���ֵ������
			if(b[now][i])
				printf("%d ",i); //�������Щ�����г��ֹ�
    puts("");
}
int main()
{
    n=read();
    for(int i=1;i<=n;i++)
	{
        int x=read();
        for(int j=1;j<=x;j++)    //һ������һ�����ʵĲ���Trie����
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
int num[maxn]={0};//��ĳһ�ַ���Ϊǰ׺�ĵ�������
int pos=1;//ֻ�ܴ�1��ʼ��������ں�������һ��

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

void Insert(string str)//�ֵ����в���
{
    int p=0;
    //pos=1;
    for(int i=0;str[i];i++)
    {
        int n=getnum(str[i]);//��ʾ�����ĸ��ͷ�ĵ���
        if(tree[p][n]==0)//��û��ֵ��Ӧ�����ĸ
        {
            tree[p][n]=pos++;//ָ��ͬ�洢λ�ã������µĴ洢λ��

        }
        p=tree[p][n];//ָ����һ���洢λ�ã�����ǰ׺

        num[p]++;//�Դ˽�β������˵�Դ�Ϊǰ׺
    }
}

bool Find(string str,int len)//�����Դ�Ϊǰ׺�ĵ�������
{
    int p=0;//����
    int cntt=0;
    //cout<<cntt<<endl;
    for(int i=0;str[i];i++)//һ��һ������
    {
        int n=getnum(str[i]);
        if(tree[p][n]==0)//���ֲ����ʵ�
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
	//freopen("D:\\�㷨����\\�ַ���\\in.txt","r",stdin);
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
    for(int i=0;i<cnt;i++)//ÿһ����������ǰ׺
    {
        memset(tree,0,sizeof(tree));
        memset(num,0,sizeof(num));
        //cout<<s[i].size()<<endl;
        for(int j=0;j<s[i].size();++j)
        {
            //cout<<"string:"<<s[i][j]<<endl;
            Insert(s[i][j]);
        }
        for(int xx=0;xx<m;++xx)//�����Ƿ����
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

