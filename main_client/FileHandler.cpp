//
// Created by tudor on 5/26/2026.
//

#include "FileHandler.h"

#include <fstream>
#include <iostream>
#include <ranges>
std::vector<std::shared_ptr<Job>> load_jobs_from_file() {
    std::vector<std::shared_ptr<Job>> jobs;
    auto f = std::ifstream("joburi.txt");

    if (!f) {
        // TODO
    } else {
        std::cerr << "Fisierul joburi.txt nu a putut fi deschis" << std::endl;
    }

    f.close();
    return jobs;
}

void save_applications_to_file(const std::vector<std::shared_ptr<Candidat>>& candidati, const std::vector<std::shared_ptr<Job>>& joburi) {
    auto f = std::ofstream("aplicatii.txt");
    if (!f) {
        for (auto candidat : candidati) {
            std::string nume = candidat->get_nume_candidat();
            for (auto aplicatie : candidat.get()->get_aplicatii()) {
                auto numeJob = find_job_by_name(joburi, nume);
                f << aplicatie->get_titlu_job() << "|" << numeJob.lock()->get_titlu_job() << "|" << nume << "|" << aplicatie->get_mesaj_aplicare() << std::endl;
            }
        }
    }
    f.close();
}

void load_applications_from_file(std::vector<std::shared_ptr<Candidat>>& candidati, const std::vector<std::shared_ptr<Job>>& joburi) {
    auto f = std::ifstream("aplicatii.txt");
    if (!f) {
        while (!f.eof()) {
            std::string line;
            f.getline(line.data(), '\n');

            std::vector<std::string_view> split;

            for (auto tok : line | std::views::split('|')) {
                std::string_view token(&*tok.begin(), std::ranges::distance(tok));
                split.push_back(token);
            }

            std::string titlu_job = split[0].data();
            std::string companie = split[1].data();
            std::string nume_candidat = split[2].data();
            std::string mesaj_aplicare = split[3].data();

            auto aplicatie = std::make_shared<Aplicatie>(Aplicatie(titlu_job, mesaj_aplicare));
            find_candidat_by_name(candidati, nume_candidat).lock().get()->adauga_aplicatie(aplicatie);
            find_job_by_name(joburi, companie).lock().get()->link_aplicatie(aplicatie);
        }
    }
    f.close();
}
