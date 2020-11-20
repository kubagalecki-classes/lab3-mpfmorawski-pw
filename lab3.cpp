#include <iostream>

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

int main()
{
    Figura figura1;
    figura1.setPole(4);
    std::cout << figura1.getPole() << std::endl;
}
