#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

//DECLARACIO D'ESTRUCTURA
struct Discs
{
    char nomgrup[15];
    char nomcd[25];
    int durada;
    float preu;
    string categoria;
};

Discs disc[10];

//DECLAREM LES FUNCIONS QUE FAREM SERVIR

void introduirdisc(Discs vc[10], int totalcd);
void mostrardisc(Discs vc[10], int totalcd);
void mostrarcategoria(Discs vc[10], int totalcd, string categoriamostrar);
void guardardatos(Discs vc[10], int totalcd);
void guardarcateoria(Discs vc[10], int totalcd);
void carregardades(Discs vc[10], int totalcd);

int main()
{
    int opcio;
    int totalcd = 0;
    string categoriamostrar;

    // Mostrem el menu per pantalla

    cout << "-----------------------------------------Menu discs-----------------------------------------" << endl;
    cout << "1.Introduir un disc" << endl;
    cout << "2.Mostrar tots els cds" << endl;
    cout << "3.Mostrar el cd per categoria"<<endl;
    cout << "4.Guardar les dades en un .txt" << endl;
    cout << "5.Exportar un cd segons la seva categoria" << endl;
    cout << "6.Carregar les dades" << endl;
    cout << "7.Sortir\n"
         << endl;


    int contador = 0; //LA VARIABLE CONTADOR ENS SEERVIRA PER PODER EXECUTAR EL SWITCH EN UN BUCLE

    while (contador == 0) //EL BUCLE ES REPETIRA MENTRE CONTADOR SIGUI 0
    {
        cout << "Que vols fer? ";
        cin >> opcio;
        switch (opcio)
        {
        case 1:
            {
                introduirdisc(disc, totalcd);
                totalcd++; //AUGMENTEM EN 1 EL VALOR DE LA VARIABLE JA QUE ESTEM INTRODUIN UN DISC
            }
            break;
        case 2:
            {
                mostrardisc(disc, totalcd);
            }
            break;
        case 3:
            {
                cout << "Introdueix la categoria que vols buscar: "; //DEMANEM PER PANTALLA LA CETEGORIA QUE VOL BUSCAR
                cin.ignore();
                getline(cin, categoriamostrar);

                mostrarcategoria(disc, totalcd, categoriamostrar);
            }
            break;
        case 4:
            {
                guardardatos(disc, totalcd);
            }
        case 5:
            {
                guardarcateoria(disc, totalcd);
            }
        case 6:
            {
                carregardades(disc, totalcd);
            }
            break;
        case 7:
            {
                cout << "Fins aviat..." << endl;
                contador++; //AL AGUMENTAR EN 1 EL VALOR DE CONTADOR JA NO ES REPETIRA EL BUCLE
            }
            break;

        }
    }

    return 0;
}


void introduirdisc(Discs vc[10], int totalcd)
{
    //int comprovar = 0; AQUESTA VARIABLE SERVEIX PER COMPARAR LA CATEGORIA I VEURE SI ES CORRECTA PERO NO FUNCIONA
    //char almacen[15];
    if(totalcd < 10)
    {
        //SOLICITEM LES DADES AL USUARI
        cout << "Introdueix el nom del grup: " << endl;
        cin.ignore();
        cin.getline(disc[totalcd].nomgrup, 15);
        cout << "Introdeix el nom del cd: " << endl;
        cin.ignore();
        cin.getline(disc[totalcd].nomcd, 15);
        cout << "Introdueix la durada del cd: ";
        cin >> disc[totalcd].durada;
        cout << "Introdueix el preu: ";
        cin >> disc[totalcd].preu;
        cout << "Les categories son: rock, pop, regueton" << endl;
        cout << "Introdueix la categoria del cd: " << endl;
        cin.ignore();
        getline(cin, disc[totalcd].categoria);

        /*while (comprovar == 0)
        {
            cout << "Introdueix la categoria del cd: " << endl;
            cin.ignore();
            cin.getline(almacen, 15);

            /*
            if (strcmp(almacen, "regueton") == 0 || strcmp(almacen, "rock") == 0 || strcmp(almacen, "pop") == 0)
            {
                strcpy(disc[totalcd].categoria, almacen);
                comprovar++;
            }
            else
            {
                cout << "Les categories nomes poden ser regueton, pop, rock\n";
            }

        }
        */
    }
}



void mostrardisc(Discs vc[10], int totalcd)
{
     cout << "Els discs registrats son: " << endl; // MOSTREM TOTES LES DADES DEL DISC
    for (int j = 0; j < totalcd; j++)                   // UTILITZEM UN BUCLE PER MOSTRALES TOTES
    {
        cout << "Les dades del disc " << j << " son les seguents: " << endl;
        cout << "\nnom del grup: " << disc[j].nomgrup << endl;
        cout << "\nnom del cd: " << disc[j].nomcd << endl;
        cout << "\ndurada: " << disc[j].durada << endl;
        cout << "\npreu: " << disc[j].preu << endl;
        cout << "\ncategoria: " << disc[j].categoria << endl;
    }
}

void mostrarcategoria(Discs vc[10], int totalcd, string categoriamostrar)
{
    cout << "Els discs de la categoria " << categoriamostrar << " son: " << endl; //MOSTREM A L'USUARI LA CATEGORIA
    for (int i = 0; i < totalcd; i++)
    {
        //COMPROVEM TOTES LES CATEGORIES I SI COINCIDEIX AMB L'INTRODUIDA MOSTREM LES DADES
        if (disc[i].categoria == categoriamostrar)
        {
            cout << "Nom del grup: " << disc[i].nomgrup << endl;
            cout << "Nom del cd: " << disc[i].nomcd << endl;
            cout << "Durada: " << disc[i].durada << endl;
            cout << "Preu: " << disc[i].preu << endl;
            cout << "Categoria: " << disc[i].categoria << endl
                 << endl;
        }
    }
}

void guardardatos(Discs vc[10], int totalcd)
{
    ofstream fichero;
    fichero.open("discos.txt"); //OBRIM L'ARIXU PER TAL DE GUARDAR LES DADES
    //GUARDEM LES DADES
    for (int i = 0; i < totalcd; i++)
    {
        fichero << "                          Disc " << i << endl;
        fichero << "------------------------------------------------------------\n";
        fichero << "Nom grup/artista: "<<disc[i].nomgrup << endl;
        fichero << "Nom del cd: " <<disc[i].nomcd << endl;
        fichero << "Durada del disc: " <<disc[i].durada << endl;
        fichero << "Preu del disc: " << disc[i].preu << endl;
        fichero << "Categoria: " <<disc[i].categoria << endl;
        fichero << "------------------------------------------------------------\n";
    }
    fichero.close(); //UNA VEGADA GUARDADES TORNEM A TENCAR L'ARXIU
}

void guardarcateoria(Discs vc[10], int totalcd)
{

    ofstream reguetonarchivo("regueton.txt", ios::out | ios::app); //HI HAURA UN ARCHIU PER A CADA CATEGORIA
    ofstream poparchivo("pop.txt", ios::out | ios::app);
    ofstream rockarchivo("rock.txt", ios::out | ios::app);

    for (int i = 0; i < totalcd; i++)
    {
        if (disc[i].categoria == "regueton") //QUAN SIGUI REGUETON GUARDAREM TOTES LES DADES D'AQUELL DISC A REGUETONARCHIVO
        {
            reguetonarchivo << "                          Disc " << i << endl;
            reguetonarchivo << "------------------------------------------------------------\n";
            reguetonarchivo << "Nom grup/artista: "<<disc[i].nomgrup << endl;
            reguetonarchivo << "Nom del cd: " <<disc[i].nomcd << endl;
            reguetonarchivo << "Durada del disc: " <<disc[i].durada << endl;
            reguetonarchivo << "Preu del disc: " << disc[i].preu << endl;
            reguetonarchivo << "Categoria: " <<disc[i].categoria << endl;
            reguetonarchivo << "------------------------------------------------------------\n";
        }
        if (disc[i].categoria == "pop") //QUAN SIGUI POP ES FARA LO MATEIX PERO EN EL ARCHIU DE POP
        {
            poparchivo << "                          Disc " << i << endl;
            poparchivo << "------------------------------------------------------------\n";
            poparchivo << "Nom grup/artista: "<<disc[i].nomgrup << endl;
            poparchivo << "Nom del cd: " <<disc[i].nomcd << endl;
            poparchivo << "Durada del disc: " <<disc[i].durada << endl;
            poparchivo << "Preu del disc: " << disc[i].preu << endl;
            poparchivo << "Categoria: " <<disc[i].categoria << endl;
            poparchivo << "------------------------------------------------------------\n";
        }
        if (disc[i].categoria == "rock") //QUAN SIGUI POP ES FARA LO MATEIX PERO EN EL ARCHIU DE ROCK
        {
            rockarchivo << "                          Disc " << i << endl;
            rockarchivo << "------------------------------------------------------------\n";
            rockarchivo << "Nom grup/artista: "<<disc[i].nomgrup << endl;
            rockarchivo << "Nom del cd: " <<disc[i].nomcd << endl;
            rockarchivo << "Durada del disc: " <<disc[i].durada << endl;
            rockarchivo << "Preu del disc: " << disc[i].preu << endl;
            rockarchivo << "Categoria: " <<disc[i].categoria << endl;
            rockarchivo << "------------------------------------------------------------\n";
        }
    }
    //TANQUEM ELS TRES ARCHIUS
    reguetonarchivo.close();
    poparchivo.close();
    rockarchivo.close();
}

void carregardades(Discs vc[10], int totalcd)
{
    ifstream file("discos.txt");
    if (file.is_open()) //SI EL FICHER ESTA OBERT
    {
        int i = 0;
        while (!file.eof() && i < 10) //EL BUCLE DURARAR TOTA LA LONGITUD DEL FICHER I FINS QUE I VALGI 10
        {
            //CARREGUEM LES DADES
            file >> disc[i].nomgrup;
            file >> disc[i].nomcd;
            file >> disc[i].durada;
            file >> disc[i].preu;
            getline(file, disc[i].categoria);
            i++;
        }
        totalcd = i;
        file.close();
    }
    else
    {
        cout << "No s'ha pogut obrir l'archiu" << endl; //SI L'ARXIU NO ES POT OBRI MOSTREM EL MISSATGE
    }
}



