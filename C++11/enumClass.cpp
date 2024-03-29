#include <iostream>

enum class Color : char // : char ,将类型限制为char(一字节)，以节省空间
{
    RED,
    GREEN,
    BLUE
};

enum class thickness
{
    thin,
    fat
};

int main()
{
    // if (Color::RED == thickness::thin)
    // {
    //     std::cout << "red thin" << std::endl;
    // }
    return 0; 
}