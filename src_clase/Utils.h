//aparent acest fisier nu trebuie inclus in cmake
#pragma once
// 
//Created by Christine on 6/06/2026.
//

//titlu_job | companie | skill1, skill2, skill3, ...

#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> split(const std::string& str, const char& delimiter){
    std::vector<std::string> tokenuri;
    std::string token;
    std::stringstream ss(str);
    
    while (std::getline(ss, token, delimiter)){ //cat timp mai avem ce citi
        
        // cat timp stringul nu e gol si primul caracter e spatiu, sterge, ca sa scapam de spatiile in plus
        while (token.length() > 0 && token[0] == ' ') {
            token.erase(0, 1); // sterge 1 caracter de la pozitia 0,adica primul caracter
        }
        
        // cat timp string-ul nu e gol si ultimul caracter e spatiu, sterge
        while (token.length() > 0 && token[token.length() - 1] == ' ') {
            token.erase(token.length() - 1, 1); // sterge 1 caracter de la final
        } //apoi dupa ce sterge ultimul caracter,cand verifica din nou ca si cum ar itera in spate
        
        tokenuri.push_back(token);
    }
    return tokenuri;
} //aceasta functie ia un string lung si un caracter delimitator si returneaza un vector de stringuri care sunt partile din care e format acel string lung original
