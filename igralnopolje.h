#ifndef IGRALNOPOLJE_H
#define IGRALNOPOLJE_H
#include <QDebug>

using namespace std;

class IgralnoPolje
{
public:
    int maloPolje[3][3];

    IgralnoPolje();
    bool preveriZmago(int igralecNaPoteziVVelikemPoljem);
    bool preveriCeJeCeloPoljeZasedeno();
    bool jeLegalna(int StevilkaGumbaXmali,int StevilkaGumbaYmali);

};

#endif // IGRALNOPOLJE_H
