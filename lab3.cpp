#include <iostream>
#include <math.h>

class Figura
{
public:
    Figura() : pole{0} { std::cout << "Konstruktor domyslny - Figura" << std::endl; }
    Figura(double p) : pole{p} { std::cout << "Konstruktor parametryczny - Figura" << std::endl; }
    ~Figura() { std::cout << "Destruktor - Figura" << std::endl; }

    virtual void id() const;

    double getPole() const;

private:
    double pole;
};

void Figura::id() const
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

    void id() const override;
};

void Kwadrat::id() const
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

    void id() const override;
};

void Kolo::id() const
{
    std::cout << "Typ: Kolo,  Pole: " << getPole() << std::endl;
}

void id(const Figura& figura)
{
    figura.id();
}

int main()
{
    Figura figura{18};
    figura.id();
    id(figura);
    Kwadrat kwadrat{8};
    kwadrat.id();
    id(kwadrat);
    Kolo kolo{1};
    kolo.id();
    id(kolo);
}

/* Po uruchomieniu otrzymano
  Konstruktor parametryczny - Figura
  Typ: Figura,  Pole: 18
  Typ: Figura,  Pole: 18
  Konstruktor parametryczny - Figura
  Konstruktor parametryczny - Kwadrat
  Typ: Kwadrat,  Pole: 64
  Typ: Kwadrat,  Pole: 64
  Konstruktor parametryczny - Figura
  Konstruktor parametryczny - Kolo
  Typ: Kolo,  Pole: 3.14159
  Typ: Kolo,  Pole: 3.14159
  Destruktor - Kolo
  Destruktor - Figura
  Destruktor - Kwadrat
  Destruktor - Figura
  Destruktor - Figura
*/