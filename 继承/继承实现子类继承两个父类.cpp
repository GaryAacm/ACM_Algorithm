
#include <bits/stdc++.h>
using namespace std;
// 基类1
class Base1 {
protected:
    int privateData1; // 私有属性

public:
    Base1(int data) : privateData1(data) {}//初始化赋值

    void function1() {
        std::cout << "Base1::function1()" << std::endl;
    }
    int getNum() const{
        return privateData1;
    }
};

// 基类2
class Base2 {
protected:
    int privateData2; // 私有属性

public:
    Base2(int data) : privateData2(data) {}

    void function2() {
        std::cout << "Base2::function2()" << std::endl;
    }
    int getNum2()const {
        return privateData2;
    }
};

// 派生类
class Derived : public Base1, public Base2 //逗号分隔继承两个子类
{
public:
    Derived(int data1, int data2) : Base1(data1), Base2(data2) {}  //构造函数调用两个类进行赋值

    void mergedFunction() {
        std::cout << "Derived::mergedFunction()" << std::endl;
        std::cout << "Private data from Base1: " << privateData1 << std::endl;
        std::cout << "Private data from Base2: " << privateData2 << std::endl;
    }
};

int main() {
    Derived derived(10, 20);//类对象

    // 调用基类1的函数
    derived.function1();

    // 调用基类2的函数
    derived.function2();

    // 调用派生类自己的函数
    derived.mergedFunction();
    cout<<"在类外得到输出值1："<< derived.getNum()<<endl<<"在类外得到输出值2："<<derived.getNum2()<<endl;;

    return 0;
}

