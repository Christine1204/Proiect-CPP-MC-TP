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


    Manager_interface manager; //creez un obiect de tip manager, se va face loadingul la fisiere tot aici in constructor
    
    //testare manager
    manager.vizualizare_joburi_comanda();
    //super,mere pana aici
    
    //verificat functia de adaugare
    //manager.adaugare_job_comanda("Software Engineer","Google",{"C++","C++","Mai mult C++"});
    //manager.vizualizare_joburi_comanda();


    //verificat functia de stergere
    //manager.adaugare_job_comanda("Data Scientist","Facebook",{"Python","R","SQL"});
    //manager.vizualizare_joburi_comanda();
    // manager.sterge_job_comanda("Data Scientist");
    // manager.vizualizare_joburi_comanda();


    //verificat functia de modificare
    // manager.adaugare_job_comanda("Software Engineer","Google",{"C++","C++","Mai mult C++"});
    // manager.modificare_job_comanda("Software Engineer", "companie", "Meta");
    // manager.modificare_job_comanda("Software Engineer", "titlu_job", "Senior Software Engineer");
    // manager.modificare_job_comanda("Software Engineer", "camp_inexistent", "valoare"); //testare camp invalid 
    // manager.modificare_job_comanda("Job Inexistent", "companie", "Meta"); //testare job inexistent
    // manager.modificare_job_comanda("Senior Software Engineer", "skill-uri", "C++,C++,mai mult C++ pentru ca e mai bine"); //testare modificare skill-uri
    // manager.vizualizare_joburi_comanda();


    //testare functii de adaugare si stergere skill-uri
    // manager.adaugare_job_comanda("Schema piramidala","Big Data",{"Escrocherie","Frauda","Incredere oarba"});
    // manager.sterge_skill_comanda("Schema piramidala","Incredere oarba");
    // manager.sterge_skill_comanda("Schema piramidala","Skill Inexistent"); //testare stergere skill inexistent
    // manager.adauga_skill_comanda("Schema piramidala","Manipulare psihologica");

    //verificat functia de vizualizare candidati

    // manager.vizualizare_candidati_comanda("Senior Software Engineer");
    // manager.vizualizare_candidati_comanda("Casier");
    // manager.vizualizare_candidati_comanda("Job inexistent");
    
    return 0;
} //pentru a seta un milion de breakpoint-uri,folositi shift alt I dupa ce selectati mai multe linii