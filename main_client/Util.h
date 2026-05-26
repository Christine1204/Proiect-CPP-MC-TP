//
// Created by tudor on 5/26/2026.
//

#ifndef CLIENT_UTIL_H
#define CLIENT_UTIL_H
#include <cassert>
#include <cstring>
#include <iostream>
#include <memory>

#include "../src_clase/Candidat.h"
#include "../src_clase/Job.h"

// Return pointer to matching object, otherwise returns empty pointer std::weak_ptr<T>()
std::weak_ptr<Candidat> find_candidat_by_name(const std::vector<std::shared_ptr<Candidat>>& candidati, const std::string& name);
std::weak_ptr<Job> find_job_by_name(const std::vector<std::shared_ptr<Job>>& joburi, const std::string& name);

void todo();

void eroare(const char * str);

#endif //CLIENT_UTIL_H
