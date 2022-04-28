#include <iostream>
#include "listaDoble.hpp"

using namespace std;

void menu();
listaDoble *lista = new listaDoble(); //?Crea una nueva lista
animal aniTemp;

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
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar lista inico a fin\n";
        cout << "4. Mostrar lista fin a inicio\n";
        cout << "5. Buscar un elemento\n";
        cout << "6. Eliminar elemento\n";
        cout << "7. Vaciar lista\n";
        cout << "8. Mostrar tamano lista\n";
        cout << "0. Salir\n\n";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese el nombre: ";
            cin >> aniTemp.nombre;
            cout << "Ingrese la raza: ";
            cin >> aniTemp.raza;
            lista->insertaInicio(aniTemp);
            break;
        case 2:
            cout << "Ingrese el nombre: ";
            cin >> aniTemp.nombre;
            cout << "Ingrese la raza: ";
            cin >> aniTemp.raza;
            lista->insertarFinal(aniTemp);
            break;
        case 3:
            lista->mostrarListaStartToEnd();
            break;
        case 4:
            lista->mostrarListaEndToStart();
            break;
        case 5:
            cout << "Ingrese la id del animal a buscar: ";
            cin >> aniTemp.id;
            lista->buscarElemento(aniTemp.id);
            break;
        case 6:
            cout << "Ingrese la id del animal a eliminar: ";
            cin >> aniTemp.id;
            lista->eliminarElemento(aniTemp.id);
            break;
        case 7:
            lista->eliminarLista();
            break;
        case 8:
            lista->tamanoLista();
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