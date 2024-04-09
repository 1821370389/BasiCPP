#include <iostream>

using namespace std;
class Color
{
public:
    virtual void paint(const string& pentype, const string& name) = 0;
};
class Red : public Color
{
public:
    void paint(const string& pentype, const string& name)
    {
        cout << pentype << "画红色的" << name <<  endl;
    }
};
class Blue : public Color
{
public:
    void paint(const string& pentype, const string& name)
    {
        cout << pentype << "画蓝色的" << name << endl;
    }
};

class Pen
{
public:
    void SetColor(Color* color)
    {
        this->color = color;
    }
    virtual void Draw(const string& name) = 0;

protected:
    Color* color;
};

class Pencil : public Pen
{
public:
    void Draw(const string& name)
    {
        this->color->paint("铅笔", name);
    }
};
class writingBrush : public Pen
{
public:
    void Draw(const string& name)
    {
        this->color->paint("毛笔", name);
    }
};

int main()
{
    Color* color = new Red();
    Pen* pen = new Pencil();
    Color* color2 = new Blue();
    Pen* pen2 = new writingBrush();
    pen->SetColor(color);
    pen2->SetColor(color2);
    pen->Draw("太阳");
    pen2->Draw("大海");
    return 0;
}