//
// Created by Christine on 5/20/2026.
//

//nu prea am metode de pus aici pentru ca job e o structura prea simpla si logica o sa o pun in clasa de manager

#include "Job.h"


//overload la operator de printare
std::ostream &operator<<(std::ostream &out, const Job &j) {

    out << "[ " << j.titlu_job << " ] la " << j.companie << " | Skill-uri: ";
    
        //printare de skilluri, cu -1 pentru a nu pune virgula dupa ultimul skill
    for (size_t i = 0; i < j.skill_uri.size(); ++i) {
        out << j.skill_uri[i];
        if (i < j.skill_uri.size() - 1) {
            out << ", ";
        }
    }
    
    //un print de newline sa fie mai usor de citit cand afisez mai multe joburi
    out << "\n";
    
    return out;
} 