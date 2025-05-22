#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);   //�߾���Բ����
const double esp= 1e-8;//���ڼ���ƫ��ֵ

int sgn(double x)
{
    if(fabs(x)<esp) return 0;//x����0
    else return x<0?-1:1;//�������߸���
}

int dcmp(double x,double y)
{
    if(fabs(x-y)<esp) return 0;//�������������
    else return x<y?-1:1;
}


//�������

struct Point
{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y) {}

    //�����ӷ�
    Point operator + (Point B){return Point(x+B.x,y+B.y);}

    //����
    Point operator - (Point B){return Point(x-B.x,y-B.y);}

    //�˷�
    Point operator * (double k){return Point(x*k,y*k);}

    //����
    Point operator / (double k){return Point(x/k,y/k);}

    //���
    bool operator == (Point B) {return sgn(x-B.x)==0&&sgn(y-B.y)==0;}
};

typedef Point Vector;


//����
double Distance(Point A,Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

//���
double Dot(Vector A,Vector B)
{
    return A.x*B.x+A.y*B.y;
}

//��ģ
double Len(Vector A)
{
    return sqrt(Dot(A,A));
}

double Len2(Vector A)
{
    return Dot(A,A);
}

//��н�
double Angle(Vector A,Vector B)
{
    return acos(Dot(A,B)/Len(A)/Len(B));
}

//���
double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}

//����AΪ������ı������
double Area2(Point A,Point B,Point C)
{
    return Cross(B-A,C-A);
}

//����AΪ��������������
double Area1(Point A,Point B,Point C)
{
    return Cross(B-A,C-A)/2;
}

//������ת
Vector Rotate(Vector A,double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

//�Ƿ�ƽ�м��
bool Paraller(Vector A,Vector B)
{
    return sgn(Cross(A,B))==0;
}

struct Line
{
    Point p1,p2;
    Line(){}
    Line (Point p1,Point p2):p1(p1),p2(p2){}
    //��֪�ǶȺ�һ����
    Line (Point p,double angle)
    {
        p1=p;
        if(sgn(angle-pi/2)==0) {p2=(p1+Point(0,1));}
        else {p2=(p1+Point(1,tan(angle)));}
    }

    //ax+by+c
    Line(double a,double b,double c)
    {
        if(sgn(a)==0)
        {
            p1=Point(0,-c/b);
            p2=Point(1,-c/b);
        }
        else if(sgn(b)==0)
        {
            p1=Point(-c/a,0);
            p2=Point(-c/a,1);
        }
        else

        {
            p1=Point(0,-c/b);
            p2=Point(1,(-c-a)/b);
        }
    }

};

typedef Line Segment;
//�жϵ��ֱ�߹�ϵ
int Point_line_relation(Point p,Line v)
{
    int c=sgn(Cross(p-v.p1,v.p2-v.p1));
    if(c<0) return 1;//���
    else if(c>0) return 2;//�Ҳ�
    return 0;//������
}

//�жϵ����߶���
int Point_on_seg(Point p,Line v)
{
    return sgn(Cross(p-v.p1,v.p2-v.p1))==0&&sgn(Dot(p-v.p1,p-v.p2))<=0 ;//�ж��ڲ������ϲ��ҽǶ��Ƕ۽�
}

//�㵽�ߵľ���
double Dis_point_line(Point p,Line v)
{
    return fabs(Cross(p-v.p1,v.p2-v.p1))/Distance(v.p1,v.p2);//�����ı��������
}

//����ֱ����ͶӰ
Point Point_line_proj(Point p,Line v)
{
    double k=Dot(v.p2-v.p1,p-v.p1)/Len2(v.p2-v.p1);
    return v.p1+(v.p2-v.p1)*k;//����ֵ��ͶӰ������꣬����p1Ϊ�����������յ����꣬������pp1ͶӰ��p1p2��
}

//�����ֱ�߶ԳƵĵ�
Point Point_line_symmtery(Point p,Line v)
{
    Point q=Point_line_proj(p,v);
    return Point(2*q.x-p.x,2*q.y-p.y);
}

//�㵽�߶ξ���
double Dis_point_seg(Point p,Segment v)
{
    if(sgn(Dot(p-v.p1,v.p2-v.p1))<0||sgn(Dot(p-v.p2,v.p1-v.p2))<0)
        return min(Distance(p,v.p1),Distance(p,v.p2));
    return Dis_point_line(p,v);
}

//����ֱ�ߵ�λ�ù�ϵ
int Line_relation(Line v1,Line v2)
{
    if(sgn(Cross(v1.p2-v1.p1,v2.p2-v2.p1))==0)
    {
        if(Point_line_relation(v1.p1,v2)==0) return 1;//�غ�
        else return 0;//ƽ��

    }

    return 2;//�ཻ
}

//�����ߵĽ���
Point Cross_point(Point a,Point b,Point c,Point d)//ab��cd�Ľ���
{
    double s1=Cross(b-a,c-a);
    double s2=Cross(b-a,d-a);
    return Point(c.x*s2-d.x*s1,c.y*s2-d.y*s1)/(s2-s1);//��֤s2��=s1
}

//�ж����߶��Ƿ��ཻ
bool Cross_segment(Point a,Point b,Point c,Point d)
{
    double c1=Cross(b-a,c-a),c2=Cross(b-a,d-a);
    double d1=Cross(d-c,a-c),d2=Cross(d-c,b-c);
    return sgn(c1)*sgn(c2)<=0 && sgn(d1)*sgn(d2)<=0;//1:�ཻ��0:���ཻ
}

int main()
{
    cout<<pi<<endl;

}
