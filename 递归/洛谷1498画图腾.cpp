/*�۲쵽����ͨ����һ��ͼ�ο���ת��Ϊn��ͼ�Σ����Կ����ɵ�һ��ͼ���Ƶ�����*/
#include<iostream>
#include<math.h>
using namespace std;
char mp[1030][2050];   //�洢��
int n;
void dr(int x,int y,int deep){        //x,y��ʾͼ�εĵ�һ����/��������
//deep��ʾ����ͼ�εĴ�С
    if(deep==1){                 //����n=1�Ļ���ͼ��
        mp[x][y]='/';
        mp[x][y+1]='\\';
        mp[x+1][y-1]='/';
        mp[x+1][y]='_';
        mp[x+1][y+1]='_';
        mp[x+1][y+2]='\\';
        return;
    }
    dr(x,y,deep-1);//��һ�εݹ��������ϲ�                       //�ݹ�ֱ���������
    dr(x+pow(2,deep-1),y-pow(2,deep-1),deep-1);//����һ������
    dr(x+pow(2,deep-1),y+pow(2,deep-1),deep-1);//����һ������
}
int main(){
    cin>>n;
    //��ʼ��
    for(int i=1;i<=pow(2,n);i++)
    {
        for(int j=1;j<=pow(2,n+1);j++)
            mp[i][j]=' ';
    }
    dr(1,pow(2,n),n);
    for(int i=1;i<=pow(2,n);i++){               //���
        for(int j=1;j<=pow(2,n+1);j++)
        cout<<mp[i][j];
        cout<<endl;
    }
}
