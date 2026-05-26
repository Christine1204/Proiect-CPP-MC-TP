#include <cstring>
#include <iostream>
#include <memory>

#include "../src_clase/Candidat.h"

void todo() {
    std::cerr << "Functionalitate neimplementata";
    exit(1);
}

void eroare(const char * str) {
    std::cerr << str;
    exit(1);
}

void parse_cli(int argc, char* argv[]) {
    switch (argc) {
        case 1:
            if (strcmp(argv[1], "vizualizare_joburi") == 0) {
                return todo();
            }
            break;
        case 2:
            if (strcmp(argv[1], "vizualizare_joburi_filtrat") == 0) {
                return todo();
            } if (strcmp(argv[1], "vizualizare_aplicatii_proprii") == 0) {
                return todo();
            }
            break;
        case 3:
            if (strcmp(argv[1], "retragere_aplicatie") == 0) {
                return todo();
            }
            break;
        case 4:
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
