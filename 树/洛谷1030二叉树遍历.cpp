#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
char pre[maxn],in[maxn],post[maxn];
int k;
struct node
{
    char value;
    node *l,*r;
    node(char value=' ',node*l=NULL,node *r=NULL):value(value),l(l),r(r){}
};//定义结构体并且赋值

void buildtree(int l,int r,int &t,node *&root)//建树
{
    int flag=-1;
    for(int i=l;i<=r;i++)
    {
        //找到节点
        if(in[i]==post[t])
        {
            flag=i;//记录节点位置
            break;
        }
    }
    if(flag==-1) return;
    root = new node(in[flag]);//新建节点
    t++;//递归节点
    if(flag>l) buildtree(l,flag-1,t,root->l);//建立左子树
    if(flag<r) buildtree(flag+1,r,t,root->r);//建立右子树

}

//下面分别是前序，中序和后续输出
void preorder(node *root)
{
    if(root!=NULL)
    {
        pre[k++]=root->value;//先输出节点
        preorder(root->l);
        preorder(root->r);
    }
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->l);
        in[k++]=root->value;
        inorder(root->r);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->l);
        postorder(root->r);
        post[k++]=root->value;
    }
}

void remove_tree(node *root)
{
    if(root==NULL) return ;
    remove_tree(root->l);
    remove_tree(root->r);
    delete root;
}

int main()
{
       cin>>in+1;
       cin>>post+1;
       //cout<<in+1;
       int n=strlen(in+1);
        node *root;
        int t=1;//建立根节点和初始1为节点
        buildtree(1,n,t,root);
        k=0;
        preorder(root);
        for(int i=0;i<k;i++)
        {
            cout<<pre[i];
        }
        cout<<endl;
        remove_tree(root);
    return 0;
}

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
void beford(string in,string after){
    if (in.size()>0){
        char ch=after[after.size()-1];
        cout<<ch;//找根输出
        int k=in.find(ch);
        beford(in.substr(0,k),after.substr(0,k));
        beford(in.substr(k+1),after.substr(k,in.size()-k-1));//递归左右子树；
    }
}
int main(){
    string inord,aftord;
    cin>>inord;cin>>aftord;//读入
    beford(inord,aftord);cout<<endl;
    return 0;
}
