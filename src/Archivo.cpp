#include "Archivo.h"
#include<fstream>
#include<sstream>
#include<string>
#include <iostream>

Archivo::Archivo()
{
    //ctor
}

void Archivo::leerArchivo(Vellonera* vellonera)
{
    const string nfichero = "Canciones.txt";
    char cancion[100];
    ifstream archivo;
    archivo.open(nfichero.c_str());
    string canc, nombre, artista, duracion, mins, segs, nomb, art, dura;
    int duracionSeg;


    if(!archivo.fail()){
        archivo.getline(cancion, 80, '\n');

        while(!archivo.eof()){
            canc = string(cancion);
            nombre = canc.substr(0, canc.find(','));
            canc = canc.substr(nombre.size()+2, canc.find('.'));
            artista = canc.substr(0, canc.find(','));
            canc = canc.substr(artista.size()+2, canc.find('.'));
            duracion = canc.substr(0, canc.find('.'));

            mins = duracion.substr(0, 1);
            segs = duracion.substr(2,4);

            //convertiendo string to int de min y segs
            int minutos = 0;
            int segundos = 0;
            for(int i=0; i<mins.size(); i++){
                int d = mins[i]-'0';
                minutos = minutos*10 + d;
            }
            for(int j=0; j<segs.size(); j++){
                int e = segs[j]-'0';
                segundos = segundos*10 + e;
            }
            ///////////////////////////////////////////
            nomb = string(nombre);
            art = string(artista);
            dura = string(duracion);

            duracionSeg = (minutos*60) + segundos;
            Cancion* canciones = new Cancion(nomb, art, dura, duracionSeg);
            vellonera -> agregar(canciones);

            archivo.getline(cancion, 80, '\n');
        }
        archivo.close();
    }
}

void Archivo::escribirArchivo(Vellonera* vellonera)
{
    ofstream archivo("Canciones.txt");

    int i = 0;
    Cancion* temp = vellonera -> getPrimera();
    while(temp){
        archivo << temp -> datosCancion() << endl;
        temp = temp -> getProxima();
        i++;
    }
}
