#include <iostream>
#include <math.h>

const int SIZE = 5;

class WizytatorFigurBaza;
class WizytatorDrukujacy;
class BytGeometryczny;
class Figura;
class Kwadrat;
class Kolo;
class WektorFigur;
class FabrykaFigur;

/* WIZYTATOR FIGUR BAZA */

class WizytatorFigurBaza
{
public:
    virtual void wizytuj(Kwadrat&) = 0;
    virtual void wizytuj(Kolo&)    = 0;
};

/* KONIEC WIZYTATOR FIGUR BAZA */

/* WIZYTATOR DRUKUJĄCY */

class WizytatorDrukujacy : WizytatorFigurBaza
{
public:
    virtual void wizytuj(Kwadrat&) { std::cout << "Wiz. Drukujacy: To jest Kwadrat." << std::endl; }
    virtual void wizytuj(Kolo&) { std::cout << "Wiz. Drukujacy: To jest Kolo." << std::endl; }
};

/* WIZYTATOR DRUKUJĄCY */

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

    virtual void id() const override;
    virtual void akceptuj(WizytatorFigurBaza&) = 0;
    virtual void akceptuj(WizytatorDrukujacy&) = 0;

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
    void akceptuj(WizytatorFigurBaza&) override;
    void akceptuj(WizytatorDrukujacy&) override;
};

void Kwadrat::id() const
{
    std::cout << "Typ: Kwadrat,  Pole: " << getPole() << std::endl;
}

void Kwadrat::akceptuj(WizytatorFigurBaza& v)
{
    v.wizytuj(*this);
}

void Kwadrat::akceptuj(WizytatorDrukujacy& v)
{
    v.wizytuj(*this);
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
    void akceptuj(WizytatorFigurBaza&) override;
    void akceptuj(WizytatorDrukujacy&) override;
};

void Kolo::id() const
{
    std::cout << "Typ: Kolo,  Pole: " << getPole() << std::endl;
}

void Kolo::akceptuj(WizytatorFigurBaza& v)
{
    v.wizytuj(*this);
}

void Kolo::akceptuj(WizytatorDrukujacy& v)
{
    v.wizytuj(*this);
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
    void    idWszystkie();
    void    wizytujWszystkie(WizytatorFigurBaza&);
    void    wizytujOrazDrukujWszystkie(WizytatorDrukujacy&);

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

void WektorFigur::idWszystkie()
{
    for (int i = 0; i < counter; i++)
        wektor_figur[i]->id();
}

void WektorFigur::wizytujWszystkie(WizytatorFigurBaza& v)
{
    for (int i = 0; i < counter; i++)
        wektor_figur[i]->akceptuj(v);
}

void WektorFigur::wizytujOrazDrukujWszystkie(WizytatorDrukujacy& v)
{
    for (int i = 0; i < counter; i++)
        wektor_figur[i]->akceptuj(v);
}

/* KONIEC WEKTOR FIGUR */

/* FABRYKA FIGUR */

class FabrykaFigur
{
public:
    Figura* operator()(const std::string&, double);
};

Figura* FabrykaFigur::operator()(const std::string& nazwa, double wymiar)
{
    if (nazwa == "kwadrat")
        return (new Kwadrat{wymiar});
    else if (nazwa == "kolo")
        return (new Kolo{wymiar});
    else
        return nullptr;
}

/* KONIEC FABRYKA FIGUR */

int main()
{
    WektorFigur        wektor;
    FabrykaFigur       ff;
    WizytatorDrukujacy wd;

    wektor.push(ff("kwadrat", 4));
    wektor.push(ff("kolo", 3));
    wektor.pop();
    wektor.push(ff("kwadrat", 2));
    wektor.push(ff("kolo", 1));
    wektor.idWszystkie();
    wektor.wizytujOrazDrukujWszystkie(wd);
}

/* Po uruchomieniu otrzymano:
  Konstruktor domyslny - Wektor figur
  Konstruktor parametryczny - Figura
  Konstruktor parametryczny - Kwadrat
  Konstruktor parametryczny - Figura
  Konstruktor parametryczny - Kolo
  Destruktor - Kolo
  Destruktor - Figura
  Konstruktor parametryczny - Figura
  Konstruktor parametryczny - Kwadrat
  Konstruktor parametryczny - Figura
  Konstruktor parametryczny - Kolo
  Typ: Kwadrat,  Pole: 16
  Typ: Kwadrat,  Pole: 4
  Typ: Kolo,  Pole: 3.14159
  Wiz. Drukujacy: To jest Kwadrat.
  Wiz. Drukujacy: To jest Kwadrat.
  Wiz. Drukujacy: To jest Kolo.
  Destruktor - Wektor figur
  Destruktor - Kwadrat
  Destruktor - Figura
  Destruktor - Kwadrat
  Destruktor - Figura
  Destruktor - Kolo
  Destruktor - Figura
*/