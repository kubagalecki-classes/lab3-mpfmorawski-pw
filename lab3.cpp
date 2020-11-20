#include <iostream>
#include <math.h>

class Figura
{
public:
    void   setPole(double);
    double getPole() const;

private:
    double pole;
};

void Figura::setPole(double p)
{
    pole = p;
}
double Figura::getPole() const
{
    return pole;
}

class Kwadrat : public Figura
{
public:
    Kwadrat() { setPole(0); }
    Kwadrat(double a) { setPole(a * a); }
};

class Kolo : public Figura
{
public:
    Kolo() { setPole(0); }
    Kolo(double r) { setPole(M_PI * r * r); }
};

int main()
{
    Kwadrat kwadrat{8};
    std::cout << kwadrat.getPole() << std::endl;
    Kolo kolo{1};
    std::cout << kolo.getPole() << std::endl;
}
