#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;


int t,n;
int a,b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        a=n/2;
        b=n*2-a;
        if((a^b)==n) cout<<a<<' '<<b<<'\n';
        else cout<<-1<<'\n';
    }
}

//ͨ��ö�ٳ�ǰ1000�����������ִ�����СΪx/2,����һ����2*x/3��ֻ��2�����������Ƿ����Ҫ�����
/*#include<bits/stdc++.h>
using namespace std;
inline long long read();
int main()
{
	for(int x=1;x<=1000;x++)
		for(int i=1;i<=x*2;i++)
			if((i^(x*2-i))==x)
			{
				cout<<x<<" "<<i<<" "<<(x*2-i)<<"\n";
				break;
			}
	return 0;
}*/
