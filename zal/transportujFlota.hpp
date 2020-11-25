#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int przetransportowany_towar = 0;
    unsigned int zaglowiec_counter = 0;
    while(przetransportowany_towar < towar)
    {
      Stocznia stocznia{};
      Statek* statek = stocznia();
      przetransportowany_towar += (statek->transportuj());
      if ((dynamic_cast<Zaglowiec *>(statek)) != nullptr)
        zaglowiec_counter++;
      delete statek;
    }
    return zaglowiec_counter;
}