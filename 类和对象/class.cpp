#include <iostream>
#include <string>


class Student
{
    private:
        /* 私有变量 
        无法直接通过诸如 
        s.m_age = 10; 
        直接进行设置 */
        int m_age;
        std::string m_name;
    public:
        void setAge(int age)
        {
            m_age = age;
        }
        int getAge()
        {
            return m_age;
        }
        void setName(const std::string& name)
        {
            m_name = name;
        }
        // 类内声明 
        std::string getName();
        void showStudentInfo();
        
        // 无参构造  
        Student()
        {
            std::cout << "无参构造" << std::endl;
            m_name = "zhangsan";
            m_age = 20;
        }
        // 带参构造     
        Student(std::string name, int age)
        {
            m_name = name;
            m_age = age;
        }
        // 重载构造函数
        Student(std::string name)
        {
            m_name = name;
            m_age = 20;
        }

        // 复制构造函数
        Student(const Student& s)
        {
            std::cout << "拷贝构造函数" << std::endl;
            m_name = s.m_name;
            m_age = s.m_age;
        }

        // 赋值运算符的重载函数
        void operator=(const Student& s)
        {
            std::cout << "赋值运算符的重载函数" << std::endl;
        }

        // 析构函数
        ~Student()
        {
            std::cout << "析构函数" << std::endl;
        }
};

// 类外定义
std::string Student::getName()
{
    return m_name;
}

void Student::showStudentInfo()
{
    std::cout <<" name:" << m_name << "age:" << m_age <<  std::endl;
}

void func(Student& s)
{
    /* 使用Student s 会进行一次拷贝,增大使用量 */
    s.showStudentInfo();
}

int main()
{
#if 0
    Student s("zhangsan",20);
    // s.setAge(20);
    // s.setName("zhangsan");

    // 复制构造函数
    Student s1(s);
    /* 等效于
    Student s1 = s;*/

    // 无参生成后, 赋值运算符重载函数
    Student s2;
    s2 = s;

    std::cout << s.getAge() << std::endl;
    std::cout << s.getName() << std::endl;
#elif 1
    Student *p = new Student;   // 无参构造, 空间申请时触发
    delete p;                   // 触发析构函数, 空间释放时自动触发

#endif 
    return 0;
}