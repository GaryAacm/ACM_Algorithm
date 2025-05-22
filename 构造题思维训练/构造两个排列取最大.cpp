#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int maxn=2e5+10;
//˼������ҵ���Ӧ�ĳ��ִ���������ͬ���ǻ�����ע��ʵ�ֵķ�������det�����ң��Լ���vector��¼λ��
int t,n,a[maxn];
vector<int> pos[maxn];
set<int> s;
int p[maxn],q[maxn];

void init()
{
    for(int i=1;i<=n;i++)
    {
        pos[i].clear();
        p[i]=q[i]=0;
    }
}

void solve()
{
    cin>>n;
    init();
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxx=max(a[i],maxx);
        pos[a[i]].push_back(i);//��¼a[i]���ֶ�Ӧ��λ��
    }
    bool f=true;
    if(pos[n].empty()||pos[1].size()>=2)
    {
        f=false;
        cout<<"NO"<<'\n';
        return ;
    }
    else
    {
        for(int i=1;i<=maxx;i++)
        {
            sort(pos[i].begin(),pos[i].end());
            if(pos[i].empty()) s.insert(i);//��¼û�г��ֵ����
            else if(pos[i].size()==1) p[pos[i][0]]=q[pos[i][0]]=i;
            else if(pos[i].size()==2) p[pos[i][0]]=q[pos[i][1]]=i;//����λ��
            else
            {
                f=false;
                break;
            }
        }
        if(!f)
        {
            cout<<"NO"<<'\n';
            return ;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(p[i]&&!q[i])
                {
                    int tmp=pos[p[i]][1];//��¼p�յ�λ��
                    set<int>::iterator it=s.lower_bound(p[i]);
                    if(it==s.begin())
                    {
                        f=false;
                        cout<<"NO"<<endl;
                        return ;
                    }
                    else
                    {
                        it--;
                        q[i]=p[tmp]=*it;
                        s.erase(it);//�ҵ������ڵ�������
                    }
                }
            }
            cout<<"YES"<<'\n';
            for(int i=1;i<=n;i++)
            {
                cout<<p[i]<<' ';
            }
            cout<<'\n';
            for(int i=1;i<=n;i++)
            {
                cout<<q[i]<<' ';
            }
            cout<<'\n';
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}


/*#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
int read(){
	int x=0,f=1,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f=(ch=='-')?-1:1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
int T,Max,n,k,a[N],p[N],q[N];
vector<int>pos[N];
set<int>s;
void clean(){
	Max=0;s.clear();
	for(int i=1;i<=n;++i){
		p[i]=q[i]=0;
		pos[i].clear();
	}
}
int main(){
	T=read();
	while(T--){
		n=read();clean();
		for(int i=1;i<=n;++i) Max=max(Max,a[i]=read());
		for(int i=1;i<=n;++i) pos[a[i]].push_back(i);
		bool flg=true;
		for(int i=1;i<=Max;++i){
			sort(pos[i].begin(),pos[i].end());
			if(pos[i].empty()) s.insert(i);
			else if(pos[i].size()==1) p[pos[i][0]]=q[pos[i][0]]=i;
			else if(pos[i].size()==2) p[pos[i][0]]=q[pos[i][1]]=i;
			else{
				flg=false;
				break;
			}
		}
		if(pos[n].empty() || pos[1].size()>=2) flg=false;
		for(int i=1;i<=n;++i){
			if(p[i] && !q[i]){
				int pre=pos[p[i]][1];
				set<int>::iterator it=s.lower_bound(p[i]);
				if(it==s.begin()){
					flg=false;
					break;
				}
				else{
					it--;
					q[i]=p[pre]=*it;
					s.erase(it);
				}
			}
		}
		if(!flg) puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;++i) printf("%d ",p[i]);puts("");
			for(int i=1;i<=n;++i) printf("%d ",q[i]);puts("");
		}
	}
	return 0;
}*/
