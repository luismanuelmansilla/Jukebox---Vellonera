#include "Cancion.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Cancion::Cancion(string nombre, string artista, string duracionString, int duracionSeg)
{
    _nombre = nombre;
    _artista = artista;
    _duracionString = duracionString;
    _duracionSeg = duracionSeg;
    _proxima = NULL;
    _anterior = NULL;
}

string Cancion::getNombre()
{
    return _nombre;
}

string Cancion::getArtista()
{
    return _artista;
}

string Cancion::getDuracionString()
{
    return _duracionString;
}

Cancion* Cancion::getProxima()
{
    return _proxima;
}

Cancion* Cancion::getAnterior()
{
    return _anterior;
}

void Cancion::mostrarCancion()
{
    cout << getNombre();
    cout << ", ";
    cout << getArtista();
    cout << " ";
    cout << getDuracionString() << endl;
}

string Cancion::datosCancion()
{
    stringstream ss;
    string resultado;
    ss << getNombre() << ", "<< getArtista() << ", " << getDuracionString() << ".";
    resultado = ss.str();
    return resultado;
}


