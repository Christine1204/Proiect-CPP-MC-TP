#include <cstring>
#include <iostream>
#include <memory>

#include "../src_clase/Candidat.h"
#include "FileHandler.h"

void vizualiare_joburi(std::vector<std::shared_ptr<Job>> joburi);
void vizualiare_joburi(std::vector<std::shared_ptr<Job>> joburi, std::string filtru);

void parse_cli(int argc, char* argv[]) {
    switch (argc) {
        case 2:
            if (strcmp(argv[1], "vizualizare_joburi") == 0) {
                return todo();
            }
            break;
        case 3:
            if (strcmp(argv[1], "vizualizare_joburi_filtrat") == 0) {
                return todo();
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
    parse_cli(argc, argv);
}
