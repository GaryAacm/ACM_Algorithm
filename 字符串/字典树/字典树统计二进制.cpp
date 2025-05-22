#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
int tree[maxn][65];
int num[maxn]={0};//��ĳһ�ַ���Ϊǰ׺�ĵ�������
int pos=1;//ֻ�ܴ�1��ʼ��������ں�������һ��
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

void Insert(string str)//�ֵ����в���
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int n=getnum(str[i]);//��ʾ�����ĸ��ͷ�ĵ���,n��ָ���ض����ַ�
        if(tree[p][n]==0)//��û��ֵ��Ӧ�����ĸ
        {
            tree[p][n]=pos++;//ָ��ͬ�洢λ�ã������µĴ洢λ��

        }
        p=tree[p][n];//ָ����һ���洢λ�ã�����ǰ׺

        num[p]++;//�Դ˽�β������˵�Դ�Ϊǰ׺
    }
    bo[p]++;//��β���ַ�����ʾ�������β���ַ�
}



int Find(string str)//�����Դ�Ϊǰ׺�ĵ�������
{
    int p=0;//����
    int res=0;
    for(int i=0;str[i];i++)//һ��һ������
    {
        int n=getnum(str[i]);
        if(tree[p][n]==0)//���ֲ����ʵ�
            return res;//ͳ��ǰ׺��ͬ�ĸ���
        p=tree[p][n];
        res+=bo[p];
    }

    return res+num[p]-bo[p];//�����ַ��������м���Լ�ƥ����ɵ� 11ƥ��1 and 110 ������ǰ׺�͵�ǰƥ���ϵģ�ֻ������ǰƥ���ϵļ�ȥbo[p]�����ظ��㣬bo������num����
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

	//freopen("D:\\�㷨����\\�ַ���\\in.txt","r",stdin);
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
