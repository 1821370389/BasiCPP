#include <iostream>

namespace A
{
    const int size = 10;
} // namespace A

namespace B
{
    const int size = 20;
} // namespace B

int main()
{

/*
    const int  a = 10;
    int *p = (int *) &a;
    printf("*p:%d, p:%p\n",*p,p);
    *p = 20;
    
    printf("*p:%d, &a:%p, p:%p\n",*p, &a, p);
*/
    std::cout<<A::size<<std::endl;
    return 0;
}