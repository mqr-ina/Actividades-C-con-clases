#include "ClsGestorProducto.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>


GestorProducto::GestorProducto()
{
    _rutaDireccion = "Producto.dat";
}

void GestorProducto::CargarUnProducto(Producto &producto)
{
    int id,puntoDePedido,stock;
    float precioUnitario;
    std::string nombre,descripcion, categoria, marca;
    bool estado;

    std::cout<<"INGRESE EL ID DEL PRODUCTO: ";
    std::cin>>id;
    std::cin.ignore();

    std::cout<<"INGRESE EL NOMBRE DEL PRODUCTO: ";
    std::getline(std::cin,nombre);

    std::cout<<"INGRESE LA DESCRIPCION DEL PRODUCTO: ";
    std::getline(std::cin,descripcion);

    std::cout<<"INGRESE EL PRECIO UNITARIO DEL PRODUCTO: ";
    std::cin>>precioUnitario;

    std::cout<<"INGRESE EL PUNTO DE PEDIDO DEL PRODUCTO: ";
    std::cin>>puntoDePedido;

    std::cout<<"INGRESE EL STOCK DEL PRODUCTO: ";
    std::cin>>stock;
    std::cin.ignore();

    std::cout<<"INGRESE LA CATEGORIA DEL PRODUCTO: ";
    std::getline(std::cin,categoria);

    std::cout<<"INGRESE LA MARCA DEL PRODUCTO: ";
    std::getline(std::cin,marca);

    std::cout<<"INGRESE EL ESTADO DEL PRODUCTO: ";
    std::cin>>estado;

    producto.setId(id);
    producto.setNombre(nombre);
    producto.setDescripcion(descripcion);
    producto.setPrecioUnitario(precioUnitario);
    producto.setPuntoDePedido(puntoDePedido);
    producto.setStock(stock);
    producto.setCategoria(categoria);
    producto.setMarca(marca);
    producto.setEstado(estado);
}
void GestorProducto::MostrarUnProducto(Producto producto)
{
    std::cout<<"ID PRODUCTO: " << producto.getIde() << std::endl;
    std::cout<<"NOMBRE DEL PRODUCTO: " << producto.getNombre() << std::endl;
    std::cout<<"DESCRIPCION DEL PRODUCTO: " << producto.getDescripcion() << std::endl;
    std::cout<<"PRECIO UNITARIO DEL PRODUCTO: " << producto.getPrecioUnitario() << std::endl;
    std::cout<<"PEDIDO DEL PRODUCTO: " << producto.getPuntoDePedido() << std::endl;
    std::cout<<"STOCK DEL PRODUCTO: " << producto.getStock() << std::endl;
    std::cout<<"CATEGORIA DEL PRODUCTO: " << producto.getCategoria() << std::endl;
    std::cout<<"MARCA DEL PRODUCTO: " << producto.getMarca() << std::endl;
    std::cout<<"ESTADO DEL PRODUCTO: " << (producto.getEstado() ? "ACTIVO" : "INACTIVO") <<std:: endl;
    std::cout<<"\n";
}

bool GestorProducto::guardarEnDiscoProducto(Producto reg){
    FILE *p;
    p = fopen(_rutaDireccion.c_str(), "ab+");
    if(p==NULL){
        exit(1);
    }
    bool grabo = fwrite(&reg, sizeof(Producto),1, p);
    fclose(p);
    return grabo;
}

void GestorProducto::listarTodosLosProductos(){

    Producto reg;
    FILE *p;
    p = fopen(_rutaDireccion.c_str(), "rb");
    if(p==NULL){
        exit(1);
    }
    while(fread(&reg, sizeof(Producto),1, p))
    MostrarUnProducto(reg);
    fclose(p);
}

void GestorProducto::Listarsolopedidos(){
    Producto reg;
    FILE *p;
    p = fopen(_rutaDireccion.c_str(),"rb");
    if(p==NULL){
        exit(201);
    }

    while(fread(&reg, sizeof(Producto),1,p)){
        if(reg.getStock()<reg.getPuntoDePedido()){
            MostrarUnProducto(reg);
        }
    }
fclose(p);
}



void GestorProducto::listarSoloActivos(){
    Producto reg;
    FILE *p;
    p = fopen(_rutaDireccion.c_str(),"rb");
    if(p==NULL){
        exit(201);
    }

    while(fread(&reg, sizeof(Producto),1,p)){
        if(reg.getEstado()){
            MostrarUnProducto(reg);
        }
    }
fclose(p);
}

int GestorProducto::buscarProductoPorId(int id){
    int pos;
    Producto reg;
    FILE *p;
    p = fopen(_rutaDireccion.c_str(), "rb");
    if(p==NULL){
        exit(1);
    }
    int i=0;
    while(fread(&reg, sizeof(Producto),1, p)){
        if(reg.getIde()==id){
            pos = i;
            fclose(p);
            return pos;
        }
        i++;
    }
    fclose(p);
    return -1;
}

Producto GestorProducto::leerProducto(int pos) {
    Producto reg;
    FILE *p;
    ///
    p=fopen(_rutaDireccion.c_str(), "rb");
    if(p==NULL){
        exit(500);
    }
    // me posiciono en el registro exacto
    fseek(p,sizeof(Producto)*pos,SEEK_SET);
    fread(&reg,sizeof(Producto),1,p);
    ///Cierro arch//
    fclose(p);


    return reg;
   }


bool GestorProducto::guardarEnDiscoProducto(Producto reg, int pos){
    bool grabo;
    //apertura arch
    FILE *p;
    p = fopen(_rutaDireccion.c_str(),"rb+");
    if(p==NULL){
        exit(501);
    }
    ///posiciono el cursor
    fseek(p, sizeof(Producto)*pos,SEEK_SET);
    grabo = fwrite(&reg, sizeof(Producto),1,p);
    ///Cierro
    fclose(p);

    return grabo;
}

