#include "Manager_interface.h"
#include "Utils.h" //un header cu functii auxiliare folositoare, la scrierea acestui comentariu e doar functia split
#include <vector>
#include <string>
#include <iostream>



Manager_interface::Manager_interface(){
        jobs_file.open("joburi.txt", std::ios::in | std::ios::out); //mod citire,scriere
        aplicatii_file.open("aplicatii.txt", std::ios::in | std::ios::out); //mod citire,scriere

        if (!jobs_file.is_open()) {
            std::cerr << "Eroare: nu s-a putut deschide joburi.txt, asigura-te ca fisierul exista\n";
        }
        if (!aplicatii_file.is_open()) {
            std::cerr << "Eroare: nu s-a putut deschide aplicatii.txt, asigura-te ca fisierul exista\n";
        }
        return; //daca nu s-au putut deschide fisierele, iesim din constructor, lasand vectorul de joburi gol, si afisand un mesaj de eroare

        incarca_joburi(); //incarc joburile din fisier la pornirea aplicatiei, daca exista, daca nu, atunci ramane vectorul de joburi gol
    } 
    //aici deschidem fisierul de joburi, si fisierul de aplicatii, pentru a putea incarca joburile si aplicatiile
    //daca nu exista,da eroare




Manager_interface::~Manager_interface(){
        if(jobs_file.is_open()){ //check pentru a vedea daca e deschis sau nu
            jobs_file.close(); //inchidem fisierul la final, pentru a salva modificarile
        }
        if(aplicatii_file.is_open()){
            aplicatii_file.close();
        }
}


void Manager_interface::salveaza(){
        if (!jobs_file.is_open()){
            std::cerr << "Eroare: nu s-a putut deschide joburi.txt pentru salvare, asigura-te ca fisierul exista\n";
            return; //daca nu se poate deschide fisierul pentru salvare, iesim din functie, afisand un mesaj de eroare
        }
        
            jobs_file.close(); //inchidem fisierul
            jobs_file.open("joburi.txt", std::ios::out | std::ios::trunc); //redeschidem fisierul in mod scriere, si stergem continutul vechi
            if (!jobs_file.is_open()){
                std::cerr << "Eroare: nu s-a putut deschide joburi.txt pentru salvare, asigura-te ca fisierul exista,bucla interioara\n";
                return;

                for (const auto& job : joburi){
                    jobs_file << job.get_titlu_job() << " | " << job.get_companie() << " | "; //partea cu nume si companie
                    const auto& skill_uri = job.get_skill_uri();
                    for (int i = 0; i < skill_uri.size(); i++) { //partea cu skill-uri, cu virgula intre ele
                        jobs_file << skill_uri[i];
                        if (i < skill_uri.size() - 1) {
                            jobs_file << ", ";
                        }
                    }
                    jobs_file << "\n";
                } // titlu job | companie | skill1, skill2, skill3, ...
            }
}


void Manager_interface::vizualizare_joburi_comanda(){
    for (const auto& job : joburi){
        std::cout << job; //folosim overload-ul de operator de printare pentru a afisa joburile intr-un format frumos
    }
}

 void Manager_interface::incarca_joburi(){
    if (!jobs_file.is_open()){
        std::cerr << "Eroare: nu s-a putut deschide joburi.txt pentru incarcare in incarca_joburi(), asigura-te ca fisierul exista\n";
        return; //daca nu se poate deschide fisierul pentru incarcare, iesim din functie, afisand un mesaj de eroare
    }
    std::string linie;
    while (std::getline(jobs_file, linie)){
            if (linie.empty()) continue; //sarim peste liniile goale
        //aici trebuie sa parsez liniile
        //formatul e titlu job | companie | skill1, skill2, skill3, ...
        //voi folosi o functie numita split din headerul Utils (asa se numeste dupa conventie) pentru a sparge linia in parti, folosind ca delimitator " | " pentru a obtine titlu job, companie, si skill-uri, 
        //iar apoi voi folosi din nou split pentru a sparge partea de skill-uri folosind ca delimitator ", "
        std::vector<std::string> parti = split(linie, '|'); //prima impartire dupa '|'
        if (parti.size() != 3){
            std::cerr << "Eroare: format incorect in joburi.txt, linia: " << linie << "\n";
            continue; //daca linia nu are exact 3 parti dupa impartire, inseamna ca formatul e incorect, deci o sarim, afisand un mesaj de eroare
        }
        std::string titlu_job = parti[0];
        std::string companie = parti[1];
        std::vector<std::string> skill_uri = split(parti[2], ','); //a doua impartire dupa ',' pentru a obtine skill-urile individuale        
        
        //acum am toate informatiile necesare pentru a crea un obiect de tip Job, pe care il adaug in vectorul de joburi al managerului
        Job job(titlu_job, companie, skill_uri);
        joburi.push_back(job);
    
    
    }
}