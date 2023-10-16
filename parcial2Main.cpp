#include <iostream>
#include <string>
#include <fstream>
#include "Edificio.h"
#include "Laboratorio.h"
#include "Salon.h"
#include "Computer.h"
using namespace std;

int maxLabs = 10;
int maxSalones = 12;
int maxComputadoras = 22;
int maxEdificios = 4;

int main()
{
    Edificio arrEdificio[maxEdificios];
    Laboratorio arrLaboratorios[maxLabs];
    Salon arrSalones[maxSalones];
    Computer arrComputers[maxComputadoras];

    ifstream compFile("Computadora.txt");
    int compId;
    string compBrand, compOS;
    int compRam;
    int compIndex = 0;

    while (compFile >> compId >> compBrand >> compOS >> compRam)
    {
        arrComputers[compIndex] = Computer(compId, compBrand, compOS, compRam);
        compIndex++;

        if (compIndex >= maxComputadoras)
        {
            cout << "Too many Computers" << endl;
            break;
        }
    }
    compFile.close();

    // Loads data from laboratorio.txt
    ifstream labFile("laboratorios.txt");
    int labId, labCap, labCompId;
    string labName;
    int labIndex = 0;

    while (labFile >> labId >> labName >> labCap >> labCompId)
    {
        int compIndex = 0;
        for (int i = 0; i < maxComputadoras; i++)
        {
            if (arrComputers[i].getId() == labCompId)
            {
                compIndex = i;
                break;
            }
        }
        if (compIndex != 0)
        {
            arrLaboratorios[labIndex] = Laboratorio(labId, labName, labCap, arrComputers[compIndex]);
        }
        else
        {
            cout << "Could not find corresponding Computer" << endl;
        }

        if (labIndex >= maxLabs)
        {
            cout << "Too many Labs" << endl;
            break;
        }

        labIndex++;
    }
    labFile.close();

    // Loads data from salones.txt
    ifstream salonFile("salones.txt");
    int salonId, salonCap, salonCompId;
    string salonName;
    int salonIndex = 0;

    while (salonFile >> salonId >> salonName >> salonCap >> salonCompId)
    {
        int compIndex = 0;
        for (int i = 0; i < maxComputadoras; i++)
        {
            if (arrComputers[i].getId() == salonCompId)
            {
                compIndex = i;
                break;
            }
        }
        if (compIndex != 0)
        {
            arrSalones[salonIndex] = Salon(salonId, salonName, salonCap, arrComputers[compIndex]);
            salonIndex++;
        }
        else
        {
            cout << "Could not find corresponding Computer" << endl;
        }

        if (salonIndex >= maxSalones)
        {
            cout << "Too many Salones" << endl;
            break;
        }
    }
    salonFile.close();

    // Loads data from edificios.txt
    ifstream edificioFile("edificios.txt");
    int edificioNumber, numLabs, numSalones;
    string edificioName, responsible;
    int labIds[maxLabs];
    int salonIds[maxSalones];
    int edificioIndex = 0;

    while (edificioFile >> edificioNumber >> edificioName >> numLabs >> numSalones)
    {
        // Reading the list of lab ID's in the txt file
        for (int i = 0; i < numLabs; i++)
        {
            edificioFile >> labIds[i];
        }

        // Reading the list of salon ID's in the txt file
        for (int i = 0; i < numSalones; i++)
        {
            edificioFile >> salonIds[i];
        }

        edificioFile >> responsible;

        arrEdificio[edificioIndex] = Edificio(edificioNumber, numLabs, numSalones, edificioName, responsible, labIds, salonIds);
        edificioIndex++;

        if (edificioIndex >= maxEdificios)
        {
            cout << "Too many Edificios" << endl;
            break;
        }
    }

    char option;

    do
    {
        cout << "\n--- Menú ---" << endl;
        cout << "a. Consulta de todos los laboratorios." << endl;
        cout << "b. Consulta de todos los salones." << endl;
        cout << "c. Consulta de todos los edificios." << endl;
        cout << "d. Consulta de todas las computadoras disponibles." << endl;
        cout << "e. Consulta de computadoras por edificio." << endl;
        cout << "f. Consulta por clave de computadora." << endl;
        cout << "g. Consulta de lista de labs y salones por marca de computadora." << endl;
        cout << "h. Terminar." << endl;
        cout << "Seleccione una opción: ";
        cin >> option;

        if (option == 'a')
        {
            for (int i = 0; i < maxLabs; i++)
            {
                cout << "Laboratorio " << i + 1 << ": " << arrLaboratorios[i].getId() << " " << arrLaboratorios[i].getId() << " " << arrLaboratorios[i].getName() << " " << arrLaboratorios[i].getCapacidad() << " " << arrLaboratorios[i].getComputer().getBrand() << endl;
            }
        }
        else if (option == 'b')
        {
            for (int i = 0; i < maxSalones; i++)
            {
                cout << "Salon " << i + 1 << ": " << arrSalones[i].getId() << " " << arrSalones[i].getName() << " " << arrSalones[i].getCapacidad() << " " << arrSalones[i].getComputer().getBrand() << endl;
            }
        }
        else if (option == 'c')
        {
            for (int i = 0; i < maxEdificios; i++)
            {
                cout << "Edificio " << i + 1 << ": " << arrEdificio[i].getId() << " " << arrEdificio[i].getName() << " " << arrEdificio[i].getResponsible() << endl;
                cout << "Laboratorios en el edificio:" << endl;
                for (int x = 0; x < arrEdificio[i].getCantLabs(); x++)
                {
                    int labIndex = arrEdificio[i].getLabAtIndex(x);
                    cout << "Laboratorio " << x + 1 << ": " << arrLaboratorios[labIndex].getId() << " " << arrLaboratorios[labIndex].getName() << " " << arrLaboratorios[labIndex].getCapacidad() << " " << arrLaboratorios[labIndex].getComputer().getBrand() << endl;
                }

                cout << "Salones en el edificio:" << endl;
                for (int x = 0; x < arrEdificio[i].getCantSalones(); x++)
                {
                    int salonIndex = arrEdificio[i].getSalonAtIndex(x);
                    cout << "Salon " << x + 1 << ": " << arrSalones[salonIndex].getId() << " " << arrSalones[salonIndex].getName() << " " << arrSalones[salonIndex].getCapacidad() << " " << arrSalones[salonIndex].getComputer().getBrand() << endl;
                }
            }
        }
        else if (option == 'd')
        {
            for (int i = 0; i < maxComputadoras; i++)
            {
                cout << "Computadora " << i + 1 << ": " << arrComputers[i].getId() << " " << arrComputers[i].getBrand() << " " << arrComputers[i].getOS() << " " << arrComputers[i].getRam() << "GB" << endl;

                for (int x = 0; x < maxLabs; x++)
                {
                    if (arrLaboratorios[x].getComputer().getId() == arrComputers[i].getId())
                    {
                        cout << "Ubicación: Laboratorio " << arrLaboratorios[x].getId() << ": " << arrLaboratorios[x].getName() << endl;
                    }
                }
                for (int x = 0; x < maxSalones; x++)
                {
                    if (arrSalones[x].getComputer().getId() == arrComputers[i].getId())
                    {
                        cout << "Ubicación: Salon " << arrSalones[x].getId() << ": " << arrSalones[x].getName() << endl;
                    }
                }
            }
        }
        else if (option == 'e')
        {
            int edificioNumber;
            cout << "Ingresa el numero del edificio: ";
            cin >> edificioNumber;

            bool foundEdificio = false;
            for (int i = 0; i < maxEdificios; i++)
            {
                if (arrEdificio[i].getId() == edificioNumber)
                {
                    foundEdificio = true;
                    arrEdificio[i].displayComputersInEdificio(arrLaboratorios, arrSalones, arrComputers, maxLabs, maxSalones, maxComputadoras);
                    break;
                }
            }

            if (!foundEdificio)
            {
                cout << "Edificio no encontrado." << endl;
            }
            break;
        }
        else if (option == 'f')
        {
            int computerId;
            cout << "Ingrese la clave de la computadora: ";
            cin >> computerId;

            bool foundComputer = false;
            for (int i = 0; i < maxComputadoras; i++)
            {
                if (arrComputers[i].getId() == computerId)
                {
                    foundComputer = true;
                    int edificioNumber, labOrSalonIndex;

                    // Find edificio and lab/salon index
                    if (arrEdificio[i].findLabOrSalonForComputer(computerId, edificioNumber, labOrSalonIndex, arrLaboratorios, arrSalones, maxLabs, maxSalones))
                    {
                        // Display details
                        cout << "Numero de edificio: " << edificioNumber << endl;
                        cout << "En el ";

                        if (labOrSalonIndex < maxLabs)
                        {
                            cout << "laboratorio " << arrLaboratorios[labOrSalonIndex].getName() << ": ";
                            arrLaboratorios[labOrSalonIndex].getComputer().displayDetails();
                        }
                        else
                        {
                            cout << "Salon " << arrSalones[labOrSalonIndex - maxLabs].getName() << ": ";
                            arrSalones[labOrSalonIndex - maxLabs].getComputer().displayDetails();
                        }
                    }
                    break;
                }
            }

            if (!foundComputer)
            {
                cout << "Computadora no encontrada." << endl;
            }
            break;
        }
        else if (option == 'g')
        {
            string brandToSearch;
            cout << "Ingrese la marca de la computadora: ";
            cin >> brandToSearch;

            bool foundBrand = false;

            for (int i = 0; i < maxEdificios; i++)
            {
                int totalLabsWithBrand = 0;
                int totalSalonesWithBrand = 0;

                for (int j = 0; j < arrEdificio[i].getCantLabs(); j++)
                {
                    int labIndex = arrEdificio[i].getLabAtIndex(j);
                    if (arrLaboratorios[labIndex].getComputer().getBrand() == brandToSearch)
                    {
                        totalLabsWithBrand++;
                    }
                }

                for (int j = 0; j < arrEdificio[i].getCantSalones(); j++)
                {
                    int salonIndex = arrEdificio[i].getSalonAtIndex(j);
                    if (arrSalones[salonIndex - maxLabs].getComputer().getBrand() == brandToSearch)
                    {
                        totalSalonesWithBrand++;
                    }
                }

                if (totalLabsWithBrand > 0 || totalSalonesWithBrand > 0)
                {
                    foundBrand = true;

                    cout << "Edificio " << arrEdificio[i].getName() << ": " << endl;
                    cout << "Labs con la marca " << brandToSearch << ": " << totalLabsWithBrand << endl;
                    cout << "Salones con la marca " << brandToSearch << ": " << totalSalonesWithBrand << endl;
                }
            }

            if (!foundBrand)
            {
                cout << "No se encontraron labs o salones con la marca especificada." << endl;
            }

            break;
        }
        else if (option == 'h')
        {
            cout << "Programa Terminado" << endl;
        }
        else
        {
            cout << "Opcion invalida, trata otra vez" << endl;
        }

    } while (option != 'h');
    return 0;
}