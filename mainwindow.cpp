#include "mainwindow.h"
#include "ui_mainwindow.h"

VelikoIgralnoPolje VelikoIgralnoPolje1;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

    //naredi messegebox, da izbere ali igra proti racunalniku ali cloveku
    QMessageBox msgBox;
    msgBox.setWindowTitle("Izbira nasprotnika");
    msgBox.setText("Se zelis preizkusiti proti racunalniku? V tem primeru pritisni Yes, sicer bos moral najti soigralca in pritisniti No.");
    msgBox.addButton(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
        VelikoIgralnoPolje1.setIgraProtiRacunalniku(true);
    }
    else {
        VelikoIgralnoPolje1.setIgraProtiRacunalniku(false);

    }

}

QString izpisiPoljaMalegaIgralnegaPolja(IgralnoPolje igralnoPolje2){
    QString izpis = "mala igralna plosca \n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            izpis += "("+QString::number(i)+ ", "+QString::number(j)+ "): " + QString::number(igralnoPolje2.maloPolje[i][j])+ "\n";
        }
    }
    return izpis;
}

QString izpisiPoljaVelikegaIgralnegaPolja(VelikoIgralnoPolje VelikoIgralnoPolje2){
    QString izpis = "Velika igralna plosca \n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            izpis += "("+QString::number(i)+ ", "+QString::number(j)+ ") - " +izpisiPoljaMalegaIgralnegaPolja(VelikoIgralnoPolje2.velikoPolje[i][j])+ "\n";
        }
    }
    izpis += "Veliko polje - veliki kvadrati \n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            izpis += "("+QString::number(i)+ ", "+QString::number(j)+ "): " + QString::number(VelikoIgralnoPolje2.maloPolje[i][j])+ "\n";
        }
    }
    return izpis;
}


void MainWindow::poteza(int stevilkaGumbaXveliki, int stevilkaGumbaYveliki,int stevilkaGumbaXmali,int stevilkaGumbaYmali,VelikoIgralnoPolje &VelikoIgralnoPolje1, QPushButton *gumb){
    //najprej preveri, ce je poteza legalna
    if (VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki].jeLegalna(stevilkaGumbaXmali, stevilkaGumbaYmali) && VelikoIgralnoPolje1.jeLegalna(stevilkaGumbaXveliki, stevilkaGumbaYveliki)){
        VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki].maloPolje[stevilkaGumbaXmali][stevilkaGumbaYmali] = VelikoIgralnoPolje1.getIgralecNaPotezi(); // vpise potezo v "bazo podatkov"
        if(VelikoIgralnoPolje1.getZadnjaPotezaX() != -1 && (VelikoIgralnoPolje1.maloPolje[VelikoIgralnoPolje1.getZadnjaPotezaX()][VelikoIgralnoPolje1.getZadnjaPotezaY()]) == 0)
            spremeniBarvoOzadjaKvadrata(VelikoIgralnoPolje1.getZadnjaPotezaX(), VelikoIgralnoPolje1.getZadnjaPotezaY(),-100); // izbrise pobarvano zeleno polje od zadnje poteze, ce je bilo zeleno samo en kvadrat
        if(VelikoIgralnoPolje1.getPoljeNaslednjePotezeX() == -1){// izbrise pobarvano zeleno polje od zadnje poteze, ce jih je vec
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if (VelikoIgralnoPolje1.maloPolje[i][j]==0){
                        spremeniBarvoOzadjaKvadrata(i, j,-100);
                    }
                }
            }
        }

        //vrise slikico na gumb
        if (VelikoIgralnoPolje1.getIgralecNaPotezi() == 1){
            gumb->setIcon(QIcon(":/krizec.png"));
            gumb->setIconSize(QSize(20, 20));
        }
        else{
            gumb->setIcon(QIcon(":/krozec.png"));
            gumb->setIconSize(QSize(20, 20));
        }

        //preveri zmago v malem kvadratu
        if(VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki].preveriZmago(VelikoIgralnoPolje1.getIgralecNaPotezi())){
            spremeniBarvoOzadjaKvadrata(stevilkaGumbaXveliki,stevilkaGumbaYveliki,VelikoIgralnoPolje1.getIgralecNaPotezi());
            VelikoIgralnoPolje1.maloPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki] = VelikoIgralnoPolje1.getIgralecNaPotezi();
            if(VelikoIgralnoPolje1.preveriZmago(VelikoIgralnoPolje1.getIgralecNaPotezi())){//preveri ce zmaga celotno igro
                obvestiloOZmagiIgre.setText("Zmagovalec igre je igralec " + QString::number(VelikoIgralnoPolje1.getIgralecNaPotezi()) + ". Cestitke!!!");
                obvestiloOZmagiIgre.exec();
            }
        }
        else if(VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki].preveriCeJeCeloPoljeZasedeno()){//preveri ce je malo polje, kjer je bila odigrana zadnja poteza, celo zasedeno
            // obarva polje rumeno
            VelikoIgralnoPolje1.maloPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki]=-1;
            spremeniBarvoOzadjaKvadrata(stevilkaGumbaXveliki,stevilkaGumbaYveliki,-1);
        }

        if(VelikoIgralnoPolje1.preveriCeJeCeloPoljeZasedeno()){ // preveri, ce so zasedeni vsi mali kvadrati, potem javi, da se je igra koncala z remijem
            obvestiloORemiju.setText("Igra se je koncala z remijem.");
            obvestiloORemiju.exec();
            VelikoIgralnoPolje1.setIgraProtiRacunalniku(false);
        }

        //ui->textBrowser->setText(izpisiPoljaVelikegaIgralnegaPolja(VelikoIgralnoPolje1));

        //pregleda, kam naj igralec vpise nasldnjo potezo
        VelikoIgralnoPolje1.setZadnjaPotezaX(stevilkaGumbaXmali);
        VelikoIgralnoPolje1.setZadnjaPotezaY(stevilkaGumbaYmali);
        VelikoIgralnoPolje1.poljeNaslednjePoteze();
        if(VelikoIgralnoPolje1.getPoljeNaslednjePotezeX()!=-1){ // spremeni v eno polje v zeleno
            spremeniBarvoOzadjaKvadrata(VelikoIgralnoPolje1.getPoljeNaslednjePotezeX(), VelikoIgralnoPolje1.getPoljeNaslednjePotezeY(),0);
        }
        else{ // spremeni tista polja, ki se niso zasedena v zeleno
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if (VelikoIgralnoPolje1.maloPolje[i][j]==0){
                        spremeniBarvoOzadjaKvadrata(i, j, 0);
                    }
                }
            }
        }

        VelikoIgralnoPolje1.spremembaIgralca();

        if(VelikoIgralnoPolje1.getIgraProtiRacunalniku() && VelikoIgralnoPolje1.getIgralecNaPotezi()==2){ // naredi potezo za racunalnik, ce je na potezi racunalnik
            int izbranoPoljeRacunalnika = VelikoIgralnoPolje1.izberiPoljeZaRacunalnik();
            QPushButton *gumb1 = ui->centralwidget->findChild<QPushButton*>("pushButton_" + QString::number(izbranoPoljeRacunalnika+1));
            poteza((izbranoPoljeRacunalnika/9)/3, (izbranoPoljeRacunalnika/9)%3,(izbranoPoljeRacunalnika%9)/3, (izbranoPoljeRacunalnika%9)%3, VelikoIgralnoPolje1, gumb1);
        }
    }

    else{ // to se izvede, ce poteza ni legalna
        obvestiloOZasedenostiPolja.setText("Izbrana poteza ni legalna. Prosim, da izberete prosto polje v zelenem obmocju.");
        obvestiloOZasedenostiPolja.exec();
    }
}

void MainWindow::spremeniBarvoOzadjaKvadrata(int spremeniX, int spremeniY, int barva)
{
    QWidget *listWidgetov[9] = {ui->widget_1, ui->widget_2, ui->widget_3,ui->widget_4, ui->widget_5, ui->widget_6,ui->widget_7, ui->widget_8, ui->widget_9};
    switch(barva){
        case 0://tukaj pokaze, v katero polje mora igralec vpisati nasedlnjo potezo
            listWidgetov[3*spremeniX+spremeniY]->setStyleSheet("background-color: rgba(127,255,0, 150);");
            break;
        case -100://tukaj izbrise pobarvanao polje, kjer je igralec prej lahko vpisal potezo
            listWidgetov[3*spremeniX+spremeniY]->setStyleSheet("");
            break;
        case 1://igralec 1 - rdeca
            listWidgetov[3*spremeniX+spremeniY]->setStyleSheet("background-color: rgba(250, 0, 0, 150);");
            break;
        case 2://igralec 2 - modra
            listWidgetov[3*spremeniX+spremeniY]->setStyleSheet("background-color: rgba(30,144,255, 150);");
            break;
        case -1://remi - rumena
            listWidgetov[3*spremeniX+spremeniY]->setStyleSheet("background-color: rgba(250, 250, 0, 50);");
    }
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_pushButton_1_clicked()
{
    poteza(0, 0, 0, 0, VelikoIgralnoPolje1, ui->pushButton_1);
}
void MainWindow::on_pushButton_2_clicked()
{
    poteza(0, 0, 0, 1, VelikoIgralnoPolje1, ui->pushButton_2);
}
void MainWindow::on_pushButton_3_clicked()
{
    poteza(0, 0, 0, 2, VelikoIgralnoPolje1, ui->pushButton_3);
}
void MainWindow::on_pushButton_4_clicked()
{
    poteza(0, 0, 1, 0, VelikoIgralnoPolje1, ui->pushButton_4);
}
void MainWindow::on_pushButton_5_clicked()
{
    poteza(0, 0, 1, 1, VelikoIgralnoPolje1, ui->pushButton_5);
}
void MainWindow::on_pushButton_6_clicked()
{
    poteza(0, 0, 1, 2, VelikoIgralnoPolje1, ui->pushButton_6);
}
void MainWindow::on_pushButton_7_clicked()
{
    poteza(0, 0, 2, 0, VelikoIgralnoPolje1, ui->pushButton_7);
}
void MainWindow::on_pushButton_8_clicked()
{
    poteza(0, 0, 2, 1, VelikoIgralnoPolje1, ui->pushButton_8);
}
void MainWindow::on_pushButton_9_clicked()
{
    poteza(0, 0, 2, 2, VelikoIgralnoPolje1, ui->pushButton_9);
}
void MainWindow::on_pushButton_10_clicked()
{
    poteza(0, 1, 0, 0, VelikoIgralnoPolje1, ui->pushButton_10);
}
void MainWindow::on_pushButton_11_clicked()
{
    poteza(0, 1, 0, 1, VelikoIgralnoPolje1, ui->pushButton_11);
}
void MainWindow::on_pushButton_12_clicked()
{
    poteza(0, 1, 0, 2, VelikoIgralnoPolje1, ui->pushButton_12);
}

void MainWindow::on_pushButton_13_clicked()
{
    poteza(0, 1, 1, 0, VelikoIgralnoPolje1, ui->pushButton_13);
}
void MainWindow::on_pushButton_14_clicked()
{
    poteza(0, 1, 1, 1, VelikoIgralnoPolje1, ui->pushButton_14);
}
void MainWindow::on_pushButton_15_clicked()
{
    poteza(0, 1, 1, 2, VelikoIgralnoPolje1, ui->pushButton_15);
}
void MainWindow::on_pushButton_16_clicked()
{
    poteza(0, 1, 2, 0, VelikoIgralnoPolje1, ui->pushButton_16);
}
void MainWindow::on_pushButton_17_clicked()
{
    poteza(0, 1, 2, 1, VelikoIgralnoPolje1, ui->pushButton_17);
}
void MainWindow::on_pushButton_18_clicked()
{
    poteza(0, 1, 2, 2, VelikoIgralnoPolje1, ui->pushButton_18);
}
void MainWindow::on_pushButton_19_clicked()
{
    poteza(0, 2, 0, 0, VelikoIgralnoPolje1, ui->pushButton_19);
}
void MainWindow::on_pushButton_20_clicked()
{
    poteza(0, 2, 0, 1, VelikoIgralnoPolje1, ui->pushButton_20);
}
void MainWindow::on_pushButton_21_clicked()
{
    poteza(0, 2, 0, 2, VelikoIgralnoPolje1, ui->pushButton_21);
}
void MainWindow::on_pushButton_22_clicked()
{
    poteza(0, 2, 1, 0, VelikoIgralnoPolje1, ui->pushButton_22);
}
void MainWindow::on_pushButton_23_clicked()
{
    poteza(0, 2, 1, 1, VelikoIgralnoPolje1, ui->pushButton_23);
}
void MainWindow::on_pushButton_24_clicked()
{
    poteza(0, 2, 1, 2, VelikoIgralnoPolje1, ui->pushButton_24);
}
void MainWindow::on_pushButton_25_clicked()
{
    poteza(0, 2, 2, 0, VelikoIgralnoPolje1, ui->pushButton_25);
}
void MainWindow::on_pushButton_26_clicked()
{
    poteza(0, 2, 2, 1, VelikoIgralnoPolje1, ui->pushButton_26);
}
void MainWindow::on_pushButton_27_clicked()
{
    poteza(0, 2, 2, 2, VelikoIgralnoPolje1, ui->pushButton_27);
}
void MainWindow::on_pushButton_28_clicked()
{
    poteza(1, 0, 0, 0, VelikoIgralnoPolje1, ui->pushButton_28);
}
void MainWindow::on_pushButton_29_clicked()
{
    poteza(1, 0, 0, 1, VelikoIgralnoPolje1, ui->pushButton_29);
}
void MainWindow::on_pushButton_30_clicked()
{
    poteza(1, 0, 0, 2, VelikoIgralnoPolje1, ui->pushButton_30);
}
void MainWindow::on_pushButton_31_clicked()
{
    poteza(1, 0, 1, 0, VelikoIgralnoPolje1, ui->pushButton_31);
}
void MainWindow::on_pushButton_32_clicked()
{
    poteza(1, 0, 1, 1, VelikoIgralnoPolje1, ui->pushButton_32);
}
void MainWindow::on_pushButton_33_clicked()
{
    poteza(1, 0, 1, 2, VelikoIgralnoPolje1, ui->pushButton_33);
}
void MainWindow::on_pushButton_34_clicked()
{
    poteza(1, 0, 2, 0, VelikoIgralnoPolje1, ui->pushButton_34);
}
void MainWindow::on_pushButton_35_clicked()
{
    poteza(1, 0, 2, 1, VelikoIgralnoPolje1, ui->pushButton_35);
}
void MainWindow::on_pushButton_36_clicked()
{
    poteza(1, 0, 2, 2, VelikoIgralnoPolje1, ui->pushButton_36);
}
void MainWindow::on_pushButton_37_clicked()
{
    poteza(1, 1, 0, 0, VelikoIgralnoPolje1, ui->pushButton_37);
}
void MainWindow::on_pushButton_38_clicked()
{
    poteza(1, 1, 0, 1, VelikoIgralnoPolje1, ui->pushButton_38);
}
void MainWindow::on_pushButton_39_clicked()
{
    poteza(1, 1, 0, 2, VelikoIgralnoPolje1, ui->pushButton_39);
}
void MainWindow::on_pushButton_40_clicked()
{
    poteza(1, 1, 1, 0, VelikoIgralnoPolje1, ui->pushButton_40);
}
void MainWindow::on_pushButton_41_clicked()
{
    poteza(1, 1, 1, 1, VelikoIgralnoPolje1, ui->pushButton_41);
}
void MainWindow::on_pushButton_42_clicked()
{
    poteza(1, 1, 1, 2, VelikoIgralnoPolje1, ui->pushButton_42);
}
void MainWindow::on_pushButton_43_clicked()
{
    poteza(1, 1, 2, 0, VelikoIgralnoPolje1, ui->pushButton_43);
}
void MainWindow::on_pushButton_44_clicked()
{
    poteza(1, 1, 2, 1, VelikoIgralnoPolje1, ui->pushButton_44);
}
void MainWindow::on_pushButton_45_clicked()
{
    poteza(1, 1, 2, 2, VelikoIgralnoPolje1, ui->pushButton_45);
}
void MainWindow::on_pushButton_46_clicked()
{
    poteza(1, 2, 0, 0, VelikoIgralnoPolje1, ui->pushButton_46);
}
void MainWindow::on_pushButton_47_clicked()
{
    poteza(1, 2, 0, 1, VelikoIgralnoPolje1, ui->pushButton_47);
}
void MainWindow::on_pushButton_48_clicked()
{
    poteza(1, 2, 0, 2, VelikoIgralnoPolje1, ui->pushButton_48);
}
void MainWindow::on_pushButton_49_clicked()
{
    poteza(1, 2, 1, 0, VelikoIgralnoPolje1, ui->pushButton_49);
}
void MainWindow::on_pushButton_50_clicked()
{
    poteza(1, 2, 1, 1, VelikoIgralnoPolje1, ui->pushButton_50);
}
void MainWindow::on_pushButton_51_clicked()
{
    poteza(1, 2, 1, 2, VelikoIgralnoPolje1, ui->pushButton_51);
}
void MainWindow::on_pushButton_52_clicked()
{
    poteza(1, 2, 2, 0, VelikoIgralnoPolje1, ui->pushButton_52);
}
void MainWindow::on_pushButton_53_clicked()
{
    poteza(1, 2, 2, 1, VelikoIgralnoPolje1, ui->pushButton_53);
}
void MainWindow::on_pushButton_54_clicked()
{
    poteza(1, 2, 2, 2, VelikoIgralnoPolje1, ui->pushButton_54);
}
void MainWindow::on_pushButton_55_clicked()
{
    poteza(2, 0, 0, 0, VelikoIgralnoPolje1, ui->pushButton_55);
}
void MainWindow::on_pushButton_56_clicked()
{
    poteza(2, 0, 0, 1, VelikoIgralnoPolje1, ui->pushButton_56);
}
void MainWindow::on_pushButton_57_clicked()
{
    poteza(2, 0, 0, 2, VelikoIgralnoPolje1, ui->pushButton_57);
}
void MainWindow::on_pushButton_58_clicked()
{
    poteza(2, 0, 1, 0, VelikoIgralnoPolje1, ui->pushButton_58);
}
void MainWindow::on_pushButton_59_clicked()
{
    poteza(2, 0, 1, 1, VelikoIgralnoPolje1, ui->pushButton_59);
}
void MainWindow::on_pushButton_60_clicked()
{
    poteza(2, 0, 1, 2, VelikoIgralnoPolje1, ui->pushButton_60);
}
void MainWindow::on_pushButton_61_clicked()
{
    poteza(2, 0, 2, 0, VelikoIgralnoPolje1, ui->pushButton_61);
}
void MainWindow::on_pushButton_62_clicked()
{
    poteza(2, 0, 2, 1, VelikoIgralnoPolje1, ui->pushButton_62);
}
void MainWindow::on_pushButton_63_clicked()
{
    poteza(2, 0, 2, 2, VelikoIgralnoPolje1, ui->pushButton_63);
}
void MainWindow::on_pushButton_64_clicked()
{
    poteza(2, 1, 0, 0, VelikoIgralnoPolje1, ui->pushButton_64);
}
void MainWindow::on_pushButton_65_clicked()
{
    poteza(2, 1, 0, 1, VelikoIgralnoPolje1, ui->pushButton_65);
}
void MainWindow::on_pushButton_66_clicked()
{
    poteza(2, 1, 0, 2, VelikoIgralnoPolje1, ui->pushButton_66);
}
void MainWindow::on_pushButton_67_clicked()
{
    poteza(2, 1, 1, 0, VelikoIgralnoPolje1, ui->pushButton_67);
}
void MainWindow::on_pushButton_68_clicked()
{
    poteza(2, 1, 1, 1, VelikoIgralnoPolje1, ui->pushButton_68);
}
void MainWindow::on_pushButton_69_clicked()
{
    poteza(2, 1, 1, 2, VelikoIgralnoPolje1, ui->pushButton_69);
}
void MainWindow::on_pushButton_70_clicked()
{
    poteza(2, 1, 2, 0, VelikoIgralnoPolje1, ui->pushButton_70);
}
void MainWindow::on_pushButton_71_clicked()
{
    poteza(2, 1, 2, 1, VelikoIgralnoPolje1, ui->pushButton_71);
}
void MainWindow::on_pushButton_72_clicked()
{
    poteza(2, 1, 2, 2, VelikoIgralnoPolje1, ui->pushButton_72);
}
void MainWindow::on_pushButton_73_clicked()
{
    poteza(2, 2, 0, 0, VelikoIgralnoPolje1, ui->pushButton_73);
}
void MainWindow::on_pushButton_74_clicked()
{
    poteza(2, 2, 0, 1, VelikoIgralnoPolje1, ui->pushButton_74);
}
void MainWindow::on_pushButton_75_clicked()
{
    poteza(2, 2, 0, 2, VelikoIgralnoPolje1, ui->pushButton_75);
}
void MainWindow::on_pushButton_76_clicked()
{
    poteza(2, 2, 1, 0, VelikoIgralnoPolje1, ui->pushButton_76);
}
void MainWindow::on_pushButton_77_clicked()
{
    poteza(2, 2, 1, 1, VelikoIgralnoPolje1, ui->pushButton_77);
}
void MainWindow::on_pushButton_78_clicked()
{
    poteza(2, 2, 1, 2, VelikoIgralnoPolje1, ui->pushButton_78);
}
void MainWindow::on_pushButton_79_clicked()
{
    poteza(2, 2, 2, 0, VelikoIgralnoPolje1, ui->pushButton_79);
}
void MainWindow::on_pushButton_80_clicked()
{
    poteza(2, 2, 2, 1, VelikoIgralnoPolje1, ui->pushButton_80);
}
void MainWindow::on_pushButton_81_clicked()
{
    poteza(2, 2, 2, 2, VelikoIgralnoPolje1, ui->pushButton_81);
}
