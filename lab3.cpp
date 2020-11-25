#include <iostream>
#include <math.h>

class BytGeometryczny
{
public:
    virtual void id() const = 0;
};

class Figura : public BytGeometryczny
{
public:
    Figura() : pole{0} { std::cout << "Konstruktor domyslny - Figura" << std::endl; }
    Figura(double p) : pole{p} { std::cout << "Konstruktor parametryczny - Figura" << std::endl; }
    virtual ~Figura() { std::cout << "Destruktor - Figura" << std::endl; }

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
    virtual ~Kwadrat() { std::cout << "Destruktor - Kwadrat" << std::endl; }

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
    virtual ~Kolo() { std::cout << "Destruktor - Kolo" << std::endl; }

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
    // BytGeometryczny byt; //Tak nie mozna zrobic. 1
    // Figura figura; // 2
    return 0;
}

/* 1
  Nie udalo sie skompilowac, jesli probowalismy utworzyc obiekt typu BytGeometryczny
*/

/* 2
  Rowniez nie udalo sie skompilowac. Trzeba zdefiniowac metode id() dla figury.
*/