#ifndef CLSGESTORPRODUCTO_H_INCLUDED
#define CLSGESTORPRODUCTO_H_INCLUDED

#include"Producto.h"
#include<string>

class GestorProducto
{
public:

    void CargarUnProducto(Producto &); // Agregar un nuevo producto al sistema.
    void MostrarUnProducto(Producto); // Visualizar los datos de un producto específico por su id.


    /// MANIPULACION DE ARCHIVOS
    bool guardarEnDiscoProducto(Producto);
    void listarTodosLosProductos();
    int buscarProductoPorId(int); ///el int representa el ID del producto
    void leerUnRegistro(int);
    Producto leerProducto(int); ///devuelve un producto, el entero representa la posicion del registro en memoria
    bool guardarEnDiscoProducto(Producto, int);
    void listarSoloActivos();
    void Listarsolopedidos();

    /// OBTENER_PROXIMO_ID()

    GestorProducto();

private:
    std::string _rutaDireccion;
};

#endif // CLSGESTORPRODUCTO_H_INCLUDED
