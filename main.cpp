#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    GestorProducto gestorProducto;
    Producto producto;

    Menu menu;
    menu.ejecutarMenu(gestorProducto, producto);

    return 0;
}
