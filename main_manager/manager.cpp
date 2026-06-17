#include <iostream>
#include <string>
using namespace std;


// classes include
#include "Job.h"
#include "Candidat.h"
#include "Aplicatie.h" //pentru orice eventualitate
#include "Manager_interface.h" //clasa de manager, care va gestiona joburile
#include "Utils.h"
/*  comanda test 
 ./main_manager/build/manager "arg1" "arg2" "this is arg 3"
*/

//functie de printat help

void print_help() {
    cout << "\n=== Modul Admin - Ajutor ===\n";
    cout << "Utilizare: ./manager <comanda> [argumente]\n\n";
    cout << "Comenzi disponibile:\n";
    cout << "  vizualizare_joburi\n";
    cout << "  adaugare_job \"<titlu>\" \"<companie>\" \"<skill1>, <skill2>, <skill3>\"\n";
    cout << "  modificare_job \"<titlu>\" \"<camp>\" \"<valoare>\"\n";
    cout << "  adauga_skill \"<titlu>\" \"<skill>\"\n";
    cout << "  sterge_skill \"<titlu>\" \"<skill>\"\n";
    cout << "  stergere_job \"<titlu>\"\n";
    cout << "  vizualizare_candidati \"<titlu>\"\n\n";
    cout << "Folositi ghilimele (\"\") in jurul argumentelor formate din mai multe cuvinte.\n";
    cout << "============================\n\n";
}


int main(int argc, char* argv[]) {
    
    // cout << "You have entered " << argc
    //      << " arguments:" << endl;

    // int i = 0;
    // while (i < argc) {
    //     cout << "Argument " << i + 1
    //          << ": " << argv[i]
    //          << endl;
    //     i++;
    // }
    //aceasta parte e testare a argumentelor de pe CLI




    Manager_interface manager; //creez un obiect de tip manager, se va face loadingul la fisiere tot aici in constructor
    
    //testare manager
    //manager.vizualizare_joburi_comanda();
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
    
    //i want to start writing the parsing for the argc and argv input to make all these commands work in the console


// -- RUTELE CLI --


    //argv 0 = locatia programului si numele
    //argv 1 = comanda in sine = cmd1
    //argv 2 = argument 1
    //argv 3 = argument 2 
    //...

    if (argc == 1){
        print_help();
        return 0;
    }
    string cmd1 = argv[1]; // comanda in sine

    if (cmd1 == "vizualizare_joburi") {
        manager.vizualizare_joburi_comanda();
    } 
    else if (cmd1 == "adaugare_job") {
        if (argc >= 5) {
            string titlu = argv[2];
            string companie = argv[3];
            string skills_str = argv[4];
            manager.adaugare_job_comanda(titlu, companie, split(skills_str, ','));
        } else {
            cout << "Eroare: Argumente insuficiente pentru 'adaugare_job'.\n"; 
            print_help();
        }
    }
    else if (cmd1 == "modificare_job") {
        if (argc >= 5) {
            manager.modificare_job_comanda(argv[2], argv[3], argv[4]);
        } else { 
            cout << "Eroare: Argumente insuficiente pentru 'modificare_job'.\n"; 
            print_help(); 
        }
    }
    else if (cmd1 == "adauga_skill") {
        if (argc >= 4) {
            manager.adauga_skill_comanda(argv[2], argv[3]);
        } else { 
            cout << "Eroare: Argumente insuficiente pentru 'adauga_skill'.\n"; 
            print_help(); 
        }
    }
    else if (cmd1 == "sterge_skill") {
        if (argc >= 4) {
            manager.sterge_skill_comanda(argv[2], argv[3]);
        } else { 
            cout << "Eroare: Argumente insuficiente pentru 'sterge_skill'.\n"; 
            print_help(); 
        }
    }
    else if (cmd1 == "stergere_job") {
        if (argc >= 3) {
            manager.sterge_job_comanda(argv[2]);
        } else { 
            cout << "Eroare: Argumente insuficiente pentru 'stergere_job'.\n"; 
            print_help(); 
        }
    }
    else if (cmd1 == "vizualizare_candidati") {
        if (argc >= 3) {
            manager.vizualizare_candidati_comanda(argv[2]);
        } else { 
            cout << "Eroare: Argumente insuficiente pentru 'vizualizare_candidati'.\n"; 
            print_help(); 
        }
    }
    else if (cmd1 == "help" || cmd1 == "-h" || cmd1 == "--help") {
        print_help();
    }
    else {
        cout << "Eroare: Comanda necunoscuta.\n";
        print_help();
    }
    


    return 0;
} //pentru a seta un milion de breakpoint-uri,folositi shift alt I dupa ce selectati mai multe linii