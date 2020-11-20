#include <iostream>
#include <math.h>

class Figura
{
public:
    double getPole() const;

protected:
    double pole;
};

double Figura::getPole() const
{
    return pole;
}

class Kwadrat : public Figura
{
public:
    Kwadrat() { pole = 0.; }
    Kwadrat(double a) { pole = a * a; }
};

class Kolo : public Figura
{
public:
    Kolo() { pole = 0.; }
    Kolo(double r) { pole = M_PI * r * r; }
};

int main()
{
    Kwadrat kwadrat{8};
    std::cout << kwadrat.getPole() << std::endl;
    Kolo kolo{1};
    std::cout << kolo.getPole() << std::endl;
}
