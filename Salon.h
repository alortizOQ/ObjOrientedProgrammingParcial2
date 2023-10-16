#include <string>
#include "Edificio.h"
#include "Computer.h"
#ifndef SALON_H
#define SALON_H
using namespace std;

class Salon
{
public:
    Salon();
    Salon(int idP, string nameP, int capacidadP, Computer computerP);
    void setId(int idP);
    void setName(string nameP);
    void setCapacidad(int capacidadP);
    void setComputer(Computer computerP);
    void displayComputerInSalon(Computer arrComputers[], int maxComputadoras);
    int getId();
    string getName();
    int getCapacidad();
    Computer getComputer();

private:
    int id = 0;
    string name = "N/A";
    int capacidad = 0;
    Computer computer;
};

Salon::Salon()
{
    id = 0;
    name = "";
    capacidad = 0;
    Computer computer;
}

Salon::Salon(int idP, string nameP, int capacidadP, Computer computerP)
{
    id = idP;
    name = nameP;
    capacidad = capacidadP;
    computer = computerP;
}

void Salon::setId(int idP)
{
    id = idP;
}

void Salon::setName(string nameP)
{
    name = nameP;
}

void Salon::setCapacidad(int capacdidadP)
{
    capacidad = capacdidadP;
}

void Salon::setComputer(Computer computerP)
{
    computer = computerP;
}

int Salon::getId()
{
    return id;
}

string Salon::getName()
{
    return name;
}

int Salon::getCapacidad()
{
    return capacidad;
}

Computer Salon::getComputer()
{
    return computer;
}

void Salon::displayComputerInSalon(Computer arrComputers[], int maxComputadoras)
{
    Computer salonComputer = getComputer();
    if (salonComputer.isInUse())
    {
        cout << "En Salon " << name << ": ";
        salonComputer.displayDetails();
    }
}

#endif