//双向广搜，从终点和起点开始搜索，搜到相同的状态就退出即可
//定义中间状态
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>//用于哈希操作
#include<queue>
using namespace std;
#define l first
#define r second
int sum=0;
const int N=5;

char g[N][N];

unordered_map<string,pair<char,string> >apre,bpre;//记录操作路径

unordered_map<string,int> da,db;//起点和终点到到点的距离,记录对方有没有搜到过

string middle;//中间状态

void sett(string s)//字符串转化为二维数组
{
    int k=0;
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;j++)
            g[i][j]=s[k++];
    }
}

string get()//二维数组转化为字符串
{
    string res;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            res+=g[i][j];
        }
    }
    return res;
}

string change1(string s)
{

    sett(s);

    int x,y;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(g[i][j]=='0'&&i==0)
                return "no";
            else if(g[i][j]=='0'&&i!=0)
            {
                x=i;y=j;

            }


        }
    }
    swap(g[x][y],g[x-1][y]);
    return get();
}

string change2(string s)
{
    sett(s);

    int x,y;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(g[i][j]=='0'&&i==2)
                return "no";
            else if(g[i][j]=='0'&&i!=2)
            {
                x=i;y=j;

            }

        }
    }
    swap(g[x][y],g[x+1][y]);
    return get();
}

string change3(string s)
{
    sett(s);

    int x,y;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(g[i][j]=='0'&&j==0)
                return "no";
            else if(g[i][j]=='0'&&j!=0)
            {
                x=i;y=j;

            }
        }
    }
    swap(g[x][y],g[x][y-1]);
    return get();
}

string change4(string s)
{
    sett(s);

    int x,y;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(g[i][j]=='0'&&j==2)
                return "no";
            else if(g[i][j]=='0'&&j!=2)
            {
                x=i;y=j;

            }

        }
    }
    swap(g[x][y],g[x][y+1]);
    return get();
}


int extrend(queue<string>&q,int judge)
{
    for(int i=0;i<q.size();i++)
    {
        string t=q.front();

        q.pop();
        string state[5];

        int is[5]={};//判断操作是否合理

        if(change1(t)!="no")
        {
            state[1]=change1(t);
        }
        else
        {
            is[1]=1;
        }
        if(change2(t)!="no")
        {
            state[2]=change2(t);
        }
        else
        {
            is[2]=1;
        }
        if(change3(t)!="no")
        {
            state[3]=change3(t);
        }
        else
        {
            is[3]=1;
        }
        if(change4(t)!="no")
        {
            state[4]=change4(t);
        }
        else
        {
            is[4]=1;
        }

        if(judge==0)
        {
            for(int j=1;j<=4;j++)
            {
                if(da[state[j]]==0&&is[j]==0)
                {
                    da[state[j]]=da[t]+1;

                    if(j==1) apre[state[j]]={'u',t};
                    if(j==2) apre[state[j]]={'d',t};
                    if(j==3) apre[state[j]]={'l',t};
                    if(j==4) apre[state[j]]={'r',t};

                    if(db[state[j]]!=0)//被搜过是中间状态
                    {
                        middle=state[j];

                        return db[state[j]];

                    }
                    q.push(state[j]);

                }
            }
        }
        else
        {
            for(int j=1;j<=4;j++)
            {
                if(db[state[j]]==0&&is[j]==0)
                {
                    db[state[j]]=db[t]+1;

                    if(j==1) bpre[state[j]]={'u',t};
                    if(j==2) bpre[state[j]]={'d',t};
                    if(j==3) bpre[state[j]]={'l',t};
                    if(j==4) bpre[state[j]]={'r',t};

                    if(da[state[j]]!=0)//被搜过是中间状态
                    {
                        middle=state[j];

                        return da[state[j]];

                    }
                    q.push(state[j]);

                }
            }
        }

    }
    return -1;
}

int bfs(string A,string B)
{
    queue<string> q1;
    queue<string> q2;
    q1.push(A);
    da[A]=0;
    q2.push(B);
    db[B]=0;
    while(q1.size()&&q2.size())
    {
        int t,judge;
        //挨个搜索

        if(sum>=10000) return -1;

        if(q1.size()<=q2.size())
        {
            judge=0;

            //搜A

            t=extrend(q1,judge);

            sum+=q1.size();
        }
        else
        {
            judge=1;

            t=extrend(q2,judge);

            sum+=q2.size();
        }
        if(t!=-1)
            return t;
    }
    return -1;
}



int main()
{
    string A,B;
    A="123804765";//A是初始状态，B是最终的结果
    cin>>B;
    //B[8]='x';
    if(A==B) cout<<0<<endl;
    else
    {
        int ans=bfs(A,B);
    if(ans==-1)
    {
        printf("unsolvable");
    }
    else
    {
        string res1,res2;

        string copy=middle;

        while(middle!=A)
        {
            res1+=apre[middle].l;

            middle=apre[middle].r;//更新middle
        }
        reverse(res1.begin(),res1.end());

        middle=copy;//还原状态

        while(middle!=B)
        {
            char temp=bpre[middle].l;
            if(temp=='u'||temp=='d')
                temp='u'+'d'-temp;
            else
                temp='l'+'r'-temp;
            res2+=temp;
            middle=bpre[middle].r;
        }
        string ss=res1+res2;
        cout<<ss.length()<<endl;
    }
    }
    return 0;
}
