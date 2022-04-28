#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

class animal
{
public:
    animal(string, string);
    animal();
    string nombre, raza;
    int id;
private:

};
//Constructores
animal::animal(string nom, string raz)
{
    nombre = nom;
    raza = raz;
}
animal::animal()
{
    nombre = "";
    raza = "";
    id = 0;
}
#endif