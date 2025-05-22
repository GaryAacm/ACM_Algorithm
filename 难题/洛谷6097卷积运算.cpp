#include<bits/stdc++.h>
#define ll long long
#define mod 1000000009
using namespace std;
const int N=22;
int n,len,a[N][1<<N],b[N][1<<N],h[N][1<<N];
int ct(int x){
    return __builtin_popcount(x);
}
void FMT(int *a,int n,int flag) {
    for(int i=0; i<n; i++)
        for(int j=0; j<(1<<n); j++)
            if(j>>i&1)
                a[j]=(a[j]+(flag+mod)%mod*1ll*a[j^(1<<i)]%mod)%mod;
}
int main() {
    scanf("%d",&n);
    len=1<<n;
    for(int i=0;i<len;i++)
        scanf("%d",&a[ct(i)][i]);
    for(int i=0;i<len;i++)
        scanf("%d",&b[ct(i)][i]);
    for(int i=0;i<=n;i++)
        FMT(a[i],n,1),FMT(b[i],n,1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<len;j++)
        for(int k=0;k<=i;k++)
        h[i][j]=(h[i][j]+1ll*a[k][j]*b[i-k][j]%mod)%mod;
        FMT(h[i],n,-1);
    }
    for(int i=0;i<len;i++)
        printf("%d ",h[ct(i)][i]);
    return 0;
}


