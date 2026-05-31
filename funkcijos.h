#pragma once

#include <filesystem>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
#include <set>

std::string sutvarkytiURL(std::string& zodis){
    const std::string skyryba = "()[]{}<>\"'.,;:!?";
    std::size_t a = zodis.find_first_not_of(skyryba);
    if (a == std::string::npos) return "";
    std::size_t b = zodis.find_last_not_of(skyryba);
    return zodis.substr(a, b - a + 1);
}

std::string sutvarkytZodi(std::string& zodis){
    std::string rezultatas;

    for (unsigned char c : zodis)
    {
        if (std::ispunct(c) || std::isdigit(c))
            continue;

        if (c <= 127)
            rezultatas += std::tolower(c);

        else
            rezultatas += c;
    }

    return rezultatas;
}

void suskaiciuotiZodzius(std::string input){
    std::map<std::string, int> sarasas;
    
    std::ifstream in(input);

    std::string zodis;
    while(in >> zodis){
        zodis = sutvarkytZodi(zodis);
        if(!zodis.empty()){
            //std::cout << test << "\n";
            sarasas[zodis] += 1;
        }
    }
    in.close();

    std::ofstream out(std::filesystem::path(input).stem().string() + "_zodziu_skaicius.txt");

    for(auto narys : sarasas){
        if(narys.second > 1)
            out << narys.first << ": " << narys.second << "\n";
    }
    out.close();
    return;
}

void crossReferenceLentele(std::string input){
    std::map<std::string, std::set<int>> sarasas;

    std::ifstream in(input);

    std::string eilute;
    int eilNr = 0;

    while (std::getline(in, eilute)) {
        eilNr++;

        std::stringstream ss(eilute);
        std::string zodis;

        while (ss >> zodis) {
            zodis = sutvarkytZodi(zodis);

            if (!zodis.empty()) {
                sarasas[zodis].insert(eilNr);
            }
        }
    }

    in.close();

    std::ofstream out(std::filesystem::path(input).stem().string() + "_cross_ref.txt");
    
    for(auto narys : sarasas){
        if(narys.second.size() > 1){
            out << narys.first << " -> ";
            for(auto eil : narys.second) 
                out << eil << " ";
            out << '\n';
        }
    }

    return;
}

void rastiURL(std::string input){
    std::set<std::string> sarasas;
    std::regex pattern("^(https?:\\/\\/|www\\.|([A-Za-z0-9-]+\\.)+[A-Za-z]{2,})");

    std::ifstream in(input);

    std::string zodis;
    while(in >> zodis){
        zodis = sutvarkytiURL(zodis);
        if(!zodis.empty() && regex_search(zodis, pattern)){
            sarasas.insert(zodis);
        }
    }
    in.close();

    std::ofstream out(std::filesystem::path(input).stem().string() + "_urls.txt");

    if(sarasas.empty()){
        out << "Nera URLS\n";
        return;
    }

    for(std::string url : sarasas){
        out << url << "\n";
    }

    return;
}
