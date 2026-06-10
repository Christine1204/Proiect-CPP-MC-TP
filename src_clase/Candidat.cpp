#include "Candidat.h"

#include <cstring>
#include <utility>

Candidat::Candidat(std::string nume_candidat) {
    this->nume_candidat = std::move(nume_candidat);
}

std::string Candidat::get_nume_candidat() {
    return nume_candidat;
}

std::vector<std::shared_ptr<Aplicatie>> Candidat::get_aplicatii() {
    return aplicatii;
}

std::string Candidat::adauga_aplicatie(const std::shared_ptr<Aplicatie>& aplicatie) {
    this->aplicatii.push_back(aplicatie);

    return ""; // TODO: check if candidate has applied to this job already
}

std::string Candidat::retragere_aplicatie(std::string titlu_job) {
    for (auto ap = this->aplicatii.begin(); ap != this->aplicatii.end(); ++ap) {
        if (titlu_job.compare(ap->get()->get_titlu_job()) == 0) {
            this->aplicatii.erase(ap);
            break;
        }
    }

    return "Application not found.";
}