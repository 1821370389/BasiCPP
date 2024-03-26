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
    m.insert({3,{3,"王五"}});
    m[2] = s1.second;
    m.insert({3,{4,"王五"}});   // 同set相似,重复的键值无法插入
    m[3] = {5,"wangwu"};        // [] 可以对键值进行修改
    for(auto &p : m)
    {
        std::cout << p.first << " " << p.second.age << " " << p.second.name << std::endl;
    }
    std::cout << "-----------------" << std::endl;
    for(auto ite = m.begin(); ite != m.end(); ite++)
    {
        std::cout << ite->first  << " " << ite->second.age<< " " << ite->second.name << std::endl;
    }
    std::cout << "-----------------" << std::endl;
    auto ite = m.find(3);
    if(ite != m.end())
    {
        std::cout << ite->first << " " << ite->second.age << " " << ite->second.name << std::endl;
    }
    
    return 0;
}