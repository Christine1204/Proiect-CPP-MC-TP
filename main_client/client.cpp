#include <cstring>
#include <iostream>
#include <memory>

#include "../shared/classes/Candidat.h"
#include "FileHandler.h"
#include "Util.h"

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

void vizualizare_aplicatii_proprii(std::vector<std::shared_ptr<Candidat>>& candidati, std::string nume_candidat) {
    auto candidat = find_candidat_by_name(candidati, nume_candidat);
    if(candidat.expired()) {
        std::cout << "Nu a fost gasita nicio aplicatie pentru acest candidat";
        return;
    }

    std::cout << "Lista de aplicatii pentru " << nume_candidat << ":" << std::endl;

    auto aplicatii = candidat.lock()->get_aplicatii(); // Aplicatii nu poate sa fie gol
    for(auto aplicatie : aplicatii) {
        std::cout << "Nume job: " << aplicatie->get_titlu_job() << std::endl << "Mesaj aplicare: " << aplicatie->get_mesaj_aplicare() << std::endl << std::endl; 
    }
}

void aplicare(std::vector<std::shared_ptr<Candidat>>& candidati, std::vector<std::shared_ptr<Job>>& joburi, std::string titlu_job, std::string nume_candidat, std::string mesaj_aplicare) {
    auto aplicatie = std::make_shared<Aplicatie>(Aplicatie(titlu_job, mesaj_aplicare));

    auto jobCoresp = find_job_by_name(joburi, titlu_job);
    if(jobCoresp.expired()) {
        std::cerr << "Nu exista acest job!";
        return;
    }
    jobCoresp.lock()->link_aplicatie(aplicatie);
    
    auto candidatCoresp = find_candidat_by_name(candidati, nume_candidat);
    // If there's no candidate object found, make a new one
    if(!candidatCoresp.lock()) {
        auto newCandidat = std::make_shared<Candidat>(Candidat(nume_candidat));
        newCandidat.get()->adauga_aplicatie(aplicatie);
        candidati.push_back(newCandidat);
    } else {
        std::string err_msg = candidatCoresp.lock().get()->adauga_aplicatie(aplicatie);
        if(err_msg.compare("") != 0) {
            std::cout << err_msg;
            return;
        }
    }
    std::cout << "Aplicatie adaugata cu succes!";
}

void retragere_aplicatie(std::vector<std::shared_ptr<Candidat>>& candidati, std::vector<std::shared_ptr<Job>>& joburi, std::string titlu_job, std::string nume_candidat) {
    auto candidat = find_candidat_by_name(candidati, nume_candidat);
    if(candidat.expired()) {
        std::cerr << "Acest candidat nu a fost gasit!";
        return;
    }
    auto jobAplicatie = find_job_by_name(joburi, titlu_job).lock()->get_aplicatii();
    auto aplicatii = candidat.lock().get()->get_aplicatii();

    
    auto mesajEroare = candidat.lock()->retragere_aplicatie(titlu_job);
    bool ok = mesajEroare.compare("") == 0;


    if(!ok) {
        std::cerr << mesajEroare;
    } else { // Stergem si referinta din joburi, care acum va fi expirata
        for(auto ap = jobAplicatie.begin(); ap != jobAplicatie.end(); ap++) {
            if((*ap).expired()) {
                jobAplicatie.erase(ap);
                break;
            }
        } 
        std::cout << "Aplicatie retrasa cu succes!";
    }
}

void parse_cli(int argc, char* argv[], std::vector<std::shared_ptr<Candidat>>& candidati, std::vector<std::shared_ptr<Job>>& joburi) {
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
                return vizualizare_aplicatii_proprii(candidati, argv[2]);
            }
            break;
        case 4:
            if (strcmp(argv[1], "retragere_aplicatie") == 0) {
                return retragere_aplicatie(candidati, joburi, argv[2], argv[3]);
            }
            break;
        case 5:
            if (strcmp(argv[1], "aplicare") == 0) {
                return aplicare(candidati, joburi, argv[2], argv[3], argv[4]);
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

    save_applications_to_file(candidati, joburi);
}
