#include<bits/stdc++.h>
using namespace std;
//继承实现
//公共页面
class BasePage
{
public:
    void header()
    {
        cout<<"首页"<<endl;
    }
    void footer()
    {
        cout<<"帮助中心"<<endl;
    }
    void left()
    {
        cout<<"Java,python,c++"<<endl;

    }
    void content()
    {
        cout<<"视频"<<endl;
    }

};

//减少重复代码
class Java:public BasePage//class 子类 ：继承方式 父类
{
public:
    void content()
    {
        cout<<"JAVA视频"<<endl;
    }
};

class Python:public BasePage
{
    public:
    void content()
    {
        cout<<"PYTHON视频"<<endl;
    }
};
void test01()
{
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
}


// 基类
class Animal {
private:
    int age; // 私有属性

public:
    Animal(int _age) : age(_age) {}//构造函数初始化

    void eat() {
        std::cout << "Animal is eating." << std::endl;
    }

    int getAge() const {
        return age;//输出age
    }
};

// 派生类
class Dog : public Animal {
public:
    Dog(int _age) : Animal(_age) {}

    void bark() {
        std::cout << "Dog is barking." << std::endl;
    }
};

int main() {
    // 创建派生类对象
    Dog dog(3);

    // 调用基类的成员函数
    dog.eat();

    // 调用派生类自己的成员函数
    dog.bark();

    // 调用基类的公有成员函数获取私有属性的值
    std::cout << "Dog's age: " << dog.getAge() << std::endl;

    return 0;
}

