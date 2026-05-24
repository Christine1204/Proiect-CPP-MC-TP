//
// Created by Christine on 5/20/2026.
//
#ifndef PROIECT_C_JOB_H
#define PROIECT_C_JOB_H
#include <memory>
#include <vector>
#include <string>



#include "Aplicatie.h"

class Job{

    std::string titlu_job;
    std::string companie;
    std::vector<std::string> skill_uri;
    std::vector<std::weak_ptr<Aplicatie>> aplicatii; //pointer weak care va fi dealocat cand vectoruld e aplicatii va disparea

public:
    Job() = default; //constructor gol default

    Job(const std::string& titlu_job,const  std::string& companie,const std::vector<std::string>& skill_uri)
    {
        this->titlu_job = titlu_job;
        this->companie = companie;
        this->skill_uri = skill_uri;
    } //full featured constructor
    // partea cu aplicatii va veni de la shared pointer, la moment ramane goala
    ~Job() = default;

    void link_aplicatie(const std::shared_ptr<Aplicatie> app_existenta) {
        aplicatii.push_back(app_existenta);
    }

    std::string get_titlu_job()
    {
        return titlu_job;
    }
    std::string get_companie()
    {
        return companie;
    }
    std::vector<std::string> get_skill_uri()
    {
        return skill_uri;
    }
    std::vector<std::weak_ptr<Aplicatie>> get_aplicatie()
    {
        return aplicatii;
    } //get-erre
};




#endif //PROIECT_C_JOB_H