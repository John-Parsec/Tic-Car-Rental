#include "CarRental.hpp"

#include<iostream>
#include<string>

Date::Date(){
    std::string d, m, a, str, strm;
    int id, im, ia;
    
    for(bool valido = 0; valido == 0;)
    {
        valido = 1;

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

        if(!valido){
            cout << "Essa data e invalida. ";
        }
    }

    this->dia = id;
    this->mes = im;
    this->ano = ia;
}
