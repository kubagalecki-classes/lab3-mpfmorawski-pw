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
        wektor_figur = new Figura*[SIZE];
    }
    ~WektorFigur()
    {
        std::cout << "Destruktor - Wektor figur" << std::endl;
        if (*wektor_figur != nullptr) {
            for (int i = 0; i < counter; i++)
                delete wektor_figur[i];
            delete[] wektor_figur;
        }

        // for (int i = 0; i < counter; i++)
        //     delete &wektor_figur[i];
    }

    void    push(Figura*);
    void    pop();
    Figura* operator[](int) const;

private:
    Figura** wektor_figur;
    int      counter;
};

Figura* WektorFigur::operator[](int i) const
{
    if (i < counter)
        return wektor_figur[i];
    else
        return nullptr;
}

void WektorFigur::push(Figura* fig)
{
    wektor_figur[counter] = fig;
    counter++;
}

void WektorFigur::pop()
{
    if (counter > 0) {
        delete wektor_figur[counter - 1];
        counter--;
    }
}

/* KONIEC WEKTOR FIGUR */

int main()
{
    WektorFigur wektor;

    Kwadrat* kwad1ptr = new Kwadrat{4};
    Kolo*    kolo1ptr = new Kolo{3};
    Kwadrat* kwad2ptr = new Kwadrat{2};

    wektor.push(kwad1ptr);
    wektor.push(kolo1ptr);
    wektor.pop();
    wektor.push(kwad2ptr);

    wektor[0]->id();
    wektor[1]->id();
}

/* Po uruchomieniu otrzymano:
  Konstruktor domyslny - Wektor figur
  Konstruktor parametryczny - Figura
  Konstruktor parametryczny - Kwadrat
  Konstruktor parametryczny - Figura
  Konstruktor parametryczny - Kolo
  Konstruktor parametryczny - Figura
  Konstruktor parametryczny - Kwadrat
  Destruktor - Kolo
  Destruktor - Figura
  Typ: Kwadrat,  Pole: 16
  Typ: Kwadrat,  Pole: 4
  Destruktor - Wektor figur
  Destruktor - Kwadrat
  Destruktor - Figura
  Destruktor - Kwadrat
  Destruktor - Figura
*/