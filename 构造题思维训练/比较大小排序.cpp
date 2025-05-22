/*排序之后处理前缀，相当于大鱼吃小鱼，不断吃掉小小的，看最后能吃多少*/
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0;bool w=0;char ch=getchar();
    while((ch<'0'||ch>'9')&&(ch^45)&&(ch^-1)) ch=getchar();
    (!(ch^45)&&(w=1,(ch=getchar())));
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return w&&(x=-x),x;
}
inline void write(int x,char l='\n'){
    if(!x){putchar('0');putchar(l);return;}
    int cnt=0;
    static char ch[55];
    ((x<0)&&(putchar('-'),(x=-x)));
    while(x) ch[++cnt]=x%10+48,x/=10;
    while(putchar(ch[cnt]),--cnt);
    putchar(l);
}
using ll=long long;
using pii=pair<int,int>;
#define pb push_back
void solve(){
	int n=read();
	vector<pii> a(n+1);
	vector<ll> p(n+1);
	vector<int> ans(n+1);
	int l=0;
	for(int i=1;i<=n;i++) a[i]={read(),i};//可以结构体替代
	sort(begin(a)+1,end(a));
	p[0]=0;
	for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i].first;
	for(int i=1;i<=n;i++){
		if(l<i){
			l=i;
			while(p[l]>=a[l+1].first&&l<n) l++;//递增和的极限
		}
		ans[a[i].second]=l;
	}
	for(int i=1;i<=n;i++) write(ans[i]-1,' ');
	putchar('\n');
}
int main(){
	int t=1;
	t=read();
	while(t--) solve();
}
