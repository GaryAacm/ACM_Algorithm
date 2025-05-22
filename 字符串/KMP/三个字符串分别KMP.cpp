/*题目连接：https://www.luogu.com.cn/problem/CF25E  */

#include <cstdio>
#include <cstring>
#define min(a,b) ((a)<(b))?(a):(b)
using namespace std;
const int INF=2147483646;
int nxt[4][100050],l[4];
char s[4][100050];
inline void Pre(){
    for(int f=1;f<4;++f){//求出三个字符串的next数组
        int p=0,len=l[f];
        for(int i=2;i<=len;++i){
            while(p&&s[f][i]!=s[f][p+1]) p=nxt[f][p];//f做好标记
            if(s[f][i]==s[f][p+1]) ++p;
            nxt[f][i]=p;
        }
    }
    return ;
}


int solve(int a,int b,int c){
    int ans=INF,p1=0;
    int al=l[a],bl=l[b],cl=l[c];
    for(int i=1;i<=al;++i){
        while(p1&&s[b][p1+1]!=s[a][i]) p1=nxt[b][p1];//匹配失败
        if(s[b][p1+1]==s[a][i]) ++p1;//匹配上的长度
        if(p1==bl){
            p1=-1;//-1代表b是a的子串
            break;
        }
    }
    if(p1==-1){//如果b是a的子串，就直接让c和a匹配

        int p=0;
        for(int i=1;i<=al;++i){
            while(p&&s[c][p+1]!=s[a][i]) p=nxt[c][p];
            if(s[c][p+1]==s[a][i]) ++p;
            if(p==cl){
                p=-1;
                break;
            }
        }
        if(p==-1) ans=al;
        else ans=al+cl-p;
    }
    else{
    	//否则，先用c匹配a再从a，b相交位置开始匹配b
        int p=0;
        for(int i=1;i<=al;++i){
            while(p&&s[c][p+1]!=s[a][i]) p=nxt[c][p];
            if(s[c][p+1]==s[a][i]) ++p;
            if(p==cl){
                p=-1;
                break;
            }
        }
        if(p!=-1){
            int p2=p;
            for(int i=p1+1;i<=bl;++i){
                while(p2&&s[c][p2+1]!=s[b][i]) p2=nxt[c][p2];
                if(s[c][p2+1]==s[b][i]) ++p2;
                if(p2==cl){
                    p2=-1;
                    break;
                }
            }
            if(p2==-1) ans=al+bl-p1;
            else ans=al+bl-p1 + cl -p2;//减去三者的公共长度
        }
        else ans=al+bl-p1;
    }
    return ans;
}


int main(){
    scanf("%s%s%s",s[1]+1,s[2]+1,s[3]+1);
    int ans=INF;
    l[1]=strlen(s[1]+1);l[2]=strlen(s[2]+1);l[3]=strlen(s[3]+1);
    Pre();
    ans=min(ans,solve(1,2,3));ans=min(ans,solve(1,3,2));
    ans=min(ans,solve(2,1,3));ans=min(ans,solve(2,3,1));
    ans=min(ans,solve(3,2,1));ans=min(ans,solve(3,1,2));

    printf("%d\n",ans);
    return 0;
}
