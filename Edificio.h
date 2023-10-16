#include <string>
#ifndef EDIFICIO_H
#define EDIFICIO_H
#include "Laboratorio.h"
#include "Salon.h"
#include "Computer.h"
using namespace std;

class Edificio
{
public:
    Edificio();
    Edificio(int idP, int cantLabsP, int cantSalonesP, string nameP, string responsibleP, int listalabsP[], int listaSalonesP[]);
    void setId(int idP);
    void setName(string nameP);
    void setResponsible(string responsibleP);
    void displayComputersInEdificio(Laboratorio arrLaboratorios[], Salon arrSalones[], Computer arrComputers[], int maxLabs, int maxSalones, int maxComputadoras);
    bool findLabOrSalonForComputer(int computerId, int &edificioNumber, int &labOrSalonIndex, Laboratorio arrLaboratorios[], Salon arrSalones[], int maxLabs, int maxSalones);

    int getId();
    string getName();
    string getResponsible();
    int getCantLabs();
    int getCantSalones();
    void muestraLabs();
    void muestraSalones();

    int getLabAtIndex(int index);
    int getSalonAtIndex(int index);

    bool agregarLab(int labID);
    bool agregarSalon(int salonID);

private:
    int id = 0;
    string name, responsible;
    int cantLabs;
    int *listaLabs;
    int cantSalones;
    int *listaSalones;
};

Edificio::Edificio()
{
    id = 0;
    name = "";
    responsible = "";
    cantLabs = 0;
    cantSalones = 0;
    listaLabs = new int[10];
    listaSalones = new int[10];
}

Edificio::Edificio(int idP, int cantLabsP, int cantSalonesP, string nameP, string responsibleP, int listalabsP[], int listaSalonesP[])
{
    id = idP;
    cantLabs = cantLabsP;
    cantSalones = cantSalonesP;
    name = nameP;
    responsible = responsibleP;

    for (int i = 0; i < cantLabs && i < 10; i++)
    {
        listaLabs[i] = listalabsP[i];
    }

    for (int i = 0; i < cantSalones && i < 10; i++)
    {
        listaSalones[i] = listaSalonesP[i];
    }
}

void Edificio::setId(int idP)
{
    id = idP;
}

void Edificio::setName(string nameP)
{
    name = nameP;
}

void Edificio::setResponsible(string responsibleP)
{
    responsible = responsibleP;
}

int Edificio::getId()
{
    return id;
}

string Edificio::getName()
{
    return name;
}

string Edificio::getResponsible()
{
    return responsible;
}

int Edificio::getCantLabs()
{
    return cantLabs;
}

int Edificio::getCantSalones()
{
    return cantSalones;
}

int Edificio::getLabAtIndex(int index)
{
    if (index >= 0 && index < cantLabs)
    {
        return listaLabs[index];
    }
    return -1;
}

int Edificio::getSalonAtIndex(int index)
{
    if (index >= 0 && index < cantSalones)
    {
        return listaSalones[index];
    }
    return -1;
}

bool Edificio::agregarLab(int labID)
{
    if (cantLabs <= 10)
    {
        for (int i = 0; i < cantLabs; i++)
        {
            if (listaLabs[i] == labID)
            {
                return false;
            }
        }

        listaLabs[cantLabs] = labID;
        cantLabs++;
        return true;
    }
    return false;
}

bool Edificio::agregarSalon(int salonID)
{
    if (cantSalones <= 10)
    {
        for (int i = 0; i < cantSalones; i++)
        {
            if (listaSalones[i] == salonID)
            {
                return false;
            }
        }
        listaSalones[cantSalones] = salonID;
        cantSalones++;
        return true;
    }
    return false;
}

void Edificio::muestraLabs()
{
    cout << "Labs: " << endl;
    for (int i = 0; i < cantLabs; i++)
    {
        cout << "Lab " << i + 1 << ": "
             << "ID: " << listaLabs[i] << ", Name: " << name << ", Responsible: " << responsible << ", Computer: " << endl;
    }
}

void Edificio::muestraSalones()
{
    cout << "Salones: " << endl;
    for (int i = 0; i < cantSalones; i++)
    {
        cout << "Salon " << i + 1 << ": "
             << "ID: " << listaSalones[i] << ", Name: " << name << ", Responsible: " << responsible << ", Computer: " << endl;
    }
}

void Edificio::displayComputersInEdificio(Laboratorio arrLaboratorios[], Salon arrSalones[], Computer arrComputers[], int maxLabs, int maxSalones, int maxComputadoras)
{
    cout << "Computadoras en el edificio:" << endl;
    for (int i = 0; i < cantLabs; i++)
    {
        int labIndex = getLabAtIndex(i);
        if (labIndex >= 0 && labIndex < maxLabs)
        {
            arrLaboratorios[labIndex].displayComputerInLaboratorio(arrComputers, maxComputadoras);
        }
    }

    for (int i = 0; i < cantSalones; i++)
    {
        int salonIndex = getSalonAtIndex(i);
        if (salonIndex >= 0 && salonIndex < maxSalones)
        {
            arrSalones[salonIndex].displayComputerInSalon(arrComputers, maxComputadoras);
        }
    }
}

bool Edificio::findLabOrSalonForComputer(int computerId, int &edificioNumber, int &labOrSalonIndex, Laboratorio arrLaboratorios[], Salon arrSalones[], int maxLabs, int maxSalones)
{
    for (int i = 0; i < cantLabs; i++)
    {
        int labIndex = getLabAtIndex(i);
        if (arrLaboratorios[labIndex].getComputer().getId() == computerId)
        {
            edificioNumber = getId();
            labOrSalonIndex = labIndex;
            return true;
        }
    }

    for (int i = 0; i < cantSalones; i++)
    {
        int salonIndex = getSalonAtIndex(i);
        if (arrSalones[salonIndex - maxLabs].getComputer().getId() == computerId)
        {
            edificioNumber = getId();
            labOrSalonIndex = salonIndex;
            return true;
        }
    }

    return false;
}

#endif