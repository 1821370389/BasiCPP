#include <iostream>

class Light // 灯光
{
public:
    void on()
    {
        std::cout << "开灯" << std::endl;
    }
    void off()
    {
        std::cout << "关灯" << std::endl;
    }
};

class TV    // 电视
{
public:
    void on()
    {
        std::cout << "开电视" << std::endl;
    }
    void off()
    {
        std::cout << "关电视" << std::endl;
    }
};

class Voice // 音响
{
public:
    void on()
    {
        std::cout << "开音响" << std::endl;
    }
    void off()
    {
        std::cout << "关音响" << std::endl;
    }
};

class HomeSystem
{
public:
    void movie()
    {
        light.off();
        tv.on();
        voice.on();
    }
    void sleep()
    {
        light.off();
        tv.off();
        voice.off();
    }
private:
    Light light;
    TV tv;
    Voice voice;
};

int main()
{
#if 0
    Light light;
    TV tv;
    Voice voice;

    light.on();
    tv.on();
    voice.on();

    light.off();
    tv.off();
    voice.off();
#else
    HomeSystem home;
    home.movie();
#endif
    return 0;
}