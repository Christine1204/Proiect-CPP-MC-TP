//
// Created by Christine on 5/20/2026.
//

#ifndef PROIECT_C_CANDIDAT_H
#define PROIECT_C_CANDIDAT_H

#include <string>
#include <vector>

#include "Aplicatie.h"

class Candidat {
    std::string nume_candidat;
    std::vector<Aplicatie*> aplicatii;
public:
    Candidat(std::string nume_candidat);
    ~Candidat();

    std::string get_nume_candidat();

    // Returns a reference to the candidate's applications for read-only purposes.
    std::vector<Aplicatie*>* get_aplicatii();

    // Returns empty string ("") if the operation was successful, otherwise returns an error message
    std::string adauga_aplicatie(Aplicatie aplicatie);
    std::string retragere_aplicatie(const Aplicatie* aplicatie);

    // Reads from aplicatii.txt and initializes a list of candidates with their respective applications
    static std::vector<Candidat*> initializare_candidati();
};

#endif //PROIECT_C_CANDIDAT_H