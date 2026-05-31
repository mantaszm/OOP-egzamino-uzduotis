#include "funkcijos.h"


int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    std::cout << "Pasirinti funkcija:\n" 
              << "1 - Suskaiciuoti pasikartojima\n"
              << "2 - Cross-reference lentele\n"
              << "3 - URL suradimas\n"
              << "4 - Visos funkcijos\n";

    char pasirinkimas;
    std::cin >> pasirinkimas;
    
    std::string in("text.txt"), out("output.txt");
    
    std::cout << "Ivesties failas:\n";
    //std::cin >> in;

    std::cout << "Isvesties failas:\n";
    //std::cin >> out;

    switch (pasirinkimas)
    {
    case '1':
        suskaiciuotiZodzius(in);
        return 0;

    case '2':
        crossReferenceLentele(in);
        return 0;

    case '3':
        rastiURL(in);
        return 0;
    case '4':
        suskaiciuotiZodzius(in);
        crossReferenceLentele(in);
        rastiURL(in);
        return 0;
    
    default:
        std::cout << "Blogas pasirinkimas!";
        return 0;
    }
}
