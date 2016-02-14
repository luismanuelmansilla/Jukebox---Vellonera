#ifndef CANCION_H
#define CANCION_H
#include<string>
using namespace std;

class Cancion
{
    public:
        Cancion(string nombre, string artista, string duracionString, int duracionSeg);
        string getNombre();
        string getArtista();
        string getDuracionString();
        Cancion* getProxima();
        Cancion* getAnterior();
        void mostrarCancion();
        string datosCancion();
    private:
        string _nombre;
        string _artista;
        string _duracionString;
        int _duracionSeg;
        Cancion* _proxima;
        Cancion* _anterior;
    friend class Vellonera;
};
#endif // CANCION_H
