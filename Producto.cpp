#include "Producto.h"
#include <iostream>
#include <cstring> /// strcpy, strcmp, strlen, etc
#include <string>

using namespace std;

Producto::Producto()
{
    _Id = -1;
    strcpy(_Nombre, "SIN_NOMBRE");
    strcpy(_Descripcion,"SIN_DESCRIPCION");
    _PrecioUnitario= 0.0;
    _PuntoDePedido = 0;
    _Stock= 0;
    strcpy(_Categoria,"SIN_CATEGORIA");
    strcpy(_Marca, "sin_marca");
    _Estado = false;
}

Producto::Producto(int id, string nombre, string descripcion, float precioUnitario, int puntoDePedido, int stock, string categoria, string marca, bool estado)
{
    _Id = id;
    strcpy(_Nombre, nombre.c_str());
    strcpy(_Descripcion,descripcion.c_str());
    _PrecioUnitario= precioUnitario;
    _PuntoDePedido = puntoDePedido;
    _Stock= stock;
    strcpy(_Categoria,categoria.c_str());
    strcpy(_Marca, marca.c_str());
    _Estado = estado;
}

void Producto::setId(int id)
{
    _Id = id;
}
void Producto::setNombre(std::string nombre)
{
    strcpy(_Nombre,nombre.c_str());
}
void Producto::setDescripcion(std::string descripcion)
{
    strcpy(_Descripcion,descripcion.c_str());
}
void Producto::setPrecioUnitario(float precioUnitario)
{
    _PrecioUnitario = precioUnitario;
}
void Producto::setPuntoDePedido(int puntoPePedido)
{
    _PuntoDePedido = puntoPePedido;
}
void Producto::setStock(int stock)
{
    _Stock = stock;
}
void Producto::setCategoria(std::string categoria)
{
    strcpy(_Categoria,categoria.c_str());
}
void Producto::setMarca(std::string marca)
{
    strcpy(_Marca,marca.c_str());
}
void Producto::setEstado(bool estado)
{
    _Estado = estado;
}

int Producto::getIde()
{
    return _Id;
}
std::string Producto::getNombre()
{
    return _Nombre;
}
std::string Producto::getDescripcion()
{
    return _Descripcion;
}
float Producto::getPrecioUnitario()
{
    return _PrecioUnitario;
}
int Producto::getPuntoDePedido()
{
    return _PuntoDePedido;
}
int Producto::getStock()
{
    return _Stock;
}
std::string Producto::getCategoria()
{
    return _Categoria;
}
std::string Producto::getMarca()
{
    return _Marca;
}
bool Producto::getEstado()
{
    return _Estado;
}
