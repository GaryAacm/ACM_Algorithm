#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
//���ﲻ��Ӳ�����۲�ֻ��1��2�������������
ll a,b,n=1,ans=1;
int nums[]={6,2,5,5,4,5,6,3,7,6};
ll check(ll x){
	ll cnt=0;
	while(x){
		cnt+=nums[x%10];
		x/=10;
	}
return cnt;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>a>>b;
	if(b-a>9){
		cout<<"2"; return 0;
	}

	for(ll i=a+1;i<=b;i++){
		if(check(i)==check(i-1)){
			cout<<"2"; return 0;
		}
	}
	cout<<"1";
return 0;
}

