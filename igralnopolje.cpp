#include "igralnopolje.h"

IgralnoPolje::IgralnoPolje()
{
    for (int j = 0 ; j<3; j++){
        for (int i = 0 ; i<3; i++){
           maloPolje[j][i]=0;
        }
    }
}

bool IgralnoPolje::preveriZmago(int igralecNaPoteziVVelikemPoljem){
    if (maloPolje[0][0]==igralecNaPoteziVVelikemPoljem && maloPolje[0][1]==igralecNaPoteziVVelikemPoljem && maloPolje[0][2]==igralecNaPoteziVVelikemPoljem)
        return true;
    else if (maloPolje[0][0]==igralecNaPoteziVVelikemPoljem && maloPolje[1][0]==igralecNaPoteziVVelikemPoljem && maloPolje[2][0]==igralecNaPoteziVVelikemPoljem)
        return true;
    else if (maloPolje[0][0]==igralecNaPoteziVVelikemPoljem && maloPolje[1][1]==igralecNaPoteziVVelikemPoljem && maloPolje[2][2]==igralecNaPoteziVVelikemPoljem)
        return true;
    else if (maloPolje[0][1]==igralecNaPoteziVVelikemPoljem && maloPolje[1][1]==igralecNaPoteziVVelikemPoljem && maloPolje[2][1]==igralecNaPoteziVVelikemPoljem)
        return true;
    else if (maloPolje[1][0]==igralecNaPoteziVVelikemPoljem && maloPolje[1][1]==igralecNaPoteziVVelikemPoljem && maloPolje[1][2]==igralecNaPoteziVVelikemPoljem)
        return true;
    else if (maloPolje[2][0]==igralecNaPoteziVVelikemPoljem && maloPolje[2][1]==igralecNaPoteziVVelikemPoljem && maloPolje[2][2]==igralecNaPoteziVVelikemPoljem)
        return true;
    else if (maloPolje[0][2]==igralecNaPoteziVVelikemPoljem && maloPolje[1][2]==igralecNaPoteziVVelikemPoljem && maloPolje[2][2]==igralecNaPoteziVVelikemPoljem)
        return true;
    else if (maloPolje[0][2]==igralecNaPoteziVVelikemPoljem && maloPolje[1][1]==igralecNaPoteziVVelikemPoljem && maloPolje[2][0]==igralecNaPoteziVVelikemPoljem)
        return true;
    else
        return false;
}

bool IgralnoPolje::preveriCeJeCeloPoljeZasedeno(){
    for (int j = 0 ; j<3; j++){
        for (int i = 0 ; i<3; i++){
           if (maloPolje[j][i]==0)
               return false;
        }
    }
    return true;
}

bool IgralnoPolje::jeLegalna(int stevilkaGumbaXmali,int stevilkaGumbaYmali){
        if (maloPolje[stevilkaGumbaXmali][stevilkaGumbaYmali] == 0)
            return true;
        return false;
}
