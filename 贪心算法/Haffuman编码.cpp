#include <iostream>
#include <cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
double ans;
string s;
int n;
priority_queue<int,vector<int>,greater<int> > Q;
int main()
{
    while(getline(cin,s)&&s!="END")
    {

        int k=s.size();
        int t=1;
        sort(s.begin(),s.end());//要排序便于统计
        //记录原来的字节长度
        for(int i=1;i<s.length();i++)
        {
            if(s[i]!=s[i-1])
            {
                Q.push(t);
                t=1;//开启新的节点
            }
            else
            {
                t++;
            }
        }
        Q.push(t);//处理最后一个数字
        int halfman=0;
        if(Q.size()==1) halfman=Q.top();//处理特殊情况！！！
        while(Q.size()>1)
        {
            int x=Q.top();
            Q.pop();
            int y=Q.top();
            Q.pop();
            Q.push(x+y);
            halfman+=x+y;
        }
        Q.pop();
        ans=k*8.0/halfman*1.0;
        printf("%d %d %.1lf\n",k*8,halfman,ans);
    }
    return 0;
}
