#pragma once
#if 0
/* 头文件 */
template <typename T>

T myAdd(T a, T b);

#else
template <typename T>
T myAdd(T a, T b)
{
    return a + b;
}
/* 模板不能在头文件声明, 在cpp实现 */
#endif