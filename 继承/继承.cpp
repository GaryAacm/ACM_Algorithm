#include<bits/stdc++.h>
using namespace std;
//�̳�ʵ��
//����ҳ��
class BasePage
{
public:
    void header()
    {
        cout<<"��ҳ"<<endl;
    }
    void footer()
    {
        cout<<"��������"<<endl;
    }
    void left()
    {
        cout<<"Java,python,c++"<<endl;

    }
    void content()
    {
        cout<<"��Ƶ"<<endl;
    }

};

//�����ظ�����
class Java:public BasePage//class ���� ���̳з�ʽ ����
{
public:
    void content()
    {
        cout<<"JAVA��Ƶ"<<endl;
    }
};

class Python:public BasePage
{
    public:
    void content()
    {
        cout<<"PYTHON��Ƶ"<<endl;
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


// ����
class Animal {
private:
    int age; // ˽������

public:
    Animal(int _age) : age(_age) {}//���캯����ʼ��

    void eat() {
        std::cout << "Animal is eating." << std::endl;
    }

    int getAge() const {
        return age;//���age
    }
};

// ������
class Dog : public Animal {
public:
    Dog(int _age) : Animal(_age) {}

    void bark() {
        std::cout << "Dog is barking." << std::endl;
    }
};

int main() {
    // �������������
    Dog dog(3);

    // ���û���ĳ�Ա����
    dog.eat();

    // �����������Լ��ĳ�Ա����
    dog.bark();

    // ���û���Ĺ��г�Ա������ȡ˽�����Ե�ֵ
    std::cout << "Dog's age: " << dog.getAge() << std::endl;

    return 0;
}

