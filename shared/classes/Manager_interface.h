#pragma once

//am decis sa fac o interfata pentru manager pentru a putea avea o clasa de manager care sa se ocupe de logica aplicatiei,
//iar main-ul sa se ocupe doar de partea de input/output, astfel incat sa fie mai usor de intretinut si de extins in viitor
//nu e chiar o interfata pentru ca va contine vectorul de joburi,dar mi se pare intuitiv numele

#include "Job.h"
#include "Aplicatie.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream> //pt files

class Manager_interface {
    
    std::vector<Job> joburi; //vectorul de joburi pe care managerul il va gestiona
    std::vector<std::shared_ptr<Aplicatie>> aplicatii; //vectorul de aplicatii, desigur intrun program real nu  las crea aici, pentru ca ar fi creat de cealalta aplicatie, dar pentru simplitate o sa las aici, si o sa fie creat in main, iar apoi adaugat in vectorul de aplicatii al managerului
    std::fstream jobs_file; //fisierul in care se vor stoca joburile, pentru a putea fi incarcate la pornirea aplicatiei
    std::fstream aplicatii_file; //fisierul in care se vor stoca aplicatiile
    public:

    //constructor si destructor pentru a gestiona fisierul de joburi
    
    
    Manager_interface();
    ~Manager_interface();

    void incarca_joburi(); //functie care se va ocupa de incarcarea joburilor din fisier la !!!!STARTUP!!!!
    void incarca_aplicatii(); //functie care se va ocupa de incarcarea aplicatiilor din fisier SI le va linka cu joburile respective, pentru a avea legatura dintre job si aplicatii
    void salveaza(); //functie care se va ocupa de salvarea joburilor in fisier, va fi apelata la finalul fiecarei comenzi care modifica joburile, pentru a salva modificarile




    //functiile cu _comanda la urma sunt functii care for vi apelate din main,depinzand pe inputul utilizatorului,
    //NU SE VOR OCUPA DE SANITIZAREA INPUTULUI, CI DOAR DE LOGICA APLICATIEI, restul se face in main

    void vizualizare_joburi_comanda();
    void adaugare_job_comanda(std::string titlu_job, std::string companie, std::vector<std::string> skill_uri);
    void modificare_job_comanda(std::string titlu_job, std::string camp, std::string valoare);
    void adauga_skill_comanda(std::string titlu_job, std::string skill_nou);
    void sterge_skill_comanda(std::string titlu_job, std::string skill_de_sters);
    void sterge_job_comanda(std::string titlu_job);
    void vizualizare_candidati_comanda(std::string titlu_job); //toate comenzile si parametrii respectivi
};