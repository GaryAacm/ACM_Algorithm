/* https://codeforces.com/problemset/problem/1844/B */
#include<bits/stdc++.h>
using namespace std;
int n,t,x;
int main(){
    cin>>t;
    while(t--){
        x=4;
        scanf("%d",&n);
        if(n==1){
            printf("1\n");
        }
        else if(n==2){
            printf("2 1\n");
        }
        else{
            printf("2 ");
            for(int i=2;i<=n/2;i++){
                printf("%d ",x);
                x++;
            }
            printf("1 ");
            for(int i=n/2+2;i<n;i++){
                printf("%d ",x);
                x++;
            }
            printf("3\n");
        }
    }
    return 0;
}
