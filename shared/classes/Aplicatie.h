//
// Created by Christine on 5/20/2026.
//

#ifndef PROIECT_C_APLICATIE_H
#define PROIECT_C_APLICATIE_H
#include <string>

class Aplicatie {
    std::string titlu_job;
    std::string mesaj_aplicare;
public:
    Aplicatie(std::string titlu_job, std::string mesaj_aplicare);

    std::string get_titlu_job();
    std::string get_mesaj_aplicare();
};

#endif //PROIECT_C_APLICATIE_H