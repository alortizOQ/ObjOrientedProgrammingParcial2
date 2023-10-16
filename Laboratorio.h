#include <string>
#include "Edificio.h"
#include "Computer.h"
#ifndef LABORATORIO_H
#define LABORATORIO_H
using namespace std;

class Laboratorio
{
public:
    Laboratorio();
    Laboratorio(int idP, string nameP, int capacidadP, Computer computerP);
    void setID(int idP);
    void setName(string nameP);
    void setCapacidad(int capacidadP);
    void setComputer(Computer computerP);
    void displayComputerInLaboratorio(Computer arrComputers[], int maxComputadoras);

    int getId();
    string getName();
    int getCapacidad();
    Computer getComputer();

private:
    int id = 0;
    string name;
    int capacidad;
    Computer computer;
};

Laboratorio::Laboratorio()
{
    id = 0;
    name = "";
    capacidad = 0;
}

Laboratorio::Laboratorio(int idP, string nameP, int capacidadP, Computer computerP)
{
    id = idP;
    name = nameP;
    capacidad = capacidadP;
    computer = computerP;
}

void Laboratorio::setID(int idP)
{
    id = idP;
}

void Laboratorio::setName(string nameP)
{
    name = nameP;
}

void Laboratorio::setCapacidad(int capacidadP)
{
    capacidad = capacidadP;
}

void Laboratorio::setComputer(Computer computerP)
{
    computer = computerP;
}

int Laboratorio::getId()
{
    return id;
}

string Laboratorio::getName()
{
    return name;
}

int Laboratorio::getCapacidad()
{
    return capacidad;
}

Computer Laboratorio::getComputer()
{
    return computer;
}

void Laboratorio::displayComputerInLaboratorio(Computer arrComputers[], int maxComputadoras)
{
    Computer labComputer = getComputer();
    if (labComputer.isInUse())
    {
        cout << "En Laboratorio " << name << ": ";
        labComputer.displayDetails();
    }
}

#endif