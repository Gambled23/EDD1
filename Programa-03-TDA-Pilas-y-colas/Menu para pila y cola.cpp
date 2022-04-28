#include <iostream>
#include <cstdlib>
#include "pila.hpp"
#include "cola.hpp"
#include "nodo.hpp"
#include "alumno.hpp"
void menuPila();
void menuCola();
pila *pila1 = new pila(); // Crea una nueva pila
cola *cola1 = new cola(); // Crea nueva cola
using namespace std;
alumno aluTemp;
int main()
{
    int opcMenu = 0;
    do
    {
        system("cls");
        cout << "\tMENU PRINCIPAN\nCual programa quieres usar?\n\t1) Pila\n\t2) Cola\n\t0) Salir\n";
        cin >> opcMenu;
        switch (opcMenu)
        {
        case 1:
            menuPila();
            break;
        case 2:
            menuCola();
            break;
        case 0:
            cout << "Gracias por su preferencia\n";
            break;
        default:
            cout << "Opcion incorrecta\n";
            break;
        }
    } while (opcMenu != 3);
    system("PAUSE");
    return 0;
}

void menuPila()
{
    int opc = 1;
    while (opc != 0)
    {
        system("cls");
        cout << "\nMENU PILA\n";
        cout << "1. Insertar elemento\n";
        cout << "2. Eliminar elemento\n";
        cout << "3. Buscar un elemento\n";
        cout << "4. Mostrar el top de la pila\n";
        cout << "5. Mostrar pila completa\n"; 
        cout << "6. Mostrar tamano pila\n";
        cout << "7. Vaciar pila\n";
        cout << "0. Menu principal\n\n";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese el nombre del alumno: ";
            cin >> aluTemp.nombre;
            cout << "Ingrese el codigo del alumno: ";
            cin >> aluTemp.codigo;
            pila1->push(aluTemp);
            break;
        case 2:
            pila1->pop();
            break;
        case 3:
            cout << "Ingrese la id del alumno a buscar: ";
            cin >> aluTemp.id;
            pila1->buscarElemento(aluTemp.id);
            break;
        case 4:
            pila1->topPila();
            break;
        case 5:
            pila1->mostrarPila();
            break;
        case 6:
            pila1->tamanoPila();
            break;
        case 7:
            pila1->eliminarPila();
            break;
        case 0:
            cout << "Gracias por su preferencia\n";
            break;
        default:
            cout << ("La opcion solicitada no existe\n");
            break;
        }
        system("PAUSE");
        system("cls");
    }
}

void menuCola()
{
    int opc;
    do
    {
        system("cls");
        cout << "\nMENU COLA" << endl;
        cout << "1) Encolar/queue" << endl;
        cout << "2) Desencolar/dequeue" << endl;
        cout << "3) Buscar por ID" << endl;
        cout << "4) Primer elemento" << endl;
        cout << "5) Ultimo elemento" << endl;
        cout << "6) Mostrar tamanio" << endl;
        cout << "7) Mostrar cola" << endl;
        cout << "8) Vaciar cola" << endl;
        cout << "0) Menu principal" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "Ingrese el nombre del alumno: ";
            cin >> aluTemp.nombre;
            cout << "Ingrese el codigo del alumno: ";
            cin >> aluTemp.codigo;
            cola1->queue(aluTemp);
            break;
        case 2:
            cola1->dequeue();
            break;
        case 3:
            cout << "Ingrese la id del alumno a buscar: ";
            cin >> aluTemp.id;
            cola1->buscar(aluTemp.id);
            break;
        case 4:
            cola1->first();
            break;
        case 5:
            cola1->last();
            break;
        case 6:
            cola1->tamanio();
            break;
        case 7:
            cola1->mostrarCola();
            break;
        case 8:
            cola1->vaciar();
            break;
        case 0:
            cout << "Gracias por su preferencia" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
        }
        system("PAUSE");
    } while (opc != 0);
}