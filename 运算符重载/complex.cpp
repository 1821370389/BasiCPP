#include <iostream>


class Complex
{
private:
    int real;
    int vir;
public:
    Complex(int real, int vir);
    ~Complex();
    void showInfo();
    Complex add(Complex &c);
    Complex operator+(Complex &c);
    Complex operator-(Complex &c);
    /*
    std::ostream& operator<<(std::ostream &os);
    */
    friend std::ostream& operator<<(std::ostream &os, const Complex &c);
    friend std::istream& operator>>(std::istream &is, Complex &c);

    /* 前置 */
    Complex operator++();
    /* 后置 */
    Complex operator++(int);
};

Complex::Complex(int real, int vir) : real(real), vir(vir)
{
    std::cout << "Complex()" << std::endl;
}

Complex::~Complex()
{
    std::cout << "~Complex()" << std::endl;
}

void Complex::showInfo()
{
    std::cout << "real: " << real << " vir: " << vir << std::endl;
}

Complex Complex::add(Complex &c)
{
    return Complex(real + c.real, vir + c.vir);
}

Complex Complex::operator+(Complex &c)
{
    return Complex(real + c.real, vir + c.vir);
}

Complex Complex::operator-(Complex &c)
{
    return Complex(real - c.real, vir - c.vir);
}

/*
std::ostream& Complex::operator<<(std::ostream &os)
{
    os << "real: " << real << " vir: " << vir << std::endl;
    return os;
}
c3 << std::cout;
*/

std::ostream& operator<<(std::ostream &os , const Complex &c)
{
    os << "real: " << c.real << " vir: " << c.vir ;
    return os;
}

std::istream& operator>>(std::istream &is, Complex &c)
{
    is >> c.real >> c.vir;
    return is;
}

Complex Complex::operator++()
{
    real++;
    vir++;
    return *this;
}

Complex Complex::operator++(int)
{
    Complex tmp = *this;
    real++;
    vir++;
    return tmp;
}



int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex c3 = c1.add(c2);
    std::cout << c3 << std::endl;
    std::cin >> c2;
    Complex c4 = c1 + c2;
    c4.showInfo();

    return 0;
}
