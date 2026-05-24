#include "Candidat.h"

#include <utility>

Candidat::Candidat(std::string nume_candidat) {
    this->nume_candidat = std::move(nume_candidat);
}

Candidat::~Candidat() {
    for (const auto ap : this->aplicatii) {
        delete ap;
    }
}

std::string Candidat::get_nume_candidat() {
    return nume_candidat;
}

std::vector<Aplicatie*>* Candidat::get_aplicatii() {
    return &aplicatii;
}

std::string Candidat::adauga_aplicatie(Aplicatie aplicatie) {
    this->aplicatii.push_back(&aplicatie);

    return ""; // TODO: check if candidate has applied to this job already
}

std::string Candidat::retragere_aplicatie(const Aplicatie* aplicatie) {
    for (auto ap = this->aplicatii.begin(); ap != this->aplicatii.end(); ++ap) {
        if (*ap == aplicatie) {
           this->aplicatii.erase(ap);
            return "";
        }
    }

    return "Application not found.";
}


std::vector<Candidat*> Candidat::initializare_candidati() {
    return {}; // TODO
}