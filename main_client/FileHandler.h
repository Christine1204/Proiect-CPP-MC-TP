//
// Created by tudor on 5/26/2026.
//

#include "../shared/classes/Aplicatie.h"
#include "../shared/classes/Job.h"
#include "../shared/classes/Candidat.h"
#include "Util.h"

#ifndef CLIENT_FILEHANDLER_H
#define CLIENT_FILEHANDLER_H

inline auto FILE_SEPARATOR = "|";

inline auto JOBS_FILE_PATH = "shared/files/joburi.txt";
inline auto APPLICATIONS_FILE_PATH = "shared/files/aplicatii.txt";

std::vector<std::shared_ptr<Job>> load_jobs_from_file();
void save_applications_to_file(const std::vector<std::shared_ptr<Candidat>>& candidati, const std::vector<std::shared_ptr<Job>>& joburi);

// Initialises candidati and binds applications to them and to joburi
void load_applications_from_file(std::vector<std::shared_ptr<Candidat>>& candidati, const std::vector<std::shared_ptr<Job>>& joburi);

#endif //CLIENT_FILEHANDLER_H
