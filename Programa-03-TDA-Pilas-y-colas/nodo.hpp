#ifndef NODO_H
#define NODO_H
#pragma once
#include "alumno.hpp"
using namespace std; 

class nodo
{
public:
    alumno dato;
    nodo *siguiente;
    nodo();
    nodo(alumno e)
    {
        dato = e;
        siguiente = nullptr;
    };

private:
};

nodo::nodo()
{
    siguiente = nullptr;
}
#endif