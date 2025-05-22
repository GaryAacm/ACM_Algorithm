#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;
ll n;
ll d[maxn],high[maxn],ans[maxn];
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
ll LIS()//求最长上升子序列
{
    int len=1;
    d[1]=high[1];
    for(int i=2;i<=n;i++)
    {
        if(d[len]<high[i])
        {
            d[++len]=high[i];
        }
        else
        {
            int j=lower_bound(d+1,d+1+len,high[i])-d;
            d[j]=high[i];
        }
    }
    return len;

}

int number()
{
    //reverse(high+1,high+1+n);
    ll lenn=1;
    ans[1]=high[1];
    for(int i=2;i<=n;i++)
    {
        if(ans[lenn]>=high[i])
        {
            ans[++lenn]=high[i];
        }
        else
        {
            ll j=upper_bound(ans+1,ans+1+lenn,high[i],greater<long long>())-ans;
            ans[j]=high[i];
        }
    }
    return lenn;
}

int main()
{
   while(cin>>high[n]){
		n++;
	}
	n--;
   // cin>>n;
    //for(int i=1;i<=n;i++)
        //cin>>high[i];
    int x=LIS();
    write(number());
    puts("");
    write(x);

    return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1000010
using namespace std;
typedef long long ll;
ll a[maxn],n=1,dp1[maxn],dp2[maxn],len1,len2;
inline void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	while(cin>>a[n]){
		n++;
	}
	n--,len1=1,len2=1;
	dp1[1]=a[1],dp2[1]=a[1];
	for(ll i=2;i<=n;i++){
		if(a[i]<=dp1[len1]){
			dp1[++len1]=a[i];
		}
		else{
			ll k1=upper_bound(dp1+1,dp1+len1+1,a[i],greater<ll>())-dp1;
			dp1[k1]=a[i];
		}
		if(a[i]>dp2[len2]){
			dp2[++len2]=a[i];
		}
		else{
			ll k2=lower_bound(dp2+1,dp2+len2+1,a[i])-dp2;
			dp2[k2]=a[i];
		}
	}
	write(len1);
	puts("");
	write(len2);
	return 0;
}
*/
