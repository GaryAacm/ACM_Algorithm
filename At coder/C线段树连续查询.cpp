/*
线段树维护区间最长连续子序列

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5e4+10;
struct node{
	int l,r,sum;//从左边开始往右的最长连续子序列长度，从右边开始往左的最长连续子序列长度，整段区间之和
}t[maxn<<2];
int n,m;

void pushup(int l,int r,int rt){
	int m=l+r>>1;
	t[rt].l=t[rt<<1].l+(t[rt<<1].l==m-l+1 ? t[rt<<1|1].l : 0);//若左子树的最长连续子序列长度等于左子树整段的长度则还要加上右子树的从左开始的最长连续子序列
	t[rt].r=t[rt<<1|1].r+(t[rt<<1|1].r==r-m ? t[rt<<1].r : 0);
	t[rt].sum=max(max(t[rt<<1].sum,t[rt<<1|1].sum),t[rt<<1].r+t[rt<<1|1].l);
}

void build(int l,int r,int rt){
	if(l==r){
		t[rt].l=t[rt].r=t[rt].sum=1;
		return;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(l,r,rt);
}

void update(int pos,int v,int l,int r,int rt){
	if(l==r){
		t[rt].l=t[rt].r=t[rt].sum=v;
		return ;
	}
	int m=(l+r)>>1;
	if(pos<=m) update(pos,v,l,m,rt<<1);
	else update(pos,v,m+1,r,rt<<1|1);
	pushup(l,r,rt);
}

int query(int pos,int l,int r,int rt){
	if(l==r || t[rt].sum==0 || t[rt].sum==r-l+1){
		return t[rt].sum;
	}
	int m=l+r>>1;
	if(pos<=m){
		if(m-t[rt<<1].r+1<=pos) return t[rt<<1].r+t[rt<<1|1].l;
		else return query(pos,l,m,rt<<1);
	}
	else {
		if(t[rt<<1|1].l+m>=pos) return t[rt<<1].r+t[rt<<1|1].l;
		else return query(pos,m+1,r,rt<<1|1);
	}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		build(1,n,1);
		char c;
		int a[maxn];
		int cnt=0,x;
		for (int i=1;i<=m;i++){
			getchar();
			scanf("%c",&c);
			if(c=='D'){
				scanf("%d",&x);
				a[cnt++]=x;
				update(x,0,1,n,1);
			}
			else if(c=='Q'){
				scanf("%d",&x);
				int ans=query(x,1,n,1);
				printf("%d\n",ans);
			}
			else if(c=='R'){
				update(a[--cnt],1,1,n,1);
			}
		}
	}
	return 0;
}*/

#include <bits/stdc++.h>

const int N = 300010;

int n, Q;

int pre[N];
char s[N];

int main() {
    scanf("%d%d", &n, &Q);
    scanf("%s", s + 1);

    for (int i = 1; i < n; ++ i) {
        pre[i] = pre[i - 1] + (s[i] == s[i + 1]);//将数据存储起来
    }

    while (Q --) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", pre[r - 1] - pre[l - 1]);//o1复杂度查询
    }
    return 0;
}

