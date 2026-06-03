//
// Created by Christine on 5/20/2026.
//
#ifndef PROIECT_C_JOB_H
#define PROIECT_C_JOB_H
#include <memory>
#include <vector>
#include <string>
#include <iostream>

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
    } //aici link-uiesc pe joc cu aplicatia, adica adaug un pointer weak la vectorul de aplicatii
    //shared-pointer-ul va fi creat in main si e automat convertit in weak pointer cand e adaugat in vectorul de aplicatii, deci nu trebuie sa ma ocup de asta

/////////////////////////////////////////////////////////////////////////////////
//GETTERE

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

    ///////////////////////////////////////////////////////////////////////////

    std::vector<std::weak_ptr<Aplicatie>> get_aplicatie()
    {
        return aplicatii;
    } //get-err mai speecial pentru ca returneaza un vector de pointeri weak, dar e necesar pentru a putea accesa aplicatiile legate de job

        //overload la operator de printare
        friend std::ostream &operator<<(std::ostream &out, const Job &j);

};









#endif //PROIECT_C_JOB_H