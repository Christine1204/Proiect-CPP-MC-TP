#include "Manager_interface.h"

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


