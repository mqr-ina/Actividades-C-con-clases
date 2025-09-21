#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "ClsGestorProducto.h"
#include "Producto.h"

class Menu{

private:
    int _opcion;
    bool _salir;

public:
    void mostrar();
    void obtenerOpcion();
    void ejecutarMenu(GestorProducto gestorProducto, Producto producto);
    void opcionesMenu(GestorProducto gestorProducto, Producto &producto);

    Menu();
};



#endif // MENU_H_INCLUDED
