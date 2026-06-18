#include "Aplicatie.h"

Aplicatie::Aplicatie(std::string titlu_job, std::string mesaj_aplicare) : titlu_job(titlu_job), mesaj_aplicare(mesaj_aplicare) {}

std::string Aplicatie::get_mesaj_aplicare() {
    return mesaj_aplicare;
}

std::string Aplicatie::get_titlu_job() {
    return titlu_job;
}
