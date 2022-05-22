#include "mainwindow.h"
#include "ui_mainwindow.h"


VelikoIgralnoPolje VelikoIgralnoPolje1;
Igralec Igralec1(1);
Igralec Igralec2(2);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug("dela");
    qDebug()<< "Polje naslednje poteze " << VelikoIgralnoPolje1.getPoljeNaslednjePotezeX() << ", "<< VelikoIgralnoPolje1.getPoljeNaslednjePotezeY();
    ui->setupUi(this);
}




QString izpisiPoljaIgralca(Igralec IgralecA){
    QString izpis = "Igralec" + QString::number(IgralecA.ime) + "\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            izpis += QString::number(i)+ ", "+QString::number(j)+ ": "; //+ QString::number(IgralecA.poteze[i][j])+ "\n";
        }
    }
    return izpis;
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

bool preveriZmagoFunkcija(int maloPolje[3][3], int igralecNaPotezi){//parameter malo polje
    /*if (igralecNaPotezi== 1)
        igralecNaPotezi+=1;
    else
        igralecNaPotezi-=1;*/
    //int j = igralecNaPotezi;

    if (maloPolje[0][0]==igralecNaPotezi && maloPolje[0][1]==igralecNaPotezi && maloPolje[0][2]==igralecNaPotezi)
        return true;
    else if (maloPolje[0][0]==igralecNaPotezi && maloPolje[1][0]==igralecNaPotezi && maloPolje[2][0]==igralecNaPotezi)
        return true;
    else if (maloPolje[0][0]==igralecNaPotezi && maloPolje[1][1]==igralecNaPotezi && maloPolje[2][2]==igralecNaPotezi)
        return true;
    else if (maloPolje[0][1]==igralecNaPotezi && maloPolje[1][1]==igralecNaPotezi && maloPolje[2][1]==igralecNaPotezi)
        return true;
    else if (maloPolje[1][0]==igralecNaPotezi && maloPolje[1][1]==igralecNaPotezi && maloPolje[1][2]==igralecNaPotezi)
        return true;
    else if (maloPolje[2][0]==igralecNaPotezi && maloPolje[2][1]==igralecNaPotezi && maloPolje[2][2]==igralecNaPotezi)
        return true;
    else if (maloPolje[0][2]==igralecNaPotezi && maloPolje[1][2]==igralecNaPotezi && maloPolje[2][2]==igralecNaPotezi)
        return true;
    else if (maloPolje[0][2]==igralecNaPotezi && maloPolje[1][1]==igralecNaPotezi && maloPolje[2][0]==igralecNaPotezi)
        return true;
    else
        return false;
        /*


        if (((maloPolje[0][1]==igralecNaPotezi && maloPolje[0][2])==igralecNaPotezi) || (maloPolje[1][0]==igralecNaPotezi&& maloPolje[2][0]==igralecNaPotezi) ||(maloPolje[1][1]==igralecNaPotezi&& maloPolje[2][2]==igralecNaPotezi))
            return true;
    }
    else if (maloPolje[1][1]==igralecNaPotezi){
        if ((maloPolje[0][1]==igralecNaPotezi&& maloPolje[2][1]==igralecNaPotezi) || (maloPolje[0][2]==igralecNaPotezi&& maloPolje[2][0]==igralecNaPotezi) ||(maloPolje[1][0]==igralecNaPotezi&& maloPolje[1][2]==igralecNaPotezi))
            return true;
    }

    else if ((maloPolje[2][0]==igralecNaPotezi&& maloPolje[2][1]==igralecNaPotezi&& maloPolje[2][2]==igralecNaPotezi)||(maloPolje[0][2]==igralecNaPotezi && maloPolje[0][1]==igralecNaPotezi && maloPolje[2][2]==igralecNaPotezi)){
            return true;
    }
    return false;
*/
}

void MainWindow::poteza(int stevilkaGumbaXveliki, int stevilkaGumbaYveliki,int stevilkaGumbaXmali,int stevilkaGumbaYmali,VelikoIgralnoPolje &VelikoIgralnoPolje1, QPushButton *gumb){

    //qDebug()<< "Malo polje - funkcija jeLegalna()" << jeLegalna((VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki]).maloPolje, stevilkaGumbaXveliki, stevilkaGumbaYveliki,stevilkaGumbaXmali, stevilkaGumbaYmali);
    if (VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki].jeLegalna(stevilkaGumbaXveliki, stevilkaGumbaYveliki,stevilkaGumbaXmali, stevilkaGumbaYmali) && VelikoIgralnoPolje1.jeLegalna(stevilkaGumbaXveliki, stevilkaGumbaYveliki,stevilkaGumbaXmali, stevilkaGumbaYmali)){
    //if (jeLegalna((VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki]).maloPolje, stevilkaGumbaXveliki, stevilkaGumbaYveliki,stevilkaGumbaXmali, stevilkaGumbaYmali) && VelikoIgralnoPolje1.jeLegalna(stevilkaGumbaXveliki, stevilkaGumbaYveliki,stevilkaGumbaXmali, stevilkaGumbaYmali)){
        qDebug()<< "Polje prejsnje poteze " << VelikoIgralnoPolje1.getZadnjaPotezaX() << ", "<< VelikoIgralnoPolje1.getZadnjaPotezaY();
        qDebug()<< "Polje naslednje poteze " << VelikoIgralnoPolje1.getPoljeNaslednjePotezeX() << ", "<< VelikoIgralnoPolje1.getPoljeNaslednjePotezeY();

        VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki].maloPolje[stevilkaGumbaXmali][stevilkaGumbaYmali] = VelikoIgralnoPolje1.getIgralecNaPotezi();
        if(VelikoIgralnoPolje1.getZadnjaPotezaX() != -1 && (VelikoIgralnoPolje1.maloPolje[VelikoIgralnoPolje1.getZadnjaPotezaX()][VelikoIgralnoPolje1.getZadnjaPotezaY()]) == 0)
            spremeniBarvoOzadjaKvadrata(VelikoIgralnoPolje1.getZadnjaPotezaX(), VelikoIgralnoPolje1.getZadnjaPotezaY(),-100);
        qDebug()<< "VelikoIgralnoPolje1.getZadnjaPotezaX() == " << QString::number(VelikoIgralnoPolje1.getPoljeNaslednjePotezeX());
        if(VelikoIgralnoPolje1.getPoljeNaslednjePotezeX() == -1){
            qDebug()<< "Brisanje barve v else ifu ";
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if (VelikoIgralnoPolje1.maloPolje[i][j]==0){
                        qDebug()<< "Brisanje barve v ifu kjer mora brisat";
                        spremeniBarvoOzadjaKvadrata(i, j,-100);
                    }
                }
            }
        }

        if (VelikoIgralnoPolje1.getIgralecNaPotezi() == 1){
            gumb->setText("");
            gumb->setIcon(QIcon(":/krizec.png"));
            gumb->setIconSize(QSize(20, 20));
        }
        else{
            gumb->setText("");
            gumb->setIcon(QIcon(":/krozec.png"));
            gumb->setIconSize(QSize(20, 20));
        }


        //cout << VelikoIgralnoPolje1;
        if(preveriZmagoFunkcija(VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki].maloPolje, VelikoIgralnoPolje1.getIgralecNaPotezi())){
        //if(VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki].preveriZmago()){
            //ui->textBrowser->setText("Zmagovalna mala plosca \n"+izpisiPoljaMalegaIgralnegaPolja(VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki]));
            //ui->widget->setStyleSheet("background-color: rgba(250, 0, 0, 150);");
            spremeniBarvoOzadjaKvadrata(stevilkaGumbaXveliki,stevilkaGumbaYveliki,VelikoIgralnoPolje1.getIgralecNaPotezi());

            QMessageBox obvestiloOZmagi;
            obvestiloOZmagi.setText("V malem polju(" +QString::number(stevilkaGumbaXveliki)+ ", "+QString::number(stevilkaGumbaYveliki)+"), kjer je bila odigrana zadnja poteza, je zmagal igralec " + QString::number(VelikoIgralnoPolje1.getIgralecNaPotezi()));
            obvestiloOZmagi.exec();
            VelikoIgralnoPolje1.maloPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki] = VelikoIgralnoPolje1.getIgralecNaPotezi();
            /*QMessageBox obvestiloOZmagiPolja;
            obvestiloOZmagi.setText(QString::number(VelikoIgralnoPolje1.maloPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki]));
            obvestiloOZmagi.exec();*/
            if(preveriZmagoFunkcija(VelikoIgralnoPolje1.maloPolje,VelikoIgralnoPolje1.getIgralecNaPotezi())){
                QMessageBox obvestiloOZmagiIgre;
                obvestiloOZmagiIgre.setText("Zmagovalec igre je igralec " + QString::number(VelikoIgralnoPolje1.getIgralecNaPotezi()) + ". Cestitke!!!");
                obvestiloOZmagiIgre.exec();
            }
        }
        else if(VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki].preveriCeJeCeloPoljeZasedeno()){
            qDebug()<<"zacetek if ce je celo polje zasedeno";
            if(VelikoIgralnoPolje1.preveriCeJeCeloPoljeZasedeno()){
                QMessageBox obvestiloORemiju;
                obvestiloORemiju.setText("Igra se je koncala z remijem.");
                obvestiloORemiju.exec();
            }
            else{
                qDebug()<<"zacetek if ce je celo polje zasedeno2";
                VelikoIgralnoPolje1.maloPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki]=-1;
                spremeniBarvoOzadjaKvadrata(stevilkaGumbaXveliki,stevilkaGumbaYveliki,-1);
                //listWidgetov[stevilkaGumbaXveliki][stevilkaGumbaYveliki].setStyleSheet("background-color: rgba(0, 50, 50, 50);"); //potem naredi, da se obrva pravi kvadrat
            }
        }
        ui->textBrowser->setText(izpisiPoljaVelikegaIgralnegaPolja(VelikoIgralnoPolje1));
        VelikoIgralnoPolje1.setZadnjaPotezaX(stevilkaGumbaXmali);
        VelikoIgralnoPolje1.setZadnjaPotezaY(stevilkaGumbaYmali);
        VelikoIgralnoPolje1.poljeNaslednjePoteze();
        if(VelikoIgralnoPolje1.getPoljeNaslednjePotezeX()!=-1){
            spremeniBarvoOzadjaKvadrata(VelikoIgralnoPolje1.getPoljeNaslednjePotezeX(), VelikoIgralnoPolje1.getPoljeNaslednjePotezeY(),0);
        }
        else{
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if (VelikoIgralnoPolje1.maloPolje[i][j]==0){
                        spremeniBarvoOzadjaKvadrata(i, j,0);
                        qDebug()<<"v for zanki za barva znotraj zanke";
                    }
                }
            }
        }
        //qDebug()<< "Polje naslednje poteze:" <<
        VelikoIgralnoPolje1.spremembaIgralca();
    }
    else{
        QMessageBox obvestiloOZasedenostiPolja;
        obvestiloOZasedenostiPolja.setText("To mesto je ze zasedeno ali ni primeren kvadrat.");
        obvestiloOZasedenostiPolja.exec();
        qDebug()<< "Malo polje - metoda jeLegalna()" << VelikoIgralnoPolje1.velikoPolje[stevilkaGumbaXveliki][stevilkaGumbaYveliki].jeLegalna(stevilkaGumbaXveliki, stevilkaGumbaYveliki,stevilkaGumbaXmali, stevilkaGumbaYmali);
        qDebug()<< "Veliko polje - metoda jeLegalna()" << VelikoIgralnoPolje1.jeLegalna(stevilkaGumbaXveliki, stevilkaGumbaYveliki,stevilkaGumbaXmali, stevilkaGumbaYmali);

    }
}

void MainWindow::spremeniBarvoOzadjaKvadrata(int spremeniX, int spremeniY, int barva)
{
    //QWidget *listWidgetov[3][3] = {{ui->widget, ui->widget_2, ui->widget_3}, {ui->widget_4, ui->widget_5, ui->widget_6},{ui->widget_7, ui->widget_8, ui->widget_9}};
    QWidget *listWidgetov[9] = {ui->widget, ui->widget_2, ui->widget_3,ui->widget_4, ui->widget_5, ui->widget_6,ui->widget_7, ui->widget_8, ui->widget_9};
    /*QWidget * polje = new QWidget [9];
    QList <QWidget> *list= new QList <QWidget> ();
    list->append(ui->widget);
    */

    qDebug()<<"v funkciji za barvo" << QString::number(barva);
    switch(barva){
        case 0://tukaj pokaze, v katero polje mora igralec vpisati nasedlnjo potezo
            listWidgetov[3*spremeniX+spremeniY]->setStyleSheet("background-color: rgba(127,255,0, 150);");
            break;
        case -100://tukaj izbrise pobarvanao polje, kjer je igralec prej vpisal potezo
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


void MainWindow::on_pushButton_130_clicked()
{
    poteza(0, 1, 1, 0, VelikoIgralnoPolje1, ui->pushButton_130);
}
void MainWindow::on_pushButton_140_clicked()
{
    poteza(0, 1, 1, 1, VelikoIgralnoPolje1, ui->pushButton_140);
}
void MainWindow::on_pushButton_150_clicked()
{
    poteza(0, 1, 1, 2, VelikoIgralnoPolje1, ui->pushButton_150);
}
void MainWindow::on_pushButton_160_clicked()
{
    poteza(0, 1, 2, 0, VelikoIgralnoPolje1, ui->pushButton_160);
}
void MainWindow::on_pushButton_170_clicked()
{
    poteza(0, 1, 2, 1, VelikoIgralnoPolje1, ui->pushButton_170);
}
void MainWindow::on_pushButton_180_clicked()
{
    poteza(0, 1, 2, 2, VelikoIgralnoPolje1, ui->pushButton_180);
}
void MainWindow::on_pushButton_190_clicked()
{
    poteza(0, 2, 0, 0, VelikoIgralnoPolje1, ui->pushButton_190);
}
void MainWindow::on_pushButton_200_clicked()
{
    poteza(0, 2, 0, 1, VelikoIgralnoPolje1, ui->pushButton_200);
}
void MainWindow::on_pushButton_210_clicked()
{
    poteza(0, 2, 0, 2, VelikoIgralnoPolje1, ui->pushButton_210);
}
void MainWindow::on_pushButton_220_clicked()
{
    poteza(0, 2, 1, 0, VelikoIgralnoPolje1, ui->pushButton_220);
}
void MainWindow::on_pushButton_230_clicked()
{
    poteza(0, 2, 1, 1, VelikoIgralnoPolje1, ui->pushButton_230);
}
void MainWindow::on_pushButton_240_clicked()
{
    poteza(0, 2, 1, 2, VelikoIgralnoPolje1, ui->pushButton_240);
}
void MainWindow::on_pushButton_250_clicked()
{
    poteza(0, 2, 2, 0, VelikoIgralnoPolje1, ui->pushButton_250);
}
void MainWindow::on_pushButton_260_clicked()
{
    poteza(0, 2, 2, 1, VelikoIgralnoPolje1, ui->pushButton_260);
}
void MainWindow::on_pushButton_270_clicked()
{
    poteza(0, 2, 2, 2, VelikoIgralnoPolje1, ui->pushButton_270);
}
void MainWindow::on_pushButton_280_clicked()
{
    poteza(1, 0, 0, 0, VelikoIgralnoPolje1, ui->pushButton_280);
}
void MainWindow::on_pushButton_290_clicked()
{
    poteza(1, 0, 0, 1, VelikoIgralnoPolje1, ui->pushButton_290);
}
void MainWindow::on_pushButton_300_clicked()
{
    poteza(1, 0, 0, 2, VelikoIgralnoPolje1, ui->pushButton_300);
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
