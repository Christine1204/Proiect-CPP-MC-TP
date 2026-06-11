//
// Created by tudor on 5/26/2026.
//

#include "FileHandler.h"
#include "../src_clase/Utils.h"

#include <fstream>
#include <iostream>

std::vector<std::shared_ptr<Job>> load_jobs_from_file() {
    std::vector<std::shared_ptr<Job>> jobs;
    std::ifstream f("joburi.txt");

    if (f) {
        while(!f.eof()) {
            std::string line;
            f.getline(line.data(), 255);

            auto sp = split(line, '|');

            std::string titlu_job = sp[0];
            std::string companie = sp[1];
            std::vector<std::string> skilluri = split(sp[2], ',');

            auto job = std::make_shared<Job>(Job(titlu_job, companie, skilluri));
            jobs.push_back(job);
        }
    } else {
        std::cerr << "Fisierul joburi.txt nu a putut fi deschis" << std::endl;
    }

    f.close();
    return jobs;
}

void save_applications_to_file(const std::vector<std::shared_ptr<Candidat>>& candidati, const std::vector<std::shared_ptr<Job>>& joburi) {
    auto f = std::ofstream("aplicatii.txt");
    if (f) {
        bool first = true; // Inseram endl inainte de toate liniile (mai putin prima) ca sa nu avem linie goala la final
        for (auto candidat : candidati) {
            std::string nume = candidat->get_nume_candidat();
            for (auto aplicatie : candidat.get()->get_aplicatii()) {
                if(first) {
                    first = false;
                } else {
                    f << std::endl;
                }
                auto numeJob = aplicatie.get()->get_titlu_job();
                auto numeCompanie = find_job_by_name(joburi, numeJob).lock().get()->get_companie();
                f << numeJob << " | " << numeCompanie << " | " << nume << " | " << aplicatie.get()->get_mesaj_aplicare();
            }
        }
    }
    f.close();
}

void load_applications_from_file(std::vector<std::shared_ptr<Candidat>>& candidati, const std::vector<std::shared_ptr<Job>>& joburi) {
    auto f = std::ifstream("aplicatii.txt");
    if (f) {
        while (!f.eof()) {
            std::string line;
            f.getline(line.data(), 255);

            auto sp = split(line, '|');

            std::string titlu_job = sp[0];
            std::string companie = sp[1];
            std::string nume_candidat = sp[2];
            std::string mesaj_aplicare = sp[3];

            auto aplicatie = std::make_shared<Aplicatie>(Aplicatie(titlu_job, mesaj_aplicare));

            auto candidatCoresp = find_candidat_by_name(candidati, nume_candidat);

            // If there's no candidate object found, make a new one
            if(!candidatCoresp.lock()) {
                auto newCandidat = std::make_shared<Candidat>(Candidat(nume_candidat));
                newCandidat.get()->adauga_aplicatie(aplicatie);
                candidati.push_back(newCandidat);
            } else {
                candidatCoresp.lock().get()->adauga_aplicatie(aplicatie);
            }

            find_job_by_name(joburi, titlu_job).lock().get()->link_aplicatie(aplicatie);
        }
    } else {
        std::cerr << "Fisierul aplicatii.txt nu a putut fi deschis." << std::endl;
    }
    f.close();
}
