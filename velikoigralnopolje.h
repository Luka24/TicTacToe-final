#ifndef VELIKOIGRALNOPOLJE_H
#define VELIKOIGRALNOPOLJE_H
#include "igralnopolje.h"

class VelikoIgralnoPolje: public IgralnoPolje
{
private:
    int zadnjaPotezaX = -1;
    int zadnjaPotezaY = -1;
    int poljeNaslednjePotezeX = -1;
    int poljeNaslednjePotezeY = -1;
    int igralecNaPotezi = 1;
    bool IgraProtiRacunalniku;

public:

    IgralnoPolje velikoPolje[3][3];
    VelikoIgralnoPolje();
    void poljeNaslednjePoteze();
    bool jeLegalna(int stevilkaGumbaXveliki, int stevilkaGumbaYveliki);
    void spremembaIgralca();
    int izberiPoljeZaRacunalnik();


    int getZadnjaPotezaY() const;
    void setZadnjaPotezaY(int newZadnjaPotezaY);
    int getZadnjaPotezaX() const;
    void setZadnjaPotezaX(int newZadnjaPotezaX);
    int getPoljeNaslednjePotezeX() const;
    void setPoljeNaslednjePotezeX(int newPoljeNaslednjePotezeX);
    int getPoljeNaslednjePotezeY() const;
    void setPoljeNaslednjePotezeY(int newPoljeNaslednjePotezeY);
    int getIgralecNaPotezi() const;
    void setIgralecNaPotezi(int newIgralecNaPotezi);
    bool getIgraProtiRacunalniku() const;
    void setIgraProtiRacunalniku(bool newIgraProtiRacunalniku);
};

#endif // VELIKOIGRALNOPOLJE_H
