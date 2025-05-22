#include<iostream>
typedef long long ll;
using namespace std;
const long long mod=19260817;

//下面是高精度读入大量数据的问题，一边读入一边取模
long long read() {
	long long ans=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ans=(ans*10+c-'0')%mod,c=getchar();
	return ans;
}
ll x,y,a,b;
ll ans;
ll x1,y11;
ll extend_gcd(ll a,ll b,ll &x1,ll &y11)//得到的x1和y11为一组特解
{
    if(b==0)
    {
        x1=1;
        y11=0;
        return a;//表示递归到最后，返回
    }

    ans=extend_gcd(b,a%b,x1,y11);
    ll temp=x1;
    x1=y11;
    y11=temp-(a/b)*y11;
    return ans;
}

int main()
{
    a=read();
    b=read();
    extend_gcd(b,mod,x1,y11);
    if(a%ans!=0) cout<<"Angry!"<<endl;
    else
    {
        cout<<((x1*(a/ans))%(mod/ans)+(mod/ans))%(mod/ans)<<endl;//放大回原来的倍数
    }
    return 0;
}
