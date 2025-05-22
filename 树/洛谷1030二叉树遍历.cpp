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
};//����ṹ�岢�Ҹ�ֵ

void buildtree(int l,int r,int &t,node *&root)//����
{
    int flag=-1;
    for(int i=l;i<=r;i++)
    {
        //�ҵ��ڵ�
        if(in[i]==post[t])
        {
            flag=i;//��¼�ڵ�λ��
            break;
        }
    }
    if(flag==-1) return;
    root = new node(in[flag]);//�½��ڵ�
    t++;//�ݹ�ڵ�
    if(flag>l) buildtree(l,flag-1,t,root->l);//����������
    if(flag<r) buildtree(flag+1,r,t,root->r);//����������

}

//����ֱ���ǰ������ͺ������
void preorder(node *root)
{
    if(root!=NULL)
    {
        pre[k++]=root->value;//������ڵ�
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
        int t=1;//�������ڵ�ͳ�ʼ1Ϊ�ڵ�
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
        cout<<ch;//�Ҹ����
        int k=in.find(ch);
        beford(in.substr(0,k),after.substr(0,k));
        beford(in.substr(k+1),after.substr(k,in.size()-k-1));//�ݹ�����������
    }
}
int main(){
    string inord,aftord;
    cin>>inord;cin>>aftord;//����
    beford(inord,aftord);cout<<endl;
    return 0;
}
