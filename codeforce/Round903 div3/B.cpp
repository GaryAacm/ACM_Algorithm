#include <bits/stdc++.h>
using namespace std;
long long T,a[10];
int main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
        sort(a+1,a+4);
        if((a[1]==a[2]&&a[2]==a[3])||(a[2]==a[3]&&a[2]==a[1]*2)||(a[1]==a[2]&&a[3]==a[1]*2)||(a[1]==a[2]&&a[3]==a[1]*3)||(a[1]==a[2]&&a[3]==a[1]*4)||(a[2]==a[1]*2&&a[3]==a[1]*3)){//判断所有的倍数情况
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}

