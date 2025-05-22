#include<iostream>
#include<math.h>
using namespace std;
long long a[99999999],b[99999999];
double kill,l=99999999999;
int main(){
    int i,j,n;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++){
        kill=sqrt((a[j]-a[i])*(a[j]-a[i])+(b[j]-b[i])*(b[j]-b[i]));
    if(l>kill)l=kill;
    }
    printf("%.4lf",l);
}
