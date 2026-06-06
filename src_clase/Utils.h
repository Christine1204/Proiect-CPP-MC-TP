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
    while (std::getline(ss, token, delimiter)){
        tokenuri.push_back(token);
    }
    return tokenuri;
} //aceasta functie ia un string lung si un caracter delimitator si returneaza un vector de stringuri care sunt partile din care e format acel string lung original
