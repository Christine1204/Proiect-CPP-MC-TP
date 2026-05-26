//
// Created by tudor on 5/26/2026.
//

#include "Util.h"

std::weak_ptr<Candidat> find_candidat_by_name(const std::vector<std::shared_ptr<Candidat>> &candidati,
    const std::string &name) {
    for (const auto& candidat : candidati) {
        if (strcmp(name.c_str(), candidat.get()->get_nume_candidat().c_str()) == 0) {
            return candidat;
        }
    }

    return {};
}

std::weak_ptr<Job> find_job_by_name(const std::vector<std::shared_ptr<Job>> &joburi, const std::string &name) {
    for (const auto& job : joburi) {
        if (strcmp(name.c_str(), job.get()->get_titlu_job().c_str()) == 0) {
            return job;
        }
    }

    return {};
}

void todo() {
    std::cerr << "Functionalitate neimplementata";
    exit(1);
}

void eroare(const char *str) {
    std::cerr << str;
    exit(1);
}
