#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class Producto
{
public:
    Producto();
    Producto(string, float, int);
    string nombre;
    float precio;
    int id;
};

Producto::Producto(string _nombre, float _precio, int _id)
{
    nombre = _nombre;
    precio = _precio;
    id = _id;
}

Producto::Producto()
{

}
#endif