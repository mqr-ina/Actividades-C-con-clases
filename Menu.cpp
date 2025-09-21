#include <iostream>
#include "Menu.h"
#include "ClsGestorProducto.h"
#include "Producto.h"

void Menu::mostrar()
{
    system("cls");
    std::cout << "====MENU DE OPCIONES====" << std::endl;
    std::cout << std::endl;
    std::cout << "1- CARGAR PRODUCTO      " << std::endl;
    std::cout << "2- MOSTRAR PRODUCTO     " << std::endl;
    std::cout << "3- AGREGAR EN DISCO UN PRODUCTO  " << std::endl;
    std::cout << "4- LISTAR TODOS LOS PRODUCTOS  " << std::endl;
    std::cout << "5- BUSCAR POR ID " << std::endl;
    std::cout << "6- LISTAR SOLO LOS PRODUCTOS ACTIVOS " <<std::endl;
    std::cout  <<"7- LISTAR SOLO STOCK<PEDIDO     "<<std::endl;
    std::cout << std::endl;
    std::cout << "9- SALIR DEL SISTEMA  " << std::endl;
}
void Menu::obtenerOpcion()
{
    std::cout << "INGRESE UNA OPCION: " << std::endl;
    std:: cin >> _opcion;
}

void Menu::opcionesMenu(GestorProducto gestorProducto, Producto &producto)
{

    switch(_opcion)
    {
    case 1:
    {
        ///
        std::cout << "CARGO PRODUCTO" << std::endl;
        gestorProducto.CargarUnProducto(producto);
    }
    break;
    case 2:
    {
        ///
        std::cout << "MUESTRO PRODUCTO" << std::endl;
        gestorProducto.MostrarUnProducto(producto);
        system("pause");
    }
    break;
    case 3:
    {
        if(gestorProducto.guardarEnDiscoProducto(producto)){
            std::cout << "Registro agregado exitosamente";
        }
        system("pause");
    }
    case 4:
    {
        std::cout << "=== LISTADO DE PRODUCTOS ===" << std::endl;
        gestorProducto.listarTodosLosProductos();
        system("pause");
    }
    break;
        case 5:
    {
        std::cout << "=== BUSCAR PRODUCTO POR ID ===" << std::endl;
        int id, pos;
        std::cout<<"INGRESE EL ID: " << std::endl;
        std::cin>>id;
        pos = gestorProducto.buscarProductoPorId(id);
        std::cout <<"POS : " << pos <<std::endl;
        //vali
        ///copiar el registro a una variable d memorai
        Producto reg;
        reg= gestorProducto.leerProducto(pos);
        //reg = gestorProducto.

        //mostrar producto
        gestorProducto.MostrarUnProducto(reg);
        bool estado, grabo;
        std::cout << "Ingrese Estado [1 activo, 0 inactivo]: ";
        std::cin >> estado;
        reg.setEstado(estado);

        // escribir el registro modificado de nuevo en la misma posicion//
        grabo=gestorProducto.guardarEnDiscoProducto(reg,pos);//sobrecarga de metodos

        if(grabo){

            std::cout<<"SIIII"<<std::endl;
        } else{
            std::cout<<"ERROR" <<std::endl;
        }






        system("pause");
    }
    break;

        case 6:
    {
        std::cout << "=== LISTADO DE PRODUCTOS ACTIVOS ===" << std::endl;
        gestorProducto.listarSoloActivos();
        system("pause");
    }
    break;


     case 7:
    {
        std::cout << "=== LISTADO DE PRODUCTOS CON STOCK POR DEBAJO DE PUNTO DE PEDIDO ===" << std::endl;
        gestorProducto.Listarsolopedidos();
        system("pause");
    break;
    }
    case 9:
    {
        _salir=true;
        std::cout << "SALIMOS DEL SISTEMA" << std::endl;
        system("pause");
    }
    break;
    default:
        std::cout << "ERROR!!!" << std::endl;

    }

}
void Menu::ejecutarMenu(GestorProducto gestorProducto, Producto producto)
{

    while(!_salir)
    {
        mostrar();
        obtenerOpcion();
        opcionesMenu(gestorProducto,producto);
    }
}

Menu::Menu()
{
    _salir=false;
}
