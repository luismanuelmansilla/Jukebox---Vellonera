#include<iostream>
#include "Vellonera.h"
#include <string>
#include <sstream>
#include <windows.h>
#include <winuser.h>
#include "Menu.h"
using namespace std;

Vellonera::Vellonera()
{
    _primera = NULL;
    _ultima = NULL;
    _actual = NULL;
    _repeticion = false;
    _tamano = 0;
}

void Vellonera::agregar(Cancion* cancion)
{
    _tamano++;
    if(!_primera){
        _primera = cancion;
        _ultima = cancion;
        _actual = _primera;
    }else{
        Cancion* temp = _ultima;
        if(cancion -> _duracionSeg > temp-> _duracionSeg){
            _ultima -> _proxima = cancion;
            cancion -> _anterior = _ultima;
            _ultima = cancion;
        }else{
            while(cancion -> _duracionSeg < temp-> _duracionSeg){
                if(!temp -> _anterior)
                    break;
                temp = temp-> _anterior;
            }
            if(temp -> _anterior == NULL && cancion -> _duracionSeg < temp -> _duracionSeg){
                _primera ->_anterior = cancion;
                cancion ->_proxima =_primera;
                _primera = cancion;
            }else{
                temp -> _proxima -> _anterior = cancion;
                cancion -> _proxima = temp -> _proxima;
                cancion -> _anterior = temp;
                temp -> _proxima = cancion;
            }
        }
    }
}

void Vellonera::eliminarCancion(int numeroCancion)
{
    int puntoMedio = _tamano/2;
    int i;
    Cancion* temp;

    if(numeroCancion >= puntoMedio){
        i = _tamano;
        temp =_ultima;
        while(i != numeroCancion){
            temp = temp -> _anterior;
            i--;
        }
    }else if(numeroCancion < puntoMedio){
        i=1;
        temp = _primera;
        while(i != numeroCancion){
            temp = temp -> _proxima;
            i++;
        }
    }

    stringstream ss;
    string mensaje;
    ss << "¿Estas seguro que deseas eliminar la canción: " << temp -> datosCancion() << "?";
    mensaje = ss.str();

    const char *cstr = mensaje.c_str();

    int msgboxID = MessageBox(
        NULL,
        cstr,
        "Confirmación",
        MB_ICONWARNING | MB_YESNO
    );

    switch (msgboxID)
    {
        case IDNO:
            return;
            break;
        case IDYES:
            MessageBox(
            NULL,
            "La canción ha sido eliminada con éxito!!",
            "Confirmación",
            MB_ICONINFORMATION | MB_OK
            );

            if(temp == _actual){
                if(temp -> _proxima)
                    _actual = temp -> _proxima;
                else if(!temp -> _proxima && !temp ->_anterior)
                    _actual = NULL;
                else
                    _actual = temp -> _anterior;
            }
            if(_tamano == 1 && temp ==_primera){
                _primera = _ultima =NULL;
                _tamano--;
                return;
            }
            if(temp == _primera){
                _primera = _primera ->_proxima;
                _primera -> _anterior=NULL;
                _tamano--;
                return;
            }
            if(temp ==_ultima){
                _ultima =_ultima ->_anterior;
                _ultima -> _proxima = NULL;
                _tamano--;
                return;
            }
            Cancion* previa= temp -> _anterior;
            Cancion* siguiente = temp-> _proxima;
            previa -> _proxima = siguiente;
            siguiente -> _anterior = previa;
            _tamano--;
            break;
    }
}

void Vellonera::listarCanciones()
{
    int cont = 1;
    Cancion* temp = _primera;
    while(temp){
        cout << cont << ". ";
        temp -> mostrarCancion();
        temp = temp -> _proxima;
        cont++;
    }
}

void Vellonera::proximaCancion()
{
    if(_repeticion && _actual ==_ultima){
        _actual = _primera;
    }
    else if(_actual ==_ultima){
        _actual =_ultima;
    }
    else{
        _actual = _actual -> _proxima;
    }
}

void Vellonera::cancionAnterior()
{
    if(_actual ==_primera){
        _actual =_primera;
    }else{
        _actual =_actual ->_anterior;
    }
}

void Vellonera::repeticion()
{
    _repeticion = true;
}

void Vellonera::pararRepeticion()
{
    _repeticion = false;
}

bool Vellonera::estaVacia()
{
    return !_tamano;
}

int Vellonera::getTamano()
{
    return _tamano;
}

Cancion* Vellonera::getActual()
{
    return _actual;
}


Cancion* Vellonera::getPrimera()
{
    return _primera;
}
