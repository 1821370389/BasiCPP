#include <iostream>
#include <map>


struct Student
{
    int age;
    std::string name;
};


int main()
{
    std::pair<int, Student> s;
    s.first = 1;
    s.second = {1, "张三"};
    std::cout << s.first << " " << s.second.name << " " << s.second.age << std::endl;
    // std::pair<int, Student> s1 = {2, {2, "李四"}};
    std::pair<int, Student> s1 = std::make_pair<int,Student>(2,{2,"李四"});
    std::cout << s1.first << " " << s1.second.name << " " << s1.second.age << std::endl;
    
    std::map<int, Student> m;   // 以队组first排序的容器
    m.insert(s);
    m.insert(s1);
    std::cout << m[1].name << " " << m[1].age << std::endl;
    std::cout << m[2].name << " " << m[2].age << std::endl;
    
    return 0;
}