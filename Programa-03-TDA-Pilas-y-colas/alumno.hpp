#ifndef alumno_H
#define alumno_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class alumno
{
public:
    alumno(string, string);
    alumno();
    string nombre, codigo;
    int id;
private:

};
//Constructores
alumno::alumno(string nom, string cdg)
{
    nombre = nom;
    codigo = cdg;
}
alumno::alumno()
{
    nombre = "";
    codigo = "";
    id = 0;
}
#endif