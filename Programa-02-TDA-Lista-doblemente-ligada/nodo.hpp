#ifndef NODO_H
#define NODO_H
#pragma once
#include "animal.hpp"
using namespace std; 

class nodo
{
public:
    animal dato;
    nodo *siguiente;
    nodo *anterior;
    nodo();
    nodo(animal e)
    {
        dato = e;
        siguiente = nullptr;
        anterior = nullptr;
    };

private:
};
nodo::nodo()
{
    siguiente = nullptr;
    anterior = nullptr;
}
#endif