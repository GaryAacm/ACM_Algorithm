#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
const int N=4e5+10;
int n;
pii a[N];
int b[N]; int tr[N];

int lowbit(int x)
{
	return x&-x;
}
void add(int x)
{
	for(int i=x;i>=1;i-=lowbit(i))
        tr[i]++;
}
int query(int x){
	int res=0;
	for(int i=x;i<=2*n;i+=lowbit(i))
        res+=tr[i];
	return res;
}
void work(){
	cin>>n; int num=0;
	for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y,b[++num]=a[i].y,b[++num]=a[i].x;
	sort(b+1,b+num+1);
	for(int i=1;i<=n;i++)
        a[i].y=lower_bound(b+1,b+num+1,a[i].y)-b,a[i].x=lower_bound(b+1,b+num+1,a[i].x)-b;

	sort(a+1,a+n+1); int cnt=0;
	//ÀëÉ¢»¯²Ù×÷
	for(int i=1;i<=n;i++){
		cnt+=query(a[i].y);
		add(a[i].y);
	} cout<<cnt<<endl;
	for(int i=1;i<=2*n;i++) tr[i]=0;
}
signed main(){
	int T; scanf("%lld",&T);
	while(T--) work(); return 0;
}

/*//Writer: HugeWide
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')
#define writekk(x,c) write(x),putchar(" \n"[c])

#define rep(x,l,r) for(int x=l;x<=r;x++)
#define per(x,r,l) for(int x=r;x>=l;x--)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

const int N=200200;

int n;
int a[N],b[N];

int raw[N],m=0;
pair<int,int> p[N];

int c[N];
int lowbit(int x) {
	return x&-x;
}
void change(int x,int k) {
	while(x<=n) {
		c[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x) {
	int r=0; while(x) {
		r+=c[x];
		x-=lowbit(x);
	} return r;
}
void init() {
	rep(i,1,n) c[i]=0;
}

int main() {
	int t=read(); while(t--) {
		n=read(); rep(i,1,n) a[i]=read(),b[i]=read();
		m=0; rep(i,1,n) raw[++m]=b[i];
		sort(raw+1,raw+m+1),m=unique(raw+1,raw+m+1)-raw-1;
//		cout<<' '<<m<<'\n';
		rep(i,1,n) b[i]=lower_bound(raw+1,raw+m+1,b[i])-raw;
		rep(i,1,n) p[i]=mp(a[i],b[i]);
		sort(p+1,p+n+1); init();
		ll ans=0;
		per(i,n,1) {
//			cout<<i<<' '<<ans<<','<<p[i].first<<' '<<p[i].second<<'\n';
			ans+=query(p[i].second);
			change(p[i].second,1);
		}
		writeln(ans);
	}
	return 0;
}

*/

