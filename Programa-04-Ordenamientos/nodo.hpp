#ifndef NODO_H
#define NODO_H
#pragma once
#include "Producto.hpp"
using namespace std; 

class nodo
{
public:
    Producto dato;
    nodo *siguiente;
    nodo *anterior;
    nodo();
    nodo(Producto e)
    {
        dato = e;
        siguiente = nullptr;
        anterior = nullptr;
    };
};
nodo::nodo()
{
    siguiente = nullptr;
    anterior = nullptr;
}

#endif