/* C++11新特性 
    1. auto  自识别类型, 建议少用会增加阅读难度
    2. decltype  自识别参数类型, 并返回一个用于声明的类型 用来识别auto
    3. declval  是一个函数模板，用于在不创建对象的情况下生成一个对应类型的右值引用。通常情况下，它用于在模板编程中获取一个类型的临时对象，以便进行类型推导或者调用成员函数
    4. nullptr  空指针
    5. static_assert  静态断言
    6. constexpr  常量表达式
    7. noexcept  无except
    8. thread_local  线程局部变量
    9. alignas  对齐
    10. alignof  对齐
    11. constinit  常量初始化
    12. [[nodiscard]]  返回值不可引用
    13. [[maybe_unused]]  不做检查
    14. 快速遍历 
*/
#include <iostream>
using namespace std;


int main()
{
/* auto */
#if 0
    auto num = 666;
    cout << "num = " << num << endl;

    auto str = "hello world";
    cout << "str = " << str << endl;

    auto* p = new int(666);
    cout << "p = " << *p << endl;
#endif

/* decltype */
#if 0
    int num = 666;
    decltype(num) num2 = 666;
    cout << "num = " << num << endl;
    cout << "num2 = " << num2 << endl;
    
    auto str = "hello world";
    decltype(str) str2 = "hello world";
    cout << "str = " << str << endl;
    cout << "str2 = " << str2 << endl;
#endif

/* nullptr */
#if 0
    int* p = nullptr;
    cout << "p = " << p << endl;
#endif

/* 快速遍历 */
#if 0
    #if 0
    int array[] = {1, 2, 3, 4, 5};  // 等效于下面
    #else
    int array[]{1,2,3,4,5};     // 使代码更简洁
    #endif
    #if 0
    for(int idx = 0; idx < sizeof(array)/sizeof(array[0]); idx++)
    {
        cout << array[idx] << endl;
    }
    #else       // 同上
    // for(int item : array)
    for(auto& item : array) // auto,自动识别类型;&,引用节省空间
    {
        cout << item << endl;
    }
    #endif
#endif
    return 0;
}

#if 0
/* declval */
#if 1
#include <utility>

class Foo {
public:
    void bar()
    {
        std::cout << "Foo::bar()" << std::endl;
    }
};

// 在模板中使用 declval 获取 Foo 的右值引用，以便调用成员函数
template<typename T>
void call_bar() {
    decltype(std::declval<T>().bar())(); // 调用 T 类型对象的 bar 成员函数
}

int main() {
    call_bar<Foo>(); // 调用 Foo 类型对象的 bar 成员函数

    return 0;
}

#endif
#endif