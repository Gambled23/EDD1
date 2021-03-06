#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "nodo.hpp"
#include "Producto.hpp"
#pragma once
int id = 1;
int numElementos;
using namespace std;

class listaDoble
{
public:
    listaDoble();
    listaDoble(listaDoble *);
    nodo *h; // Puntero que apunta a inicio
    nodo *t; // Puntero que apunta a final
    void inicializa();
    void insertaInicio(Producto);
    void mostrarListaStartToEnd();
    int tamanoLista();
    void eliminarElemento(int);
    void eliminarLista();
    void burbuja();
    void burbujaMejorada();
    void quick(listaDoble *l);
    void merge(int, listaDoble *);
    void insertSort();
    void select();
};

listaDoble::listaDoble()
{
    h = nullptr; // Inicia apuntando a null
    t = nullptr; // Apuntador a tail
}

listaDoble::listaDoble(listaDoble *l)
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
void listaDoble::insertaInicio(Producto n)
{
    nodo *nuevo_nodo = new nodo(n); // crear nuevo nodo dinamico
    if (h == nullptr)               // Si la lista esta vacia
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
            cout << "Precio: " << actual->dato.precio << endl;
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

int listaDoble::tamanoLista()
{
    int i = 0;
    nodo *actual = new nodo();
    actual = h;
    while (actual != nullptr)
    {
        i++;
        actual = actual->siguiente;
    }
    numElementos = i;
    return i;
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

void listaDoble::burbuja()
{
    listaDoble::tamanoLista();
    Producto aux;
    nodo *actual = new nodo();
    for (size_t i = 0; i < numElementos; i++)
    {
        actual = h;
        for (size_t j = 0; j < numElementos; j++)
        {
            if (actual->siguiente != nullptr)
            {
                if (actual->dato.precio > actual->siguiente->dato.precio)
                {
                    aux = actual->dato;
                    actual->dato = actual->siguiente->dato;
                    actual->siguiente->dato = aux;
                }
                actual = actual->siguiente;
            }
        }
    }
    system("cls");
    cout << "Ordenado por burbuja:\n";
    listaDoble::mostrarListaStartToEnd();
}

void listaDoble::burbujaMejorada()
{
    listaDoble::tamanoLista();
    Producto aux;
    nodo *actual = new nodo();
    bool bandera = true;
    int i = 0, j = 0, m = numElementos;
    for (size_t i = 0; i < numElementos and bandera; i++)
    {
        actual = h;
        bandera = false;
        for (size_t j = 0; j < numElementos - i - 1; j++)
        {
            if (actual->siguiente != nullptr)
            {
                if (actual->dato.precio > actual->siguiente->dato.precio)
                {
                    aux = actual->dato;
                    actual->dato = actual->siguiente->dato;
                    actual->siguiente->dato = aux;
                    bandera = true;
                }
                actual = actual->siguiente;
            }
        }
    }
    system("cls");
    cout << "Ordenado por burbuja mejorada:\n";
    listaDoble::mostrarListaStartToEnd();
}

void listaDoble::quick(listaDoble *l)
{
    nodo *piv;
    nodo *pivGuardar;
    nodo *aux;

    listaDoble *mayores = new listaDoble;
    listaDoble *menores = new listaDoble;

    if (l->h)
    {
        piv = l->h;
        pivGuardar = new nodo(l->h->dato);
        aux = l->h->siguiente;

        while (aux)
        {
            if (aux->dato.precio < piv->dato.precio)
            {
                menores->insertaInicio(aux->dato);
            }
            else
            {
                mayores->insertaInicio(aux->dato);
            }
            aux = aux->siguiente;
        }

        quick(menores);
        quick(mayores);

        aux = l->h;
        nodo *men = menores->h;
        while (men)
        {
            aux->dato = men->dato;
            aux = aux->siguiente;
            men = men->siguiente;
        }
        aux->dato = pivGuardar->dato;
        aux = aux->siguiente;

        nodo *may = mayores->h;
        while (may)
        {
            aux->dato = may->dato;
            aux = aux->siguiente;
            may = may->siguiente;
        }
    }
}

void listaDoble::merge(int tam, listaDoble *l)
{
    listaDoble *derecha = new listaDoble;
    listaDoble *izquierda = new listaDoble;
    nodo *aux = l->h;
    int med = tam / 2;
    int dif = tam % 2;
    int i, j;
    if (l->tamanoLista() > 1)
    {
        i = 0;
        while (aux and i < med)
        {
            izquierda->insertaInicio(aux->dato);
            i++;
            aux = aux->siguiente;
        }

        j = 0;
        while (aux and j < med + dif)
        {
            derecha->insertaInicio(aux->dato);
            j++;
            aux = aux->siguiente;
        }

        merge(izquierda->tamanoLista(), izquierda);
        merge(derecha->tamanoLista(), derecha);

        nodo *iz = izquierda->h;
        nodo *de = derecha->h;
        aux = l->h;
        i = 0;
        // mergear
        while (iz and de)
        {
            if (iz->dato.precio < de->dato.precio)
            {
                aux->dato = iz->dato;
                iz = iz->siguiente;
                aux = aux->siguiente;
            }
            else
            {
                aux->dato = de->dato;
                de = de->siguiente;
                aux = aux->siguiente;
            }
        }
        // guardar el resto de la izq
        if (iz)
        {
            while (iz)
            {
                aux->dato = iz->dato;
                iz = iz->siguiente;
                aux = aux->siguiente;
            }
        }

        // guardar el resto de la der
        if (de)
        {
            while (de)
            {
                aux->dato = de->dato;
                de = de->siguiente;
                aux = aux->siguiente;
            }
        }
    }
}

void listaDoble::insertSort()
{
    listaDoble::tamanoLista();
    nodo *pos = new nodo();
    pos = h;
    int cont = 0;
    Producto aux; // Aux es el valor del numero, pos es la posicion en la que estamos
    for (size_t i = 0; i < numElementos; i++)
    {
        cont = i;
        aux = pos->dato;
        while ((pos != h) and (pos->anterior->dato.precio) > aux.precio)
        {
            pos->dato = pos->anterior->dato;
            pos = pos->anterior;
            cont--;
        }
        pos->dato = aux;
        for (cont; cont <= i; cont++) // por que funca???
        {
            pos = pos->siguiente;
        }
    }
    system("cls");
}

void listaDoble::select()
{
    listaDoble::tamanoLista();
    nodo *aux = new nodo();
    aux = h;
    nodo *min = new nodo();
    nodo *aux2 = new nodo();
    Producto temp;
    while (aux)
    {
        min = aux; // Valor minimo empieza al principio
        aux2 = aux->siguiente;
        while (aux2) // Comparar para encontrar el menor
        {
            if (min->dato.precio > aux2->dato.precio)
            {
                min = aux2;
            }
            aux2 = aux2->siguiente;
        }
        temp = aux->dato; // Intercambios
        aux->dato = min->dato;
        min->dato = temp;

        aux = aux->siguiente; // Recorrer un nodo en el "bloqueo" (pag 7 investigacion 7)
    }
}
#endif