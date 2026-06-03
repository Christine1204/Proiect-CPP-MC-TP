#pragma once

//am decis sa fac o interfata pentru manager pentru a putea avea o clasa de manager care sa se ocupe de logica aplicatiei,
//iar main-ul sa se ocupe doar de partea de input/output, astfel incat sa fie mai usor de intretinut si de extins in viitor
//nu e chiar o interfata pentru ca va contine vectorul de joburi,dar mi se pare intuitiv numele

#include "Job.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream> //pt files

class Manager_interface {
    
    std::vector<Job> joburi; //vectorul de joburi pe care managerul il va gestiona
    std::fstream jobs_file; //fisierul in care se vor stoca joburile, pentru a putea fi incarcate la pornirea aplicatiei
    std::fstream aplicatii_file; //fisierul in care se vor stoca aplicatiile
    public:

    //constructor si destructor pentru a gestiona fisierul de joburi
    
    
    Manager_interface(){
        jobs_file.open("joburi.txt", std::ios::in | std::ios::out); //mod citire,scriere
        aplicatii_file.open("aplicatii.txt", std::ios::in | std::ios::out); //mod citire,scriere

        if (!jobs_file.is_open()) {
            std::cerr << "Eroare: nu s-a putut deschide joburi.txt, asigura-te ca fisierul exista\n";
        }
        if (!aplicatii_file.is_open()) {
            std::cerr << "Eroare: nu s-a putut deschide aplicatii.txt, asigura-te ca fisierul exista\n";
        }
    } //aici deschidem fisierul de joburi, si fisierul de aplicatii, pentru a putea incarca joburile si aplicatiile
    //daca nu exista,da eroare
    
    
    ~Manager_interface(){
        if(jobs_file.is_open()){ //check pentru a vedea daca e deschis sau nu
            jobs_file.close(); //inchidem fisierul la final, pentru a salva modificarile
        }
        if(aplicatii_file.is_open()){
            aplicatii_file.close();
        }
    }

    
    void salveaza(); //functie care se va ocupa de salvarea joburilor in fisier, va fi apelata la finalul fiecarei comenzi care modifica joburile, pentru a salva modificarile




    //functiile cu _comanda la urma sunt functii care for vi apelate din main,depinzand pe inputul utilizatorului,
    //se vor ocupa si de sanitizarea input-ului in caz de input gresit sau lipsa

    void vizualizare_joburi_comanda();
    void adaugare_job_comanda();
    void modificare_job_comanda();
    void adauga_skill_comanda();
    void sterge_skill_comanda();
    void sterge_job_comanda();
    void vizualizare_candidati_comanda();
};