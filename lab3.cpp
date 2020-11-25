#include <iostream>
#include <math.h>

const int SIZE = 5;

/* BYT GEOMETRYCZNY */

class BytGeometryczny
{
public:
    virtual void id() const = 0;
};

/* KONIEC BYT GEOMETRYCZNY */

/* FIGURA */

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

/* KONIEC FIGURA */

/* KWADRAT */

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

/* KONIEC KWADRAT */

/* KOLO */

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

/* KONIEC KOLO */

void id(const Figura& figura)
{
    figura.id();
}

/* WEKTOR FIGUR */
class WektorFigur
{
public:
    WektorFigur() : counter{0}
    {
        std::cout << "Konstruktor domyslny - Wektor figur" << std::endl;
        wektor_figur = new Figura[SIZE];
    }
    ~WektorFigur()
    {
        std::cout << "Destruktor - Wektor figur" << std::endl;
        delete[] wektor_figur;
    }

    Figura* operator[](int) const;

private:
    Figura* wektor_figur;
    int     counter;
};

Figura* WektorFigur::operator[](int i) const
{
    if (i < counter)
        return &wektor_figur[i];
    else
        return nullptr;
}

/* KONIEC WEKTOR FIGUR */

int main()
{
    WektorFigur wektor;
}

/* Po uruchomieniu otrzymanp:
  Konstruktor domyslny - Wektor figur
  Konstruktor domyslny - Figura
  Konstruktor domyslny - Figura
  Konstruktor domyslny - Figura
  Konstruktor domyslny - Figura
  Konstruktor domyslny - Figura
  Destruktor - Wektor figur
  Destruktor - Figura
  Destruktor - Figura
  Destruktor - Figura
  Destruktor - Figura
  Destruktor - Figura
*/