/*观察到就是通过第一个图形可以转化为n个图形，所以考虑由第一个图形推导而来*/
#include<iostream>
#include<math.h>
using namespace std;
char mp[1030][2050];   //存储答案
int n;
void dr(int x,int y,int deep){        //x,y表示图形的第一个“/”的坐标
//deep表示所需图形的大小
    if(deep==1){                 //画出n=1的基本图形
        mp[x][y]='/';
        mp[x][y+1]='\\';
        mp[x+1][y-1]='/';
        mp[x+1][y]='_';
        mp[x+1][y+1]='_';
        mp[x+1][y+2]='\\';
        return;
    }
    dr(x,y,deep-1);//第一次递归是在最上层                       //递归分别画三个部分
    dr(x+pow(2,deep-1),y-pow(2,deep-1),deep-1);//往下一层左移
    dr(x+pow(2,deep-1),y+pow(2,deep-1),deep-1);//往下一层右移
}
int main(){
    cin>>n;
    //初始化
    for(int i=1;i<=pow(2,n);i++)
    {
        for(int j=1;j<=pow(2,n+1);j++)
            mp[i][j]=' ';
    }
    dr(1,pow(2,n),n);
    for(int i=1;i<=pow(2,n);i++){               //输出
        for(int j=1;j<=pow(2,n+1);j++)
        cout<<mp[i][j];
        cout<<endl;
    }
}
