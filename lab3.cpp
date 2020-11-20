#include <iostream>
#include <math.h>

class Figura
{
public:
    Figura() : pole{0} { std::cout << "Konstruktor domyslny - Figura" << std::endl; }
    Figura(double p) : pole{p} { std::cout << "Konstruktor parametryczny - Figura" << std::endl; }
    ~Figura() { std::cout << "Destruktor - Figura" << std::endl; }

    void id();

    double getPole() const;

private:
    double pole;
};

void Figura::id()
{
    std::cout << "Typ: Figura,  Pole: " << pole << std::endl;
}

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

    void id();
};

void Kwadrat::id()
{
    std::cout << "Typ: Kwadrat,  Pole: " << getPole() << std::endl;
}

class Kolo : public Figura
{
public:
    Kolo() : Figura{0.} { std::cout << "Konstruktor domyslny - Kolo" << std::endl; }
    Kolo(double r) : Figura{M_PI * r * r}
    {
        std::cout << "Konstruktor parametryczny - Kolo" << std::endl;
    }
    ~Kolo() { std::cout << "Destruktor - Kolo" << std::endl; }

    void id();
};

void Kolo::id()
{
    std::cout << "Typ: Kolo,  Pole: " << getPole() << std::endl;
}

int main()
{
    Figura figura{18};
    figura.id();
    Kwadrat kwadrat{8};
    kwadrat.id();
    Kolo kolo{1};
    kolo.id();
}
