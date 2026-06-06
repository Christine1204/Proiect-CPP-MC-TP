#include <iostream>
#include <string>
using namespace std;


// classes include
#include "Job.h"
#include "Candidat.h"
#include "Aplicatie.h" //pentru orice eventualitate
#include "Manager_interface.h" //clasa de manager, care va gestiona joburile

/*  comanda test 
 ./main_manager/build/manager arg1 arg2 "this is arg 3"
*/


int main(int argc, char* argv[]) {
    /*
    cout << "You have entered " << argc
         << " arguments:" << endl;

    int i = 0;
    while (i < argc) {
        cout << "Argument " << i + 1
             << ": " << argv[i]
             << endl;
        i++;
    }
        */ //aceasta parte e testare a argumentelor de pe CLI


    Manager_interface manager; //creez un obiect de tip manager
    

    manager.incarca_joburi(); //incarc joburile din fisier la pornirea aplicatiei, daca exista, daca nu, atunci ramane vectorul de joburi gol
    manager.vizualizare_joburi_comanda();



    return 0;
}