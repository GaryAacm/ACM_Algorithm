#include<bits/stdc++.h>
using namespace std;
int main(){
   long long n,a,b;
   cin>>a>>b>>n;
   long long ans=a/b;
   if(ans<=n) cout<<ans*b;
   else cout<<b*n;
	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,n,x=0;
	scanf("%d%d%d",&a,&b,&n);
    for(int i=1;i<=n;i++){
    	if(x+b<=a)x+=b;
    	else break;
	}
	cout<<x<<endl;
	return 0;
}*/
