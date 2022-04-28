#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "nodo.hpp"
#include "animal.hpp"
#pragma once
int id = 1;
using namespace std;

class listaDoble
{
public:
    listaDoble();
    nodo *h; // Puntero que apunta a inicio
    nodo *t; // Puntero que apunta a final
    void inicializa();
    void insertaInicio(animal);
    void insertarFinal(animal);
    void mostrarListaStartToEnd();
    void mostrarListaEndToStart();
    void tamanoLista();
    void buscarElemento(int);
    void eliminarElemento(int);
    void eliminarLista();
};

listaDoble::listaDoble()
{
    h = nullptr; // Inicia apuntando a null
    t = nullptr; // Apuntador a tail
}

void listaDoble::inicializa()
{
    h = nullptr;
    t = nullptr;
}

//* *OPERACIONES
void listaDoble::insertaInicio(animal n)
{
    nodo *nuevo_nodo = new nodo(n); // crear nuevo nodo dinamico
    if (h == nullptr)                  // Si la lista esta vacia
    {
        h = nuevo_nodo;
        t = nuevo_nodo;
    }
    else // Si no esta vacia
    {
        h->anterior = nuevo_nodo;
        nuevo_nodo->siguiente = h;
        h = nuevo_nodo;
    }
    nuevo_nodo->dato.id = id;
    cout<<"Se ha agregado con la ID: "<<id<<endl;
    id++;
}

void listaDoble::insertarFinal(animal n)
{
    nodo *nuevo_nodo = new nodo(n); // crear nuevo nodo dinamico
    if (h == nullptr)
    {
        h = nuevo_nodo;
        t = nuevo_nodo;
    }
    else
    {
        t->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = t;
        t = nuevo_nodo;
    }
    nuevo_nodo->dato.id = id;
    cout<<"Se ha agregado con la ID: "<<id<<endl;
    id++;
}

void listaDoble::mostrarListaStartToEnd()
{
    if (h != nullptr)
    {
        nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
        actual = h;                // Apuntar el nodo actual al inicio, para recorrer desde el 1er elemento

        while (actual != nullptr) // Mientras sigamos apuntando a un dato, y no al NULL, significa que seguimos en la lista
        {
            cout << "Nombre: " << actual->dato.nombre << endl; // Imprimir el dato en el que nos encontramos
            cout << "Raza: " << actual->dato.raza << endl;
            cout << "ID: " << actual->dato.id << endl
                 << endl;
            actual = actual->siguiente; // Recorrer un nodo
        }
        cout << endl;
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}
void listaDoble::mostrarListaEndToStart()
{
    if (t != nullptr)
    {
        nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
        actual = t;                // Apuntar el nodo actual al final, para recorrer desde el ultimo elemento

        while (actual != nullptr) // Mientras sigamos apuntando a un dato, y no al NULL, significa que seguimos en la lista
        {
            cout << "Nombre: " << actual->dato.nombre << endl; // Imprimir el dato en el que nos encontramos
            cout << "Raza: " << actual->dato.raza << endl;
            cout << "ID: " << actual->dato.id << endl
                 << endl;
            actual = actual->anterior; // Recorrer un nodo hacia atras
        }
        cout << endl;
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}

void listaDoble::tamanoLista()
{
    int i = 0;
    nodo *actual = new nodo();
    actual = h;
    while (actual != nullptr)
    {
        i++;
        actual = actual->siguiente;
    }
    cout << "La lista tiene " << i << " elementos" << endl;
}

void listaDoble::buscarElemento(int n)
{
    bool bandera = true;
    nodo *actual = new nodo(); // Creamos nodo actual para saber en cual nodo estamos ubicados mientrar recorremos la lista
    actual = h;                // Apuntar el nodo actual al inicio, para recorrer desde el 1er elemento

    while ((actual != nullptr) and (bandera)) // Mientras sigamos apuntando a un dato, y no al NULL, significa que seguimos en la lista
    {
        if (actual->dato.id == n)
        {
            cout << "Nombre: " << actual->dato.nombre << endl;
            cout << "Raza: " << actual->dato.raza << endl;
            cout << "ID: " << actual->dato.id << endl;
            bandera = false;
        }
        actual = actual->siguiente; // Recorrer un nodo
    }
    if (bandera) //Si bandera sigue true es porque no encontro el elemento
    {
        cout<<"La ID no existe en la lista"<<endl;
    }
}

void listaDoble::eliminarElemento(int n)
{
    if (h != nullptr)
    {
        nodo *aux_borrar;
        aux_borrar = h;
        while ((aux_borrar != nullptr) && (aux_borrar->dato.id != n)) // Recorrer lista
        {
            aux_borrar = aux_borrar->siguiente;
        }
        if (aux_borrar == nullptr) // Si el elemento no se encuentra en la lista(no se elimina)
        {
            cout << "La ID no existe en la lista\n";
        }
        else if ((aux_borrar == h) and (aux_borrar == t) and (t == h)) // Si es el unico elemento en la lista
        {
            h = nullptr;
            t = h;
            cout << "El elemento con la ID '" << n << "' ha sido borrado\n";
            delete aux_borrar;
        }
        else if (aux_borrar->anterior == nullptr) // El primer elemento es el que se elimina
        {
            h = h->siguiente; // el inicio de la lista se cambia, pues se elimino el inicio
            h->anterior = nullptr;
            cout << "El elemento con la ID '" << n << "' ha sido borrado\n";
            delete aux_borrar;
        }
        else if (aux_borrar->siguiente == nullptr) // El elemento que se elimina es del final
        {
            t = t->anterior;
            t->siguiente = nullptr;
            cout << "El elemento con la ID '" << n << "' ha sido borrado\n";
            delete aux_borrar;
        }
        else // El elemento que se elimina esta en medio
        {
            aux_borrar->anterior->siguiente = aux_borrar->siguiente;
            aux_borrar->siguiente->anterior = aux_borrar->anterior;
            cout << "El elemento con la ID '" << n << "' ha sido borrado\n"; // Imprimir el elemento a borrar
            delete aux_borrar;
        }
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}

void listaDoble::eliminarLista()
{
    while (h != NULL) // Para hacer la eliminacion de cada nodo hasta que este vacia
    {
        nodo *aux = h; // Crear auxiliar que apunte al inicio de la lista
        h = aux->siguiente;
        delete aux;
    }
    cout << "La lista ha sido vaciada\n";
    t = nullptr;
}

#endif