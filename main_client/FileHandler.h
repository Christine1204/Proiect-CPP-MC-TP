//
// Created by tudor on 5/26/2026.
//

#include "../src_clase/Aplicatie.h"
#include "../src_clase/Job.h"
#include "../src_clase/Candidat.h"
#include "Util.h"

#ifndef CLIENT_FILEHANDLER_H
#define CLIENT_FILEHANDLER_H

inline auto FILE_SEPARATOR = "|";

std::vector<std::shared_ptr<Job>> load_jobs_from_file();
void save_applications_to_file();

// Initialises candidati and binds applications to them and to joburi
void load_applications_from_file(std::vector<std::shared_ptr<Candidat>>& candidati, const std::vector<std::shared_ptr<Job>>& joburi);

#endif //CLIENT_FILEHANDLER_H
