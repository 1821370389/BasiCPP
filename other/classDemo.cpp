#include <iostream>
#include <string>

class Person
{
    private:
        int UserID;
    protected:
        std::string name;
        std::string sex;
    public:
        Person(int UserID, const std::string& name, std::string sex)
        {
            this->UserID = UserID;
            this->name = name;
            this->sex = sex;
        }
        void displayInfo() 
        {
            std::cout << "UserID:" << UserID << ", Name:" << name << ", Sex:" << sex << ", " << std::ends;
        }
};

class Student : public Person 
{
    private:
        /* 成员变量
        类中的成员变量是描述对象的状态或特征的数据。
        它们被声明在类的内部，并且可以通过成员函数进行访问和修改。*/
        int age;

    public:
        /* 构造函数,一种特殊的成员函数，用于初始化对象的状态。
            它在对象创建时自动调用，没有返回类型，与类同名。*/
        Student(int UserID, const std::string& name, const std::string& sex, int age) 
        : Person(UserID, name, sex), age(age)
        {
            // this->UserID = UserID;
            this->name = name;
            this->sex = sex;
            this->age = age;
            std::cout << "构造了一个学生对象" << std::endl;
        }

        /* 成员函数,与类相关联的函数，用于操作类的数据成员。
        它们在类定义内部声明，并通过类的对象进行调用。*/
        void displayInfo() 
        {
            Person::displayInfo();
            std::cout << "Name: " << name << ", Sex: " << sex << ", age: " << age << std::endl;
        }

        int getAge() 
        {
            return age;
        }
};

int main() 
{
    // 创建 Student 类的对象，并传递参数给构造函数
    Student myStudent(1231,"LiHua", "man", 21);

    // 调用成员函数显示学生信息
    myStudent.displayInfo();

    std::cout << "Age: " << myStudent.getAge() << std::endl;

    return 0;
}
