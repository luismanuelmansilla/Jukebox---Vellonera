#ifndef MENU_H
#define MENU_H

class Menu
{
    public:
        Menu();
        void menuPrincipal();
        void menuInsertar();
        void menuListar();
        void menuActual();
        void menuProxima();
        void menuAnterior();
        void menuRepeticion();
        void menuPararRepeticion();
        void menuEliminar();
        void MensajeGuardar();
        void mensajeCancionAgregada();
        void mensajeVelloneraVacia();
        bool verificarDuracion(int minu, char a, int seg);
    friend class Vellonera;
};

#endif // MENU_H
