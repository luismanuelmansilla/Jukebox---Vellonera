#ifndef VELLONERA_H
#define VELLONERA_H
#include "Cancion.h"

class Vellonera
{
     public:
        Vellonera();
        void agregar(Cancion* cancion);
        void eliminarCancion(int numeroCancion);
        void listarCanciones();
        void proximaCancion();
        void cancionAnterior();
        void repeticion();
        void pararRepeticion();
        bool estaVacia();
        int getTamano();
        Cancion* getPrimera();
        Cancion* getActual();

    private:
        Cancion* _primera;
        Cancion* _ultima;
        Cancion* _actual;
        bool _repeticion;
        int _tamano;
    friend class Menu;
};

#endif // LISTA_H
