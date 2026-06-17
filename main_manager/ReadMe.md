# Retea Socializare Jobs - Modul Admin (Manager)

Acest modul reprezinta interfata de administrare a platformei de joburi. Permite gestionarea anunturilor de angajare si vizualizarea candidatilor folosind argumente direct din linia de comanda.

Autor: Cristian Meriacri

Sistem de Operare: CachyOS (Arch Linux)

## Detalii Tehnice

- CLase: Logica impartita in clasele Job, Aplicatie si Manager_interface.
- Gestiunea Memoriei: Utilizare de smart pointers (shared_ptr si weak_ptr) pentru a asigura o relatie sigura de agregare si a preveni memory leaks.
- Persistenta Datelor: Citire si rescriere automata in fisierele joburi.txt si aplicatii.txt folosind fstream.

## Comenzi de Utilizare

Nota: Argumentele care contin spatii trebuie puse obligatoriu intre ghilimele duble ("").

Vizualizare joburi active:
./manager.exe vizualizare_joburi

Adaugare job nou:
```
./manager.exe adaugare_job "<Titlu>" "<Companie>" "<Skill1, Skill2, Skill3>"
```
Daca nu se foloseste virgula in segregarea skill-urilor, toate vor fi puse la un loc impreuna cu delimitatorul

Modificare job (campuri valide: titlu_job sau companie):
```
./manager.exe modificare_job "<Titlu Curent>" "<camp>" "<Valoare Noua>"
```
Adaugare skill la un job:
```
./manager.exe adauga_skill "<Titlu Job>" "<Skill Nou>"
```
Stergere skill de la un job:
```
./manager.exe sterge_skill "<Titlu Job>" "<Skill Vechi>"
```
Stergere job din sistem:

```
./manager.exe stergere_job "<Titlu Job>"
```

Vizualizare candidati pentru un job specific:

```
./manager.exe vizualizare_candidati "<Titlu Job>"
```

## Persistenta datelor:

- joburi.txt detine toate joburile in format titlu_job | companie | skill1,skill2,skill3 ...
- aplicatii.txt detine toate aplicatiile in format titlu_job | companie | nume candidat | mesaj

## Arhitectura si Relatii intre Clase (UML)

```mermaid
classDiagram
    direction TB
    class Manager_interface {
        -vector~Job~ joburi
        -vector~shared_ptr~Aplicatie~~ aplicatii
    }
    class Job {
        -string titlu_job
        -string companie
        -vector~string~ skill_uri
        -vector~weak_ptr~Aplicatie~~ aplicatii
    }
    class Aplicatie {
        -string nume_candidat
        -string mesaj_aplicare
    }

    Manager_interface *-- Job : Gestioneaza
    Manager_interface *-- Aplicatie : Detine (shared_ptr)
    Job o-- Aplicatie : Observa (weak_ptr)