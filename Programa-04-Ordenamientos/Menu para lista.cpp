#include <iostream>
#include "listaDoble.hpp"

using namespace std;

void menu();
listaDoble *lista = new listaDoble();
Producto productoTemp;

int main()
{
    menu();
    system("PAUSE");
    return 0;
}

void menu()
{
    int opc = 1;
    string nombre, raza;
    int id;
    while (opc != 0)
    {
        system("cls");
        cout << "\tMenu\n";
        cout << "1. Insertar elemento (al inicio)\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Eliminar elemento\n";
        cout << "4. Vaciar lista\n";
        cout << "\nORDENAMIENTOS\n";
        cout << "5. Burbuja\n";
        cout << "6. Burbuja mejorada\n";
        cout << "7. Quick\n"; // TODO
        cout << "8. Merge\n"; // TODO
        cout << "9. Insert\n";
        cout << "10. Select\n"; 
        cout << "11. Shell\n";  // TODO ya lo enseño
        cout << "0. Salir\n\n";
        cin >> opc;
        switch (opc)
        {
        case 69: //haha funny number caso de prueba
            productoTemp.nombre = "Martillo";
            productoTemp.precio = 14.5;
            lista->insertaInicio(productoTemp);
            productoTemp.nombre = "Tornillo";
            productoTemp.precio = 22;
            lista->insertaInicio(productoTemp);
            productoTemp.nombre = "Disco";
            productoTemp.precio = 13.5;
            lista->insertaInicio(productoTemp);
            productoTemp.nombre = "Rotulador";
            productoTemp.precio = 27;
            lista->insertaInicio(productoTemp);
            productoTemp.nombre = "Vaso";
            productoTemp.precio = 9.2;
            lista->insertaInicio(productoTemp);
            productoTemp.nombre = "Camion";
            productoTemp.precio = 14;
            lista->insertaInicio(productoTemp);
            productoTemp.nombre = "Plato";
            productoTemp.precio = 15;
            lista->insertaInicio(productoTemp);
            productoTemp.nombre = "Lapiz";
            productoTemp.precio = 12.99;
            lista->insertaInicio(productoTemp);
            break;
        case 1:
            cout << "Ingrese el nombre: ";
            cin >> productoTemp.nombre;
            cout << "Ingresa el precio: ";
            cin >> productoTemp.precio;
            lista->insertaInicio(productoTemp);
            break;
        case 2:
            lista->mostrarListaStartToEnd();
            break;
        case 3:
            cout << "Ingrese la id del producto a eliminar: ";
            cin >> productoTemp.id;
            lista->eliminarElemento(productoTemp.id);
            break;
        case 4:
            lista->eliminarLista();
            break;
        case 5:
            lista->burbuja();
            break;
        case 6:
            lista->burbujaMejorada();
            break;
        case 7:

            break;
        case 8:
            lista->tamanoLista();
            break;
        case 9:
            lista->insertSort();
            break;
        case 10:
            lista->select();
            break;
        case 11:
            lista->shell();
            break;
        case 0:
            cout << "Gracias por su preferencia\n";
            break;
        default:
            cout << ("La opcion solicitada no existe\n");
            break;
        }
        system("PAUSE");
    }
}