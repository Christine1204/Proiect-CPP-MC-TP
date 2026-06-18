#include "Manager_interface.h"
#include "Utils.h" //un header cu functii auxiliare folositoare, la scrierea acestui comentariu e doar functia split
#include <vector>
#include <string>
#include <iostream>



Manager_interface::Manager_interface(){
    jobs_file.open("shared/files/joburi.txt", std::ios::in | std::ios::out);
    aplicatii_file.open("shared/files/aplicatii.txt", std::ios::in | std::ios::out); //deschide fisierele txt

    if (!jobs_file.is_open()) {
        std::cerr << "Eroare: nu s-a putut deschide joburi.txt,constructor, asigura-te ca fisierul exista\n";
    }
    if (!aplicatii_file.is_open()) {
        std::cerr << "Eroare: nu s-a putut deschide aplicatii.txt,constructor, asigura-te ca fisierul exista\n";
    } //daca nuse pot deschide, da erori 

    //foloseste functia de incarcat joburi pentru a popula array-ul de joburi a  clasei
    incarca_joburi(); 
    incarca_aplicatii(); //la fel pentru aplicatii,aici se face si link-ul dintre joburi si aplicatii
}




Manager_interface::~Manager_interface(){
        if(jobs_file.is_open()){ //check pentru a vedea daca e deschis sau nu
            jobs_file.close(); //inchidem fisierul la final, pentru a salva modificarile
        }
        if(aplicatii_file.is_open()){
            aplicatii_file.close();
        }
}


void Manager_interface::salveaza(){

    
    jobs_file.close(); // inchidem ultima sesiune de fisier pentru a putea deschide in mod de out si trunc, pentru a rescrie tot
    jobs_file.open("shared/files/joburi.txt", std::ios::out | std::ios::trunc); //deschidem cu out si trunc, ceea ce sterge tot continutul din fisier
    
    if (!jobs_file.is_open()){
        std::cerr << "Eroare: nu s-a putut deschide joburi.txt pentru salvare,functia salveaza\n";
        return; // daca nu sa putut deschide,iesi din functie, afisand un mesaj de eroare
    }

    for (const auto& job : joburi){ //mergem prin fiecare job din vectorul de joburi a managerului
        jobs_file << job.get_titlu_job() << " | " << job.get_companie() << " | "; //folosim operatorul de scriere pentru fisier pentru a scrie in jobs_file contentul job si companie
        const auto& skill_uri = job.get_skill_uri(); //luam skillurile jobului folosind getterul, care returneaza un vector de stringuri, pe care il stocam intr-o variabila locala pentru a-l putea itera
        for (size_t i = 0; i < skill_uri.size(); i++) { 
            jobs_file << skill_uri[i];
            if (i < skill_uri.size() - 1) {
                jobs_file << ", ";//daca e ultimul skill,nu pune virgula
            }
        }
        jobs_file << "\n"; //newline
    } 
}

void Manager_interface::modificare_job_comanda(std::string titlu_job, std::string camp, std::string valoare){
    for (auto& job : joburi){ //mergem prin fiecare job din vectorul de joburi a managerului
        if (job.get_titlu_job() == titlu_job){ //daca gasim jobul cu titlul respectiv, atunci modificam campul respectiv cu valoarea noua
            if (camp == "companie"){
                job.set_companie(valoare); // Surgical change
                salveaza(); 
                std::cout << "Campul companie a fost modificat!\n";
                return;
            }
            else if (camp == "titlu_job"){
                job.set_titlu_job(valoare); // Surgical change
                salveaza(); 
                std::cout << "Campul titlu_job a fost modificat!\n";
                return;
            }
            else {
                std::cerr << "Campul " << camp << " nu este valid pentru modificare,\n";
                std::cerr << "Campurile valide sunt: companie, titlu_job,\nDaca doriti sa modificati skillurile, folositi comenzile adauga_skill_comanda sau sterge_skill_comanda\n";
                return; //daca campul nu e valid, iesim din functie, afisand un mesaj de eroare
            }
        }
    }
}

void Manager_interface::vizualizare_joburi_comanda(){
    if (joburi.empty()){
        std::cout << "Nu exista joburi disponibile.E saracie in Romania :(\n";
        return; //daca nu exista joburi, iesim din functie, afisand un mesaj informativ
    }
    for (const auto& job : joburi){
        std::cout << job; //folosim overload-ul de operator de printare pentru a afisa joburile intr-un format frumos
    }
}


void Manager_interface::adaugare_job_comanda(std::string titlu_job, std::string companie, std::vector<std::string> skill_uri){
    Job job(titlu_job,companie,skill_uri);
    joburi.push_back(job); //adaugam jobul nou creat in vectorul de joburi al managerului
    salveaza(); //salvam modificarile in fisier, pentru a pastra persistenta datelor

    std::cout << "Jobul a fost adaugat cu succes!\n";
} 

void Manager_interface::sterge_job_comanda(std::string titlu_job){
    for (auto it = joburi.begin(); it != joburi.end(); ++it){ //folosim un iterator pentru a merge prin vectorul de joburi.
        if (it->get_titlu_job() == titlu_job){ //aparent erase are nevoie de un iterator pentru a sterge elementul,ceea ce mi se parte foarte complicat si 
            //asa de ineficient fata de un limbaj modern :), dar asta e, asa merge in C++
            joburi.erase(it);
            std::cout << "Jobul cu titlul " << titlu_job << " a fost sters cu succes.\n";
            salveaza(); //salvam modificarile in fisier, pentru a pastra persist
            return; //dupa ce am sters jobul, iesim din functie
        }

    }
                std::cerr << "Jobul cu titlul " << titlu_job << " nu a fost gasit.\n";
 //daca am terminat de iterat prin tot vectorul si nu am gasit jobul, inseamna ca nu exista, deci afisam un mesaj de eroare
} // the opps are trying to convert me to oop programming




 void Manager_interface::incarca_joburi(){
    if (!jobs_file.is_open()){
        std::cerr << "Eroare: nu s-a putut deschide joburi.txt pentru incarcare in incarca_joburi(), asigura-te ca fisierul exista\n";
        return; //daca nu se poate deschide fisierul pentru incarcare, iesim din functie, afisand un mesaj de eroare
    }
    std::string linie;
    while (std::getline(jobs_file, linie)){
            if (linie.empty()) continue; //sarim peste liniile goale
        //aici trebuie sa parsez liniile
        //formatul e titlu job | companie | skill1, skill2, skill3, ...
        //voi folosi o functie numita split din headerul Utils (asa se numeste dupa conventie) pentru a sparge linia in parti, folosind ca delimitator " | " pentru a obtine titlu job, companie, si skill-uri, 
        //iar apoi voi folosi din nou split pentru a sparge partea de skill-uri folosind ca delimitator ", "
        std::vector<std::string> parti = split(linie, '|'); //prima impartire dupa '|'
        if (parti.size() != 3){
            std::cerr << "Eroare: format incorect in joburi.txt, linia: " << linie << "\n";
            continue; //daca linia nu are exact 3 parti dupa impartire, inseamna ca formatul e incorect, deci o sarim, afisand un mesaj de eroare
        }
        std::string titlu_job = parti[0];
        std::string companie = parti[1];
        std::vector<std::string> skill_uri = split(parti[2], ','); //a doua impartire dupa ',' pentru a obtine skill-urile individuale        
        
        //acum am toate informatiile necesare pentru a crea un obiect de tip Job, pe care il adaug in vectorul de joburi al managerului
        Job job(titlu_job, companie, skill_uri);
        joburi.push_back(job);
    
    
    }
}

void Manager_interface::incarca_aplicatii(){
    if (!aplicatii_file.is_open()){
        std::cerr << "Eroare: nu sa putut deschide aplicatii.txt pentru incarcare in incarca_aplicatii(), asigura-te ca fisierul exista\n";
        return; //daca nu se poate deschide fisierul pentru incarcare, iesim din functie, afisand un mesaj de eroare
    }
    std::string linie;
    while (std::getline(aplicatii_file, linie)){
        if (linie.empty()) continue; //sarim peste liniile goale
        //aici trebuie sa parsez liniile
        //formatul e titlu job | companie | nume candidat | mesaj aplicatie
        //voi folosi functia split pentru a sparge linia in parti, folosind ca delimitator " | " pentru a obtine titlu job, companie, nume candidat, si mesaj aplicatie
        std::vector<std::string> parti = split(linie,'|');
        if (parti.size() != 4){
            std::cerr << "Eroare: format incorect in aplicatii.txt, linia: " << linie << "\n";
            continue; //daca linia nu are exact 4 parti dupa impartire, inseamna ca formatul e incorect, deci o sarim, afisand un mesaj de eroare
        }
        std::string titlu_job = parti[0];
        std::string companie = parti[1];
        std::string nume_candidat = parti[2];
        std::string mesaj_aplicare = parti[3];



        auto app = std::make_shared<Aplicatie>(nume_candidat, mesaj_aplicare); //facem un obiect aplicatie 
        aplicatii.push_back(app);  // managerul il tine in viata



        bool gasit = false;
        for (auto& job : joburi){
            if (job.get_titlu_job() == titlu_job && job.get_companie() == companie){
                job.link_aplicatie(app); // acelasi pointer, nu o copie
                gasit = true;
                break;
            }
        }        
        if (!gasit){
            std::cerr << "Eroare: jobul cu titlul " << titlu_job << " si compania " << companie << " nu a fost gasit pentru a lega aplicatia, linia: " << linie << "\n";
        } //daca dupa ce am iterat prin toate joburile nu am gasit jobul cu titlul si compania respectiva, inseamna ca aplicatia nu poate fi legata de niciun job, deci afisam un mesaj de eroare
    }
}


void Manager_interface::vizualizare_candidati_comanda(std::string titlu_job){

    //codul de mai jos e tot copy paste din functia de loading la fisier
    if (!aplicatii_file.is_open()){
        std::cerr << "Eroare: nu sa putut deschide aplicatii.txt pentru incarcare in incarca_aplicatii(), asigura-te ca fisierul exista\n";
        return; //daca nu se poate deschide fisierul pentru incarcare, iesim din functie, afisand un mesaj de eroare
    }


    aplicatii_file.clear(); // sterge eofbit si orice alt flag de eroare
    aplicatii_file.seekg(0); //aceasta functie pune pointerul de text inapoi la inceputul fisierului
    bool gasit = false;
    std::string linie;
        while (std::getline(aplicatii_file, linie)){
        if (linie.empty()) continue; //sarim peste liniile goale
        //aici trebuie sa parsez liniile
        //formatul e titlu job | companie | nume candidat | mesaj aplicatie
        //voi folosi functia split pentru a sparge linia in parti, folosind ca delimitator " | " pentru a obtine titlu job, companie, nume candidat, si mesaj aplicatie
        std::vector<std::string> parti = split(linie,'|');
        if (parti.size() != 4){
            std::cerr << "Eroare: format incorect in aplicatii.txt, linia: " << linie << "\n";
            continue; //daca linia nu are exact 4 parti dupa impartire, inseamna ca formatul e incorect, deci o sarim, afisand un mesaj de eroare
        }

        std::string companie = parti[1];
        std::string nume_candidat = parti[2];
        std::string mesaj_aplicare = parti[3];


        //std::cout << "DEBUG: '" << parti[0] << "' == '" << titlu_job << "' ?\n";


        if (parti[0] == titlu_job){  // comparam cu parametrul functiei
            std::cout << parti[2] << " | " << parti[3] << "\n"; //printam doar numele si mesajul
            gasit = true;
        }
    }
    if (!gasit){
        std::cerr << "Nu s-au gasit aplicatii pentru job-ul respectiv\n";
    }
}


void Manager_interface::adauga_skill_comanda(std::string titlu_job, std::string skill_nou){
    for (auto& job : joburi){
        if (job.get_titlu_job() == titlu_job){
            std::vector<std::string> skill_uri = job.get_skill_uri();
            skill_uri.push_back(skill_nou); //adaugam skill-ul nou la vectorul de skill-uri al jobului
            job.set_skill_uri(skill_uri); // folosin set-errul pentru a actualiza skill-urile obiectului de job direct
            salveaza(); 
            std::cout << "Skill-ul a fost adaugat cu succes!\n";
            return;
        }
    }
    std::cerr << "Jobul cu titlul " << titlu_job << " nu a fost gasit.\n";
}

//observ ca folosesc destul de mult cautarea unui job in vector,intro lume ideala as face o functie de cautare

void Manager_interface::sterge_skill_comanda(std::string titlu_job, std::string skill_de_sters){
    for (auto& job : joburi){
        if (job.get_titlu_job() == titlu_job){
            std::vector<std::string> skill_uri = job.get_skill_uri();
            for (auto it = skill_uri.begin(); it != skill_uri.end(); ++it){
                if (*it == skill_de_sters){// din nou folosim un iterator pentru ca erase are nevoie de el
                    skill_uri.erase(it); //stergem skill-ul folosing iteratorul din obiectul local
                    job.set_skill_uri(skill_uri); //actualizam skill-urile obiectului de job folosind set-errul
                    salveaza();
                    std::cout << "Skill-ul a fost sters cu succes!\n";
                    return; //dupa ce am sters skill-ul, iesim din functie,deoarece daca lasam sa mai itereze, am putea da de un segmentation fault
                }
            }
            std::cerr << "Skill-ul '" << skill_de_sters << "' nu a fost gasit pentru acest job.\n";
            return;

        }

    }
    std::cerr << "Jobul cu titlul " << titlu_job << " nu a fost gasit.\n";
}