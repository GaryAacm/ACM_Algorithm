#include<bits/stdc++.h>
using namespace std;

const double pi=acos(-1.0);   //高精度圆周率
const double esp= 1e-8;//用于计算偏差值

int sgn(double x)
{
    if(fabs(x)<esp) return 0;//x等于0
    else return x<0?-1:1;//正数或者负数
}

int dcmp(double x,double y)
{
    if(fabs(x-y)<esp) return 0;//两个浮点数相等
    else return x<y?-1:1;
}


//点和向量

struct Point
{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y) {}

    //向量加法
    Point operator + (Point B){return Point(x+B.x,y+B.y);}

    //减法
    Point operator - (Point B){return Point(x-B.x,y-B.y);}

    //乘法
    Point operator * (double k){return Point(x*k,y*k);}

    //除法
    Point operator / (double k){return Point(x/k,y/k);}

    //相等
    bool operator == (Point B) {return sgn(x-B.x)==0&&sgn(y-B.y)==0;}
};

typedef Point Vector;


//距离
double Distance(Point A,Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

//点积
double Dot(Vector A,Vector B)
{
    return A.x*B.x+A.y*B.y;
}

//求模
double Len(Vector A)
{
    return sqrt(Dot(A,A));
}

double Len2(Vector A)
{
    return Dot(A,A);
}

//求夹角
double Angle(Vector A,Vector B)
{
    return acos(Dot(A,B)/Len(A)/Len(B));
}

//叉积
double Cross(Vector A,Vector B)
{
    return A.x*B.y-A.y*B.x;
}

//求以A为顶点的四边形面积
double Area2(Point A,Point B,Point C)
{
    return Cross(B-A,C-A);
}

//求以A为顶点的三角形面积
double Area1(Point A,Point B,Point C)
{
    return Cross(B-A,C-A)/2;
}

//向量旋转
Vector Rotate(Vector A,double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

//是否平行检查
bool Paraller(Vector A,Vector B)
{
    return sgn(Cross(A,B))==0;
}

struct Line
{
    Point p1,p2;
    Line(){}
    Line (Point p1,Point p2):p1(p1),p2(p2){}
    //已知角度和一个点
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
//判断点和直线关系
int Point_line_relation(Point p,Line v)
{
    int c=sgn(Cross(p-v.p1,v.p2-v.p1));
    if(c<0) return 1;//左侧
    else if(c>0) return 2;//右侧
    return 0;//在线上
}

//判断点在线段上
int Point_on_seg(Point p,Line v)
{
    return sgn(Cross(p-v.p1,v.p2-v.p1))==0&&sgn(Dot(p-v.p1,p-v.p2))<=0 ;//判断在不在线上并且角度是钝角
}

//点到线的距离
double Dis_point_line(Point p,Line v)
{
    return fabs(Cross(p-v.p1,v.p2-v.p1))/Distance(v.p1,v.p2);//利用四边形面积求
}

//点在直线上投影
Point Point_line_proj(Point p,Line v)
{
    double k=Dot(v.p2-v.p1,p-v.p1)/Len2(v.p2-v.p1);
    return v.p1+(v.p2-v.p1)*k;//返回值是投影点的坐标，即以p1为起点的向量的终点坐标，这里是pp1投影到p1p2上
}

//点关于直线对称的点
Point Point_line_symmtery(Point p,Line v)
{
    Point q=Point_line_proj(p,v);
    return Point(2*q.x-p.x,2*q.y-p.y);
}

//点到线段距离
double Dis_point_seg(Point p,Segment v)
{
    if(sgn(Dot(p-v.p1,v.p2-v.p1))<0||sgn(Dot(p-v.p2,v.p1-v.p2))<0)
        return min(Distance(p,v.p1),Distance(p,v.p2));
    return Dis_point_line(p,v);
}

//两条直线的位置关系
int Line_relation(Line v1,Line v2)
{
    if(sgn(Cross(v1.p2-v1.p1,v2.p2-v2.p1))==0)
    {
        if(Point_line_relation(v1.p1,v2)==0) return 1;//重合
        else return 0;//平行

    }

    return 2;//相交
}

//求两线的交点
Point Cross_point(Point a,Point b,Point c,Point d)//ab与cd的交点
{
    double s1=Cross(b-a,c-a);
    double s2=Cross(b-a,d-a);
    return Point(c.x*s2-d.x*s1,c.y*s2-d.y*s1)/(s2-s1);//保证s2！=s1
}

//判断两线段是否相交
bool Cross_segment(Point a,Point b,Point c,Point d)
{
    double c1=Cross(b-a,c-a),c2=Cross(b-a,d-a);
    double d1=Cross(d-c,a-c),d2=Cross(d-c,b-c);
    return sgn(c1)*sgn(c2)<=0 && sgn(d1)*sgn(d2)<=0;//1:相交；0:不相交
}

int main()
{
    cout<<pi<<endl;

}
