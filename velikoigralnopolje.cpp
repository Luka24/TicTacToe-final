#include "velikoigralnopolje.h"

int VelikoIgralnoPolje::getZadnjaPotezaX() const
{
    return zadnjaPotezaX;
}

void VelikoIgralnoPolje::setZadnjaPotezaX(int newZadnjaPotezaX)
{
    zadnjaPotezaX = newZadnjaPotezaX;
}


int VelikoIgralnoPolje::getZadnjaPotezaY() const
{
    return zadnjaPotezaY;
}

void VelikoIgralnoPolje::setZadnjaPotezaY(int newZadnjaPotezaY)
{
    zadnjaPotezaY = newZadnjaPotezaY;
}


int VelikoIgralnoPolje::getPoljeNaslednjePotezeX() const
{
    return poljeNaslednjePotezeX;
}

void VelikoIgralnoPolje::setPoljeNaslednjePotezeX(int newPoljeNaslednjePotezeX)
{
    poljeNaslednjePotezeX = newPoljeNaslednjePotezeX;
}

int VelikoIgralnoPolje::getPoljeNaslednjePotezeY() const
{
    return poljeNaslednjePotezeY;
}

void VelikoIgralnoPolje::setPoljeNaslednjePotezeY(int newPoljeNaslednjePotezeY)
{
    poljeNaslednjePotezeY = newPoljeNaslednjePotezeY;
}

int VelikoIgralnoPolje::getIgralecNaPotezi() const
{
    return igralecNaPotezi;
}

void VelikoIgralnoPolje::setIgralecNaPotezi(int newIgralecNaPotezi)
{
    igralecNaPotezi = newIgralecNaPotezi;
}

bool VelikoIgralnoPolje::getIgraProtiRacunalniku() const
{
    return IgraProtiRacunalniku;
}

void VelikoIgralnoPolje::setIgraProtiRacunalniku(bool newIgraProtiRacunalniku)
{
    IgraProtiRacunalniku = newIgraProtiRacunalniku;
}

VelikoIgralnoPolje::VelikoIgralnoPolje()
{

}

void VelikoIgralnoPolje::poljeNaslednjePoteze()
{
    bool prosto = false;

    if (maloPolje[zadnjaPotezaX][zadnjaPotezaY] != 0){//ce je veliko polje, kjer naj bi bila naslednja poteza, zasedeno, z -1 oznaci, da lahko naredis potezo v katerikoli kvadrat
        poljeNaslednjePotezeX = -1;
        poljeNaslednjePotezeY = -1;
    }
    else{
        for (int i = 0; i<9; i++){
            for (int j = 0; j<9; j++){
                if (velikoPolje[zadnjaPotezaX][zadnjaPotezaY].maloPolje[i][j]==0){
                    prosto = true;
                    break;
                 }
            }
        }
        if(prosto){//ce je se kaksno mesto v kvadratu prosto, potem lahko naredis potezo tja
            poljeNaslednjePotezeX = zadnjaPotezaX;
            poljeNaslednjePotezeY = zadnjaPotezaY;
        }
        else{
            poljeNaslednjePotezeX = -1;
            poljeNaslednjePotezeY = -1;
        }
    }
}

void VelikoIgralnoPolje::spremembaIgralca(){
    if (igralecNaPotezi == 1)
        igralecNaPotezi += 1;
    else
        igralecNaPotezi -= 1;
}

bool VelikoIgralnoPolje::jeLegalna(int stevilkaGumbaXveliki, int stevilkaGumbaYveliki){
        if(poljeNaslednjePotezeX == -1 && maloPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki] == 0){
            return true;
        }
        else if(poljeNaslednjePotezeX == stevilkaGumbaXveliki && poljeNaslednjePotezeY == stevilkaGumbaYveliki){
            return true;
        }
        return false;

}
int VelikoIgralnoPolje::izberiPoljeZaRacunalnik(){
    int izbranIndeks;
    do{
        izbranIndeks = rand()%81;
    }while(!velikoPolje[(izbranIndeks/9)/3][(izbranIndeks/9)%3].jeLegalna((izbranIndeks%9)/3, (izbranIndeks%9)%3) || !jeLegalna((izbranIndeks/9)/3, (izbranIndeks/9)%3));
    return izbranIndeks;
}
