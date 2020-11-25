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
    Figura* f = new Kwadrat{4}; // DYNAMICZNIE TWORZONY KWADRAT
    std::cout << "Dyn. rzut. na Kwadrat*: " << dynamic_cast< Kwadrat* >(f) << std::endl;
    std::cout << "Dyn. rzut. na Kolo*: " << dynamic_cast< Kolo* >(f) << std::endl;
    std::cout << std::endl
              << "Jezeli obiekt, wskaznik do ktorego rzutujemy nie jest tak naprawde typu, na "
                 "ktory rzutujemy, to wynikiem rzutowania jest wyzerowany wskaznik (nullptr)."
              << std::endl;
}

/* Po uruchomieniu otrzymano
  Konstruktor parametryczny - Figura
  Konstruktor parametryczny - Kwadrat
  Dyn. rzut. na Kwadrat*: 0x55756f25be70
  Dyn. rzut. na Kolo*: 0

  Jezeli obiekt, wskaznik do ktorego rzutujemy nie jest tak naprawde typu, na ktory rzutujemy, to wynikiem rzutowania jest wyzerowany wskaznik (nullptr).
*/