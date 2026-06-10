#include <cstring>
#include <iostream>
#include <memory>

#include "../src_clase/Candidat.h"
#include "FileHandler.h"

void vizualizare_joburi(std::vector<std::shared_ptr<Job>> joburi, std::string filtru) {
    // Pt a afisa eroare daca nu se gaseste niciun job
    bool gasit = false;

    for(const auto& job : joburi) {
        // Gasim jobul care are skill-ul cerut, daca avem filtru
        if(filtru.compare("") != 0) {
            bool ok = false;
            for(const auto& skill : job->get_skill_uri()) {
                if(skill.compare(filtru) == 0) {
                    ok = true;
                    break;
                }
            }
            if(!ok) continue;
        }

        gasit = true;

        // Afisare job
        std::cout << job->get_titlu_job() << std::endl
            << "Compania: " << job->get_companie() << std::endl
            << "Skill-uri: ";
        for(int i = 0; i < job->get_skill_uri().size(); i++) {
            std::cout << job->get_skill_uri()[i];
            if(i < job->get_skill_uri().size() - 1) std::cout << ", ";
        }
        std::cout << std::endl << std::endl;
    }

    if(!gasit) {
        std::cout << "Nu exista joburi corespunatoare acestui criteriu.";
    }
}

void vizualizare_joburi(std::vector<std::shared_ptr<Job>> joburi) {
    vizualizare_joburi(joburi, "");
}

void parse_cli(int argc, char* argv[], std::vector<std::shared_ptr<Candidat>> candidati, std::vector<std::shared_ptr<Job>> joburi) {
    switch (argc) {
        case 2:
            if (strcmp(argv[1], "vizualizare_joburi") == 0) {
                return vizualizare_joburi(joburi);
            }
            break;
        case 3:
            if (strcmp(argv[1], "vizualizare_joburi_filtrat") == 0) {
                return vizualizare_joburi(joburi, argv[2]);
            } if (strcmp(argv[1], "vizualizare_aplicatii_proprii") == 0) {
                return todo();
            }
            break;
        case 4:
            if (strcmp(argv[1], "retragere_aplicatie") == 0) {
                return todo();
            }
            break;
        case 5:
            if (strcmp(argv[1], "aplicare") == 0) {
                return todo();
            }
            break;
        default:
            break;
    }
    return eroare("Argumente invalide");
}

int main(int argc, char* argv[]) {
    auto joburi = load_jobs_from_file();
    std::vector<std::shared_ptr<Candidat>> candidati;
    load_applications_from_file(candidati, joburi);

    parse_cli(argc, argv, candidati, joburi);
}
