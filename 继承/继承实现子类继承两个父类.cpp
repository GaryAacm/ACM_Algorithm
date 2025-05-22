
#include <bits/stdc++.h>
using namespace std;
// ����1
class Base1 {
protected:
    int privateData1; // ˽������

public:
    Base1(int data) : privateData1(data) {}//��ʼ����ֵ

    void function1() {
        std::cout << "Base1::function1()" << std::endl;
    }
    int getNum() const{
        return privateData1;
    }
};

// ����2
class Base2 {
protected:
    int privateData2; // ˽������

public:
    Base2(int data) : privateData2(data) {}

    void function2() {
        std::cout << "Base2::function2()" << std::endl;
    }
    int getNum2()const {
        return privateData2;
    }
};

// ������
class Derived : public Base1, public Base2 //���ŷָ��̳���������
{
public:
    Derived(int data1, int data2) : Base1(data1), Base2(data2) {}  //���캯��������������и�ֵ

    void mergedFunction() {
        std::cout << "Derived::mergedFunction()" << std::endl;
        std::cout << "Private data from Base1: " << privateData1 << std::endl;
        std::cout << "Private data from Base2: " << privateData2 << std::endl;
    }
};

int main() {
    Derived derived(10, 20);//�����

    // ���û���1�ĺ���
    derived.function1();

    // ���û���2�ĺ���
    derived.function2();

    // �����������Լ��ĺ���
    derived.mergedFunction();
    cout<<"������õ����ֵ1��"<< derived.getNum()<<endl<<"������õ����ֵ2��"<<derived.getNum2()<<endl;;

    return 0;
}

