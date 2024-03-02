#include <iostream>
#include <cmath>

/* 求最大公约数(辗转相除法) */
int gcd(int a, int b)
{
    int t;
    while(b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

/* 求最小公倍数 */
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

class Point
{
private:
    int x;
    int y;
public:
    Point(int x, int y);
    ~Point();
    void showInfo();
    /* 声明友元 */
    friend double Distance(const Point &p1, const Point &p2);
    friend class Line;
    friend class Circle;
};

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
    // std::cout << "构造函数" << std::endl;
}

Point::~Point()
{
    // std::cout << "析构函数" << std::endl;
}

void Point::showInfo()
{
    std::cout << "Point(" << x << ", " << y << ")" << std::endl;
}

double Distance(const Point &p1, const Point &p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

class Line 
{
private:
    double A;
    double B;
    double C;
public:
    Line(double A, double B, double C);
    Line(const Point &p1, const Point &p2);
    ~Line();
    void showInfo();
};

Line::Line(double A, double B, double C): A(A), B(B), C(C)
{
    // std::cout << "构造函数" << std::endl;
}
Line::Line(const Point &p1, const Point &p2)
{
    A = p1.y - p2.y;
    B = p2.x - p1.x;
    C = p1.x * p2.y - p2.x * p1.y;
    // std::cout << "构造函数" << std::endl;
}
Line::~Line()
{
    // std::cout << "析构" << std::endl;
}
void Line::showInfo()
{
    std::cout << "Line(" << A << ", " << B << ", " << C << ")" << std::endl;
    if(A != 0)
    {
        if(A == 1)
        {
            std::cout << "x +";
        }
        else if(A == -1)
        {
            std::cout << "-x +";
        }
        else
        {
            std::cout << A << "x + ";
        }
    }
    if(B != 0)
    {
        if(B == 1)
        {
            std::cout << "y ";
        }
        else if(B == -1)
        {
            std::cout << "-y ";
        }
        else
        {
            std::cout << B << "y ";
        }
    }
    if(C != 0)
    {
        if(C > 0)
        {
            std::cout << "- " << C;
        }
        else
        {
            std::cout << "+ " << -C;
        }
    }
    std::cout << " = 0" << std::endl;

}

class Circle
{
private:
    Point p;
    int len;
public:
    Circle(Point p, int len);
    ~Circle();
};

Circle::Circle(Point p, int len): p(0,0)
{
}

Circle::~Circle()
{
}


int main()
{
    // Point p1(1, 2);
    // Point p2(4, 6);
    // p1.showInfo();
    // p2.showInfo();
    // std::cout << Distance(p1, p2) << std::endl;
    // Line l1(p1, p2);
    // l1.showInfo();
    std::cout << gcd(18, 14) << std::endl;
    std::cout << lcm(18, 14) << std::endl;
    return 0;
}

