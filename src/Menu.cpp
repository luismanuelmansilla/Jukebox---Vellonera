#include "Menu.h"
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include<stdio.h>
#include <conio.h>
#include <string>
#include "Vellonera.h"
#include "Archivo.h"
using namespace std;

Vellonera* vellonera = new Vellonera();
Archivo* archivo = new Archivo();

Menu::Menu()
{
    archivo -> leerArchivo(vellonera);
}

void Menu::menuPrincipal()
{
    char opcionMenu;
    do {
        cout << "\n\n\n\t\tBienvenidos al sistema de Vellonera\n";
        cout << "\t\t Creado por: Luis Manuel Mansilla\n\n";
        cout << "1. Agregar nueva canci\242n.\n";
        cout << "2. Visualizar canciones.\n";
        cout << "3. Mostrar canci\242n actual.\n";
        cout << "4. Pr\242xima Canci\242n.\n";
        cout << "5. Canci\242n Anterior.\n";
        cout << "6. Activar Repetici\242n en lista.\n";
        cout << "7. Desactivar Repetici\242n en lista.\n";
        cout << "8. Eliminar.\n";
        cout << "9. Salir.\n";
        cout << "\nElija una opci\242n => ";
        opcionMenu=_getch();
        cin.clear();
        fflush(stdin);
        cout << "\n";

        switch (opcionMenu) {
            case '1': menuInsertar();
            break;
            case '2': menuListar();
            break;
            case '3': menuActual();
            break;
            case '4': menuProxima();
            break;
            case '5': menuAnterior();
            break;
            case '6': menuRepeticion();
            break;
            case '7': menuPararRepeticion();
            break;
            case '8': menuEliminar();
            break;
            case '9':
                system("cls");
                cout << "\nSaliendo del sistema.." << endl;
                cout << "\n\n\n\t\tGracias por usar el programa, hasta la pr\242xima!\n";
                MensajeGuardar();
                break;
            default: cout << "\n" <<"\nOpci\242n Invalida! Presione cualquier tecla para continuar...\n";
        }
        system("PAUSE>null");
        system("cls");
    }while(opcionMenu != '9');
}

void Menu::menuInsertar()
{
    system("cls");
    cin.clear();
    fflush(stdin);
    string nombre, artista, duracionString;
    int minu, seg, duracionSeg;
    stringstream tempMin, tempSeg;
    char a;


    cout << "\n\n\n\t\tAgregar nueva canci\242n\n\n" << endl;

    do{
        cout << "Introduzca el nombre de la canci\242n: ";
        getline(cin, nombre);
    }while (nombre.empty());

    do{
        cout << "Introduzca el nombre del artista: ";
        getline(cin, artista);
    }while (artista.empty());

    do{
        cout << "Introduzca la duraci\242n de la canci\242n(Ej: 1:00): ";
        cin >> minu >> a >> seg;
        if(!verificarDuracion(minu,a,seg)){
            cout << "\tIncorrecto el formato: MIN:SEG \n";
        }
    }while (!verificarDuracion(minu,a,seg));
    //Concatenando la duracion luego de verificarla
    tempMin << minu;
    tempSeg << seg;

    if(seg < 10){
        duracionString = tempMin.str() + ':' + '0' + tempSeg.str();
    }else{
        duracionString = tempMin.str() + ':' + tempSeg.str();
    }
    duracionSeg = (minu*60) + seg;
    vellonera -> agregar(new Cancion(nombre, artista, duracionString, duracionSeg));
    mensajeCancionAgregada();
}

void Menu::menuListar()
{
    system("cls");
    cout << "\n\n\tListado de Canciones\n\n";
    if(vellonera-> estaVacia())
        mensajeVelloneraVacia();
    else{
        vellonera-> listarCanciones();
    }
    cout << "\n--Presione Cualquier tecla para regresar al men\243 principal --\n";
}

void Menu::menuActual()
{
    system("cls");
    cout << "\n\n\tCanci\242n Actual:\n\n";
        if(!vellonera-> getActual()){
            MessageBox(
            NULL,
            "No hay ninguna canción reproduciendoce!!",
            "Aviso",
            MB_ICONWARNING | MB_OK
            );
            system("cls");
            menuPrincipal();
        }else{
        vellonera-> getActual() -> mostrarCancion();
    }
    cout << "\n--Presione Cualquier tecla para regresar al men\243 principal --\n";
}

void Menu::menuProxima()
{
    system("cls");
    cout << "\n\n\tPr\242xima Canci\242n\n\n";
    if(vellonera-> estaVacia())
        mensajeVelloneraVacia();
    else{
        cout << "\nAvanzando a la pr\242xima pista ...\n" << endl;
        cout << "Pista actual: ";
        vellonera-> proximaCancion();
        vellonera-> getActual()-> mostrarCancion();
    }
    cout << "\n--Presione Cualquier tecla para regresar al men\243 principal --\n";
}

void Menu::menuAnterior()
{
    system("cls");
    cout << "\n\n\tCanci\242n Anterior\n\n";
    if(vellonera-> estaVacia())
        mensajeVelloneraVacia();
    else{
        cout << "\nRetrocediendo a la pista anterior ...\n" << endl;
        cout << "Pista actual: ";
        vellonera-> cancionAnterior();
        vellonera-> getActual() -> mostrarCancion();
    }
    cout << "\n--Presione Cualquier tecla para regresar al men\243 principal --\n";
}

void Menu::menuRepeticion()
{
    system("cls");
    cout << "\n\n\tActivar Repetici\242n en lista\n\n";
    if(vellonera-> estaVacia())
        mensajeVelloneraVacia();
    else{
        vellonera -> repeticion();
        cout << "\nRepetici\242n en lista activado.\n" << endl;
    }
    cout << "\n--Presione Cualquier tecla para regresar al men\243 principal --\n";
}

void Menu::menuPararRepeticion()
{
    system("cls");
    cout << "\n\n\tDesactivar Repetici\242n en lista\n\n";
    if(vellonera-> estaVacia())
        mensajeVelloneraVacia();
    else{
        vellonera -> pararRepeticion();
        cout << "\nRepetici\242n en lista desactivado.\n" << endl;
    }
    cout << "\n--Presione Cualquier tecla para regresar al men\243 principal --\n";
}

void Menu::menuEliminar()
{
    int numero;
    system("cls");
    cout << "\n\n\tEliminar canci\242n de la lista\n\n";
    if(vellonera-> estaVacia())
        mensajeVelloneraVacia();
    else{
        vellonera -> listarCanciones();
        cout<<"\nIntroduzca el n\243mero de la canci\242n que desea eliminar: ";
        do{
            cin >> numero;
        }while(numero <1 || numero > vellonera->getTamano());
        vellonera -> eliminarCancion(numero);
        system("cls");
        menuPrincipal();
    }
    //cout << "\n--Presione Cualquier tecla para regresar al men\243 principal --\n";
}

bool Menu::verificarDuracion(int minu, char a, int seg)
{
    char caract = 58;
    if ((minu>=0 && minu <= 60 && a == caract && seg >=0 && seg <= 60)){
        return true;
    }
    return false;
}

void Menu::mensajeCancionAgregada()
{
    int msgboxID = MessageBox(
        NULL,
        "Canción Agregada con éxito!",
        "Confirmación..",
        MB_ICONINFORMATION | MB_OK
    );

    switch (msgboxID)
    {
    case IDOK:
        system("cls");
        menuPrincipal();
        break;
    }
}

void Menu::mensajeVelloneraVacia()
{
    int msgboxID = MessageBox(
        NULL,
        "No hay canciones agregadas!!",
        "Aviso",
        MB_ICONWARNING | MB_OK
    );

    switch (msgboxID)
    {
    case IDOK:
        system("cls");
        menuPrincipal();
        break;
    }
}


void Menu::MensajeGuardar()
{
    int msgboxID = MessageBox(
        NULL,
        "Deseas guardar las canciones antes de salir?",
        "Guardar Canciones",
        MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON1
    );

    switch (msgboxID)
    {
    case IDYES:
        archivo -> escribirArchivo(vellonera);
        exit(1);
        break;
    case IDNO:
        exit(1);
        break;
    }
}





