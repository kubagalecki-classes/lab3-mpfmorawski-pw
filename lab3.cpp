#include <iostream>
#include <math.h>

class Figura
{
public:
    Figura() : pole{0} { std::cout << "Konstruktor domyslny - Figura" << std::endl; }
    Figura(double p) : pole{p} { std::cout << "Konstruktor parametryczny - Figura" << std::endl; }
    ~Figura() { std::cout << "Destruktor - Figura" << std::endl; }

    double getPole() const;

private:
    double pole;
};

double Figura::getPole() const
{
    return pole;
}

class Kwadrat : public Figura
{
public:
    Kwadrat() : Figura{0.} { std::cout << "Konstruktor domyslny - Kwadrat" << std::endl; }
    Kwadrat(double a) : Figura{a * a}
    {
        std::cout << "Konstruktor parametryczny - Kwadrat" << std::endl;
    }
    ~Kwadrat() { std::cout << "Destruktor - Kwadrat" << std::endl; }
};

class Kolo : public Figura
{
public:
    Kolo() : Figura{0.} { std::cout << "Konstruktor domyslny - Kolo" << std::endl; }
    Kolo(double r) : Figura{M_PI * r * r}
    {
        std::cout << "Konstruktor parametryczny - Kolo" << std::endl;
    }
    ~Kolo() { std::cout << "Destruktor - Kolo" << std::endl; }
};

int main()
{
    Kwadrat kwadrat{8};
    std::cout << kwadrat.getPole() << std::endl;
    Kolo kolo{1};
    std::cout << kolo.getPole() << std::endl;
}
