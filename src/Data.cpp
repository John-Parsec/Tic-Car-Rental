#include "CarRental.hpp"

#include<iostream>
#include<string>

int main()
{
    std::string d, m, a, str, strm;
    int id, im, ia;
    bool valido = 1;

    std::cout << "Digite uma data no formato dd/mm/aaaa: ";
    std::cin >> str;
    str = str;

    d = str.substr(0, 2);
    m = str.substr(3, 2);
    a = str.substr(6, 4);

    id = stoi(d);
    im = stoi(m);
    ia = stoi(a);

    if(im < 1 || im > 12 || id < 1 || id > 31)
        valido = 0;

    if(valido && (im == 4 || im == 6 || im == 9 || im == 11) && id > 30)
        valido = 0;

    if(valido && im == 2)
    {
        if (ia % 4 == 0 && id > 29)
            valido = 0;
        else if (ia % 4 !=0 && id > 28)
            valido = 0;
    }

    std::cout << (valido ? "E uma data valida" : "E uma data invalida") << std::endl;

    strm = (im == 1 ? "Janeiro" : strm);
    strm = (im == 2 ? "Favereiro" : strm);
    strm = (im == 3 ? "Março" : strm);
    strm = (im == 4 ? "Abril" : strm);
    strm = (im == 5 ? "Maio" : strm);
    strm = (im == 6 ? "Junho" : strm);
    strm = (im == 7 ? "Julho" : strm);
    strm = (im == 8 ? "Agosto" : strm);
    strm = (im == 9 ? "Setembro" : strm);
    strm = (im == 10 ? "Outubro" : strm);
    strm = (im == 11 ? "Novembro" : strm);
    strm = (im == 12 ? "Dezembro" : strm);

    if(valido)
        std::cout << im << " de " << strm << " de " << ia << std::endl; 

    return 0;
}