#ifndef PILA_H
#define PILA_H
#include <iostream>
#include <cstdlib>
#include "nodo.hpp"
#include "alumno.hpp"

#pragma once
int id = 1;
using namespace std;

class pila
{
public:
    pila();
    nodo *h; // Puntero que apunta a inicio
    void mostrarPila();
    void inicializa();
    void push(alumno);
    void pop();
    void tamanoPila();
    void buscarElemento(int);
    void topPila();
    void eliminarPila();
};

pila::pila()
{
    h = nullptr; // Inicia apuntando a null
}

void pila::inicializa()
{
    h = nullptr;
}

//* *OPERACIONES
void pila::push(alumno n)
{
    nodo *nuevo_nodo = new nodo(n); // crear nuevo nodo dinamico
    nuevo_nodo->siguiente = h;
    h = nuevo_nodo;
    nuevo_nodo->dato.id = id;
    cout << "Se ha agregado con la ID: " << id << endl;
    id++;
}

void pila::pop()
{
    nodo *aux = h;
    if (aux)
    {
        cout<<"Alumno "<<h->dato.nombre<<" eliminado"<<endl;
        h = aux->siguiente;
        delete (aux);
    }
    else
    {
        cout << "Pila vacia" << endl;
    }
}
void pila::tamanoPila()
{
    nodo *aux = new nodo();
    aux = h;
    int cont = 0;
    while (aux != nullptr)
    {
        cont++;
        aux = aux->siguiente;
    }
}

void pila::buscarElemento(int n)
{
    nodo *aux = new nodo();
    aux = h;
    bool bandera = false;
    while (aux != nullptr and bandera == false)
    {
        if (aux->dato.id == n)
        {
            cout << "Nombre del alumno: " << aux->dato.nombre << endl;
            cout << "Codigo de alumno: " << aux->dato.codigo << endl;
            cout << "ID de alumno: " << aux->dato.id << endl;
            bandera = true;
        }
        aux = aux->siguiente;
    }
    if (bandera == false)
    {
        cout << "Elemento no encontrado" << endl;
    }
}
void pila::eliminarPila()
{
    if (h)
    {
        while (h)
        {
            pila::pop();
        }
    }
    else
    {
        cout << "PILA VACIA\n";
    }

    pila::pop();
}
void pila::topPila()
{
    cout<<"El top de la pila tiene la ID: "<<h->dato.id<<endl;
    cout<<"Nombre del alumno: "<<h->dato.nombre<<endl;
    cout<<"Codigo del alumno: "<<h->dato.codigo<<endl;
}
void pila::mostrarPila()
{
    nodo *aux = new nodo();
    aux = h;
    if (h)
    {
        while (aux != nullptr)
    {
        cout<<"\n\n Nombre del alumno: "<<aux->dato.nombre<<endl;
        cout<<"Codigo del alumno: "<<aux->dato.codigo<<endl;
        cout<<"ID del alumno: "<<aux->dato.id<<endl;
        aux = aux->siguiente;
    }
    }
    else
    {
        cout<<"PILA VACIA"<<endl;
    }
    
}

#endif