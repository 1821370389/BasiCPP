#include<iostream>
#include<vector>

void printVector(std::vector<int> &vec)
{
    std::cout << "size: " << vec.size() << " capacity:" << vec.capacity() << std::endl;

    for(auto item : vec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main()
{
/*
    std::vector<int> vec{1,2,3,4,5,6};
    std::cout << "size: " << vec.size() << " capacity:" << vec.capacity() << std::endl;
#if 0

    for(int item : vec)
    {
        std::cout << item << std::endl;
    }
    std::cout << "——————————————" << std::endl;

#elif 0

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout<<vec[i]<<std::endl;
    }
    std::cout << "——————————————" << std::endl;

#elif 0

    // std::vector<int>::iterator ite = vec.begin();    // 迭代器
    auto ite = vec.begin();
    std::cout << *ite++ << std::endl;
    auto ite_end = vec.end();
    std::cout << *--ite_end << std::endl;
    // 容器遍历更推荐 
    for(auto ite = vec.begin(); ite != vec.end(); ite++)
    {
        std::cout << *ite << std::endl;
    }

#endif
*/

    std::vector<int> vec;

    // 尾插
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    printVector(vec);

    // 尾删
    vec.pop_back();
    printVector(vec);

    // 中间增删 效率低,不推荐
    vec.insert(vec.begin()+1, 10);
    printVector(vec);

    vec.erase(vec.begin()+1);
    printVector(vec);

    std::cout << "vec[3]: " << vec[3] << std::endl;
    // std::cout << "vec.at(3): " << vec.at(3) << std::endl;   // 越界后at()会抛出异常,[]不会
    std::cout << "vec.front(): " << vec.front() << std::endl;
    std::cout << "vec.max_size():" << vec.max_size() << std::endl;

    vec.reserve(8);         // 设置容积
    printVector(vec);
    vec.shrink_to_fit();    // 自调整缩容
    printVector(vec);   
    return 0;
}