#include <iostream>
using namespace std;

#define ls(x) tr[x].s[0]

#define rs(x) tr[x].s[1]
const int N=1100010, INF=(1<<30)+1;


struct node{
  int s[2]; //���Ҷ���
  int p; //����
  int v; //�ڵ�Ȩֵ
  int cnt; //Ȩֵ���ִ���
  int siz; //������С��������������������
  void init(int p1,int v1){
    p=p1, v=v1;
    cnt=siz=1;
  }
}tr[N];


int root; //���ڵ���
int idx; //�ڵ����

void pushup(int x){
  tr[x].siz=tr[ls(x)].siz+tr[rs(x)].siz+tr[x].cnt;//���ϸ���
}


void Rotate(int x){
  int y=tr[x].p, z=tr[y].p;//˫����½ڵ�
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
    if(z!=k)   // ��ת�ף�ֱת��
      (ls(y)==x)^(ls(z)==y)//�ж����������͵�Ҫ��ʼ��ת
        ? Rotate(x) : Rotate(y);
    Rotate(x);
  }
  if(!k) root=x;
}



void Insert(int v){ //������ֵΪv�ĵ�
  int x=root, p=0;
  while(x && tr[x].v!=v)
    p=x, x=tr[x].s[v>tr[x].v];
  if(x) tr[x].cnt++;
  else{
    x=++idx;//�����µĽڵ�
    if(p) tr[p].s[v>tr[p].v]=x;
    tr[x].init(p,v);
  }
  splay(x, 0);
}


void Find(int v){ //�ҵ�v��ת����
  int x=root;
  while(tr[x].s[v>tr[x].v]&&v!=tr[x].v)
    x=tr[x].s[v>tr[x].v];
  splay(x, 0);
}


int getpre(int v){ //ǰ��
  Find(v);
  int x=root;
  if(tr[x].v<v) return x;
  x=ls(x);//�����ǰ��
  while(rs(x)) x=rs(x);//�ҵ�ǰ����������
  splay(x, 0);
  return x;
}


int getsuc(int v){ //���ͬǰ��
  Find(v);
  int x=root;
  if(tr[x].v>v) return x;
  x=rs(x);
  while(ls(x)) x=ls(x);
  splay(x, 0);
  return x;
}


void del(int v){ //ɾ��
  int pre=getpre(v);
  int suc=getsuc(v);
  splay(pre,0), splay(suc,pre);//��ɾ���Ľڵ�ת��Ҷ�ӽڵ�
  int del=tr[suc].s[0];
  if(tr[del].cnt>1)//ֻ��ɾ��һ��
    tr[del].cnt--, splay(del,0);
  else
    tr[suc].s[0]=0, splay(suc,0);//ֻ��һ������Ϊ0
}
int getrank(int v){ //�ҵ�ֵΪv������
  Insert(v);
  int res=tr[tr[root].s[0]].siz;
  del(v);
  return res;
}
int getval(int k){ //�ҵ�������k����ֵ
    int x=root;
    while(true){
        if(k<=tr[ls(x)].siz) x=ls(x);//������������
        else if(k<=tr[ls(x)].siz+tr[x].cnt) break;
        else k-=tr[ls(x)].siz+tr[x].cnt, x=rs(x);//��ȥ��Ӧ�ģ�������������
    }
    splay(x, 0);
    return tr[x].v;
}
int main(){

  Insert(-INF);Insert(INF); //�ڱ�

  //freopen("D:\\�㷨����\\��\\ƽ����\\in.txt","r",stdin);
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

