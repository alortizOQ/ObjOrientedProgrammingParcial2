#include <string>
#ifndef COMPUTADORA_H_
#define COMPUTADORA_H_
using namespace std;

class Computer
{
public:
    Computer();
    Computer(int idP, string brandP, string osP, int ramP);
    void setBrand(string brandP);
    void setOS(string osP);
    void setRam(int ramP);
    void setId(int idP);
    string getBrand();
    string getOS();
    int getRam();
    int getId();
    bool isInUse();
    string getLocation();
    void displayDetails();
    bool hasBrand(string brand);

private:
    string brand, operatingSystem;
    int ram;
    int id;
};

Computer::Computer()
{
    brand = "N/A";
    operatingSystem = "N/A";
    ram = 0;
}

Computer::Computer(int idP, string brandP, string osP, int ramP)
{
    id = idP;
    brand = brandP;
    operatingSystem = osP;
    ram = ramP;
}

void Computer::setBrand(string brandP)
{
    brand = brandP;
}

void Computer::setOS(string osP)
{
    operatingSystem = osP;
}

void Computer::setRam(int ramP)
{
    ram = ramP;
}

void Computer::setId(int idP)
{
    id = idP;
}

string Computer::getBrand()
{
    return brand;
}

string Computer::getOS()
{
    return operatingSystem;
}

int Computer::getRam()
{
    return ram;
}

int Computer::getId()
{
    return id;
}

bool Computer::isInUse()
{
    return id != 0;
}

string Computer::getLocation()
{
    return (id != 0) ? "Asignado" : "No asignado";
}

void Computer::displayDetails()
{
    cout << "ID: " << id << ", Marca: " << brand << ", Sistema Operativo: " << operatingSystem << ", RAM: " << ram << "GB, " << getLocation() << endl;
}

bool Computer::hasBrand(string brandToCheck)
{
    return brand == brandToCheck;
}

#endif