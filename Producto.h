#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<iostream>
#include<string>

class Producto
{
public:
    void setId(int);
    void setNombre(std::string);
    void setDescripcion(std::string);
    void setPrecioUnitario(float);
    void setPuntoDePedido(int);
    void setStock(int);
    void setCategoria(std::string);
    void setMarca(std::string);
    void setEstado(bool);

    int getIde();
    std::string getNombre();
    std::string getDescripcion();
    float getPrecioUnitario();
    int getPuntoDePedido();
    int getStock();
    std::string getCategoria();
    std::string getMarca();
    bool getEstado();

    Producto();
    Producto(int id, std::string nombre, std::string descripcion, float precioUnitario, int puntoDePedido, int stock, std::string categoria, std::string marca, bool estado);


private:

    int _Id; ///(identificador único del producto).
    char _Nombre[30];
    char _Descripcion[30];/// del producto.
    float _PrecioUnitario;
    int _PuntoDePedido;// (cantidad mínima a partir de la cual el stock de un producto debe renovarse).
    int _Stock ; ///(cantidad disponible actual).
    char _Categoria[30];
    char _Marca[30];
    bool _Estado; ///(activo/inactivo).

   /// Fecha fechaAlta;
};

#endif // PRODUCTO_H
