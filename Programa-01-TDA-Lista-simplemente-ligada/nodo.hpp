#ifndef NODO_H
#define NODO_H
#pragma once
using namespace std; 

class nodo
{
public:
    string dato;
    nodo *siguiente;
    nodo();
    nodo(string e)
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