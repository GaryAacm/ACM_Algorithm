#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int t,n,v,k;
double ans,ss,w;//���ʵ��������
int val[maxn];

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>v>>w;
        memset(val,0,sizeof(val));
        for(int i=1;i<=n;i++)
        {
            //����ҩˮ��Ũ��
            cin>>val[i];
        }
        sort(val+1,val+1+n);
        //�����ҵ�Ũ����С��
        int i;
        if(val[1]>w)
            {
                cout<<"0"<<' '<<"0.00"<<endl;
                continue;
            }
        ans=0,ss=0,k=0;//ע���ʼ��
        for(i=1;i<=n;i++)
        {
            //����ҩˮŨ��
            ans+=val[i]*v/100;

            if(ans/(i*v)*100<=w)
            {
                //���Լ�����
                ss=ans/(i*v);//Ũ������
                k++;
            }
            else{
                break;
            }
        }
		printf("%d %.2f\n",(i-1)*v,ss);
    }
    return 0;
}
