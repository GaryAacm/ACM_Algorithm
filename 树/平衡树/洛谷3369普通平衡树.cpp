#include <iostream>
using namespace std;

#define ls(x) tr[x].s[0]

#define rs(x) tr[x].s[1]
const int N=1100010, INF=(1<<30)+1;


struct node{
  int s[2]; //左右儿子
  int p; //父亲
  int v; //节点权值
  int cnt; //权值出现次数
  int siz; //子树大小，在搜索树里面是排名
  void init(int p1,int v1){
    p=p1, v=v1;
    cnt=siz=1;
  }
}tr[N];


int root; //根节点编号
int idx; //节点个数

void pushup(int x){
  tr[x].siz=tr[ls(x)].siz+tr[rs(x)].siz+tr[x].cnt;//往上更新
}


void Rotate(int x){
  int y=tr[x].p, z=tr[y].p;//双向更新节点
  int k = tr[y].s[1]==x;
  tr[z].s[tr[z].s[1]==y] =x;
  tr[x].p = z;
  tr[y].s[k] = tr[x].s[k^1];
  tr[tr[x].s[k^1]].p = y;
  tr[x].s[k^1] = y;
  tr[y].p = x;
  pushup(y), pushup(x);
}



void splay(int x, int k){
  while(tr[x].p!=k){
    int y=tr[x].p, z=tr[y].p;
    if(z!=k)   // 折转底，直转中
      (ls(y)==x)^(ls(z)==y)//判断是哪种类型的要开始旋转
        ? Rotate(x) : Rotate(y);
    Rotate(x);
  }
  if(!k) root=x;
}



void Insert(int v){ //插入数值为v的点
  int x=root, p=0;
  while(x && tr[x].v!=v)
    p=x, x=tr[x].s[v>tr[x].v];
  if(x) tr[x].cnt++;
  else{
    x=++idx;//开辟新的节点
    if(p) tr[p].s[v>tr[p].v]=x;
    tr[x].init(p,v);
  }
  splay(x, 0);
}


void Find(int v){ //找到v并转到根
  int x=root;
  while(tr[x].s[v>tr[x].v]&&v!=tr[x].v)
    x=tr[x].s[v>tr[x].v];
  splay(x, 0);
}


int getpre(int v){ //前驱
  Find(v);
  int x=root;
  if(tr[x].v<v) return x;
  x=ls(x);//左边找前驱
  while(rs(x)) x=rs(x);//找到前驱里面最大的
  splay(x, 0);
  return x;
}


int getsuc(int v){ //后继同前驱
  Find(v);
  int x=root;
  if(tr[x].v>v) return x;
  x=rs(x);
  while(ls(x)) x=ls(x);
  splay(x, 0);
  return x;
}


void del(int v){ //删除
  int pre=getpre(v);
  int suc=getsuc(v);
  splay(pre,0), splay(suc,pre);//把删除的节点转到叶子节点
  int del=tr[suc].s[0];
  if(tr[del].cnt>1)//只是删除一个
    tr[del].cnt--, splay(del,0);
  else
    tr[suc].s[0]=0, splay(suc,0);//只有一个就置为0
}
int getrank(int v){ //找到值为v的排名
  Insert(v);
  int res=tr[tr[root].s[0]].siz;
  del(v);
  return res;
}
int getval(int k){ //找到怕排名k的数值
    int x=root;
    while(true){
        if(k<=tr[ls(x)].siz) x=ls(x);//在左子树查找
        else if(k<=tr[ls(x)].siz+tr[x].cnt) break;
        else k-=tr[ls(x)].siz+tr[x].cnt, x=rs(x);//减去相应的，在右子树查找
    }
    splay(x, 0);
    return tr[x].v;
}
int main(){

  Insert(-INF);Insert(INF); //哨兵

  //freopen("D:\\算法进阶\\树\\平衡树\\in.txt","r",stdin);
  int n,op,x; scanf("%d", &n);
  while(n--){
    scanf("%d%d", &op, &x);
    if(op==1) Insert(x);
    else if(op==2) del(x);
    else if(op==3) printf("%d\n",getrank(x));
    else if(op==4) printf("%d\n",getval(x+1));
    else if(op==5) printf("%d\n",tr[getpre(x)].v);
    else printf("%d\n",tr[getsuc(x)].v);
  }
  return 0;
}

